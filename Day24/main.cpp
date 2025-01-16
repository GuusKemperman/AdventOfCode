#include "input.h"
#include <unordered_map>
#include <cassert>
#include <format>
#include <algorithm>
#include <iostream>
#include <bitset>
#include "../external/utilities/algorithm/memoizer.h"
#include <numeric>
#include <random>
#include <execution>

static std::default_random_engine engine{};

size_t better_rand()
{
	static_assert(std::is_same_v<decltype(engine()), std::uint32_t>);
	size_t num = (static_cast<size_t>(engine()) << 32ull) + static_cast<size_t>(engine());
	return num;
}

union id
{
	std::uint32_t num{};
	struct
	{
		std::uint16_t category{};
		std::uint16_t bit_num{};
	} reg;

	std::array<char, 4> string;
};

template<>
struct std::hash<id>
{
	size_t operator()(const id& id) const
	{
		return id.num;
	}
};

bool operator==(const id& lhs, const id& rhs)
{
	return lhs.num == rhs.num;
}

id string_to_id(std::string_view str)
{
	id id{};
	assert(str.size() <= 4);
	memcpy(&id, str.data(), str.size());
	return id;
}

std::string id_to_string(id id)
{
	return { reinterpret_cast<const char*>(&id) };
}

std::pair<char, std::uint8_t> id_to_category_and_bit(id id)
{
	std::uint8_t left_digit = (id.string[1] - '0') * 10;
	std::uint8_t right_digit = id.string[2] - '0';
	return { id.string[0], left_digit + right_digit};
}

id category_and_bit_to_id(std::pair<char, std::uint8_t> cat_and_bit)
{
	id id{};
	id.string[0] = cat_and_bit.first;
	id.string[1] = cat_and_bit.second / 10 + '0';
	id.string[2] = cat_and_bit.second % 10 + '0';
	return id;
}

enum class operation : std::uint8_t
{
	XOR, OR, AND
};

struct node
{
	id out{};
	id lhs{};
	id rhs{};
	std::uint8_t was_calculated : 1{};
	std::uint8_t result : 1{};
	operation op : 2{};
};

bool operator==(const node& lhs, const id& rhs)
{
	return lhs.out == rhs;
}

auto get_nodes()
{
	static std::unordered_map<id, node> nodes = []()
	{
		std::unordered_map<id, node> nodes{};
		for (auto [name, state] : get_initial_states())
		{
			node& node = nodes[string_to_id(name)];
			node.was_calculated = true;
			node.result = state;
			node.out = string_to_id(name);
		}

		auto program = get_program();
		for (int i = 0; i < program.size(); i += 12)
		{
			std::string_view lhs{ &program[i], 3 };
			std::string_view op{ &program[i + 3], 3 };
			std::string_view rhs{ &program[i + 6], 3 };
			std::string_view out{ &program[i + 9], 3 };

			node& node = nodes[string_to_id(out)];
			node.out = string_to_id(out);
			node.lhs = string_to_id(lhs);
			node.rhs = string_to_id(rhs);

			if (op == "OR ")
			{
				node.op = operation::OR;
			}
			else if (op == "XOR")
			{
				node.op = operation::XOR;
			}
			else if (op == "AND")
			{
				node.op = operation::AND;
			}
			else
			{
				assert(false);
			}
		}
		return nodes;
	}();

	return nodes;
}

auto get_program_result(const auto& completed_program)
{
	size_t result{};

	for (std::uint8_t i = 0; i < 100; i++)
	{
		auto it = completed_program.find(category_and_bit_to_id({ 'z', i }));

		if (it == completed_program.end())
		{
			break;
		}

		result |= static_cast<size_t>(it->second.result) << i;
	}

	return result;
}

#ifdef EXAMPLE
constexpr int num_bits_in_output = 6;
constexpr int num_bits_in_input = 6;
static constexpr size_t num_genes = 4;
#else
static constexpr size_t num_genes = 8;
constexpr int num_bits_in_output = 46;
constexpr int num_bits_in_input = num_bits_in_output - 1;
#endif

using input = std::bitset<num_bits_in_input>;
using output = std::bitset<num_bits_in_output>;

output run_program(auto& nodes, input x, input y)
{
	auto set_input = [&](input input, char reg)
		{
			for (int i = 0; i < input.size(); i++)
			{
				id id = category_and_bit_to_id({ reg, i });
				node& node = nodes.at(id);
				node.result = input[i];
				node.was_calculated = true;
			}
		};
	set_input(x, 'x');
	set_input(y, 'y');

	bool any_not_calculated;
	bool any_calculated;
	do
	{
		any_not_calculated = false;
		any_calculated = false;
		for (auto& [curr_id, curr_node] : nodes)
		{
			if (curr_node.was_calculated)
			{
				continue;
			}

			const node& lhs = nodes.at(curr_node.lhs);

			if (!lhs.was_calculated)
			{
				any_not_calculated = true;
				continue;
			}

			const node& rhs = nodes.at(curr_node.rhs);

			if (!rhs.was_calculated)
			{
				any_not_calculated = true;
				continue;
			}

			switch (curr_node.op)
			{
			case operation::XOR:
			{
				curr_node.result = lhs.result != rhs.result;
				break;
			}
			case operation::OR:
			{
				curr_node.result = lhs.result || rhs.result;
				break;
			}
			case operation::AND:
			{
				curr_node.result = lhs.result && rhs.result;
				break;
			}
			}

			any_calculated = true;
			curr_node.was_calculated = true;
		}
	} while (any_not_calculated && any_calculated);

	size_t return_value = get_program_result(nodes);
	return return_value;
}

void reset_program(auto& program)
{
	for (auto& [curr_id, curr_node] : program)
	{
		curr_node.was_calculated = false;
	}
}

using gene = id;
using genes = std::array<gene, num_genes>;

template<>
struct std::hash<genes>
{
	size_t operator()(const genes& genes)
	{
		size_t hash = 0xbadc0ffee;

		for (const gene& gene : genes)
		{
			hash = utils::multi_hash(hash, gene);
		}

		return hash;
	}
};

struct creature
{
	genes genes{};
	float score{};
};

bool operator<(const creature& lhs, const creature& rhs)
{
	return lhs.score > rhs.score;
}

constexpr int num_to_try = 25;
constexpr int population_size = 1'000;
constexpr float mutation_chance = 0.05f;
constexpr float cross_over_chance_keep_gene_intact = 0.1f;
constexpr float cross_over_chance_split_gene = 0.025f;
constexpr int elitism = 50;

gene get_random_gene()
{
	static std::vector<node> nodes = [&]()
		{
			std::vector<node> nodes{};

			for (const auto& [id, node] : get_nodes())
			{
				nodes.emplace_back(node);
			}
			auto nodes_sorter = [](const node& lhs, const node& rhs)
				{
					return std::string_view{ lhs.out.string.data(), 4 } > std::string_view{ rhs.out.string.data(), 4 };
				};
			std::sort(nodes.begin(), nodes.end(), nodes_sorter);
			return nodes;
		}();

	return nodes[better_rand() % nodes.size()].out;
}

bool are_genes_valid(genes genes)
{
	for (int i = 0; i < genes.size(); i++)
	{
		for (int j = i + 1; j < genes.size(); j++)
		{
			if (genes[i] == genes[j])
			{
				return false;
			}
		}
	}

	for (int i = 0; i < genes.size(); i += 2)
	{
		gene gene1 = genes[i];
		gene gene2 = genes[i + 1];

		bool is_input1 = gene1.string[0] == 'x' || gene1.string[0] == 'y';
		bool is_input2 = gene2.string[0] == 'x' || gene2.string[0] == 'y';

		if (is_input1 != is_input2)
		{
			return false;
		}
	}
	return true;
}

float score_genes(genes genes)
{
	assert(are_genes_valid(genes));

	auto program = get_nodes();

	for (int i = 0; i < genes.size(); i += 2)
	{
		gene gene1 = genes[i];
		gene gene2 = genes[i + 1];

		auto handle1 = program.extract(gene1);
		auto handle2 = program.extract(gene2);
		
		std::swap(handle1.mapped().out, handle2.mapped().out);
		std::swap(handle1.key(), handle2.key());

		program.insert(std::move(handle1));
		program.insert(std::move(handle2));
	}

	std::atomic<size_t> num_bits_wrong = 0;

	auto random_inputs = []()
		{
			std::array<std::pair<input, input>, num_to_try> inputs{};

			for (auto& [x, y] : inputs)
			{
				x = better_rand();
				y = better_rand();
			}

			return inputs;
		}();

	for (const auto& [x, y] : random_inputs)
	{
#ifdef EXAMPLE
		output expected_result = x.to_ullong() & y.to_ullong();
#else
		output expected_result = x.to_ullong() + y.to_ullong();
#endif
		output actual_result = run_program(program, x, y);
		reset_program(program);

		expected_result ^= actual_result;
		num_bits_wrong += expected_result.count();
	}

	constexpr size_t bits_attempted = num_bits_in_output * num_to_try;
	float percentage_right = static_cast<float>(static_cast<double>(bits_attempted - num_bits_wrong) / static_cast<double>(bits_attempted));
	return powf(percentage_right, 3.0f);
}

bool is_correct_answer(genes genes)
{
	for (gene& gene : genes)
	{
		std::cout << gene.string.data() << ", ";
	}

	assert(are_genes_valid(genes));

	auto program = get_nodes();

	for (int i = 0; i < genes.size(); i += 2)
	{
		gene gene1 = genes[i];
		gene gene2 = genes[i + 1];

		auto handle1 = program.extract(gene1);
		auto handle2 = program.extract(gene2);

		assert(!handle1.empty() && !handle2.empty());

		std::swap(handle1.mapped().out, handle2.mapped().out);
		std::swap(handle1.key(), handle2.key());

		program.insert(std::move(handle1));
		program.insert(std::move(handle2));

		node& node1 = program.at(genes[i]);
		node& node2 = program.at(genes[i + 1]);
	}

	std::atomic<size_t> num_bits_wrong = 0;

	puts("Checking if genes are 100% the answer\n");

	while (true)
	{
		input x = better_rand();
		input y = better_rand();
		auto mut_program = program;

#ifdef EXAMPLE
		output expected_result = x.to_ullong() & y.to_ullong();
#else
		output expected_result = x.to_ullong() + y.to_ullong();
#endif

		output actual_result = run_program(mut_program, x, y);

		expected_result ^= actual_result;

		if (expected_result.count() != 0)
		{
			return false;
		}
	}

	return true;
}

std::string genes_to_string(genes genes)
{
	std::string out{};

	std::sort(genes.begin(), genes.end(),
		[](const gene& lhs, const gene& rhs)
		{
			return std::string_view{ lhs.string.data() } < std::string_view{ rhs.string.data() };
		});

	for (gene& gene : genes)
	{
		out.append(gene.string.data());
		out.append(",");
	}
	return out;
}

void run_genetic_simulation()
{
	std::array<creature, population_size> population{};
	
	for (creature& creature : population)
	{
		for (gene& gene : creature.genes)
		{
			gene = get_random_gene();
		}
	}

	auto random_float = [](float min = 0.0f, float max = 1.0f)
		{
			std::uniform_real_distribution distribution{ min, std::max(min, max) };
			return distribution(engine);
		};

	float prev_high_score{};

	for (int i = 0; true; i++)
	{
		std::for_each(std::execution::par_unseq, population.begin(), population.end(),
			[](creature& creature)
			{
				if (!are_genes_valid(creature.genes))
				{
					creature.score = 0.0f;
					return;
				}

				// Helps with memoization

				std::array<std::pair<gene, gene>, num_genes / 2> swaps{};

				for (int i = 0; i < swaps.size(); i++)
				{
					gene gen1 = creature.genes[i * 2];
					gene gen2 = creature.genes[i * 2 + 1];

					if (gen1.num > gen2.num)
					{
						swaps[i] = { gen1, gen2 };
					}
					else
					{
						swaps[i] = { gen1, gen2 };
					}
				}

				std::sort(swaps.begin(), swaps.end(),
					[](const auto& lhs, const auto& rhs)
					{
						if (lhs.first == rhs.first)
						{
							return lhs.second.num < rhs.second.num;
						}
						return lhs.first.num < rhs.first.num;
					});

				genes sorted_genes;

				for (int i = 0; i < swaps.size(); i++)
				{
					sorted_genes[i * 2] = swaps[i].first;
					sorted_genes[i * 2 + 1] = swaps[i].second;
				}

				creature.score = utils::memoize<score_genes>(sorted_genes);
			});

		float total_score = std::accumulate(population.begin(), population.end(), 0.0f, [](float n, const creature& c) { return n + c.score; });
		std::sort(population.begin(), population.end());

		if (population.front().score > prev_high_score
			|| i % 100 == 0)
		{
			puts(std::format("Gen {}, BestScore: {}, Output: {}\n",
				i,
				population.front().score,
				genes_to_string(population.front().genes)).c_str());
			prev_high_score = std::max(prev_high_score, population.front().score);
		}

		if (population.front().score == 1.0)
		{
			if (is_correct_answer(population.front().genes))
			{
				puts("Answer was correct\n");
				return;
			}
			else
			{
				puts("Failed on larger input sample!\n");
				exit(1);
			}
		}

		auto select_parent_weighted =
			[&]() -> decltype(auto)
			{
				float randomValue = random_float();
				const float randomNum = randomValue * total_score;

				float cumulative{};

				for (size_t i = 0; i < population.size(); i++)
				{
					const float nextCumulative = cumulative + population[i].score;

					if (randomNum >= cumulative
						&& randomNum <= nextCumulative)
					{
						return population[i];
					}

					cumulative = nextCumulative;
				}
				return population[0];
			};

		std::array<creature, population_size> next_population{};

		for (int child_index = 0; child_index < next_population.size(); child_index++)
		{
			creature& child = next_population[child_index];
			child = population[child_index];

			if (random_float() < cross_over_chance_keep_gene_intact)
			{
				int swap1 = static_cast<int>(better_rand() % (child.genes.size() / 2)) * 2;
				int swap2 = static_cast<int>(better_rand() % (child.genes.size() / 2)) * 2;
				std::swap(child.genes[swap1], child.genes[swap2]);
				std::swap(child.genes[swap1 + 1], child.genes[swap2 + 1]);
			}

			if (child_index < elitism)
			{
				continue;
			}

			const creature& mommy = select_parent_weighted();
			const creature& daddy = select_parent_weighted();

			for (int i = 0; i < child.genes.size(); i += 2)
			{
				bool should_go_ask_mom = better_rand() & 1;
				child.genes[i] = (should_go_ask_mom ? mommy : daddy).genes[i];
				child.genes[i + 1] = (should_go_ask_mom ? mommy : daddy).genes[i + 1];
			}

			for (int i = 0; i < child.genes.size(); i++)
			{
				if (random_float() < mutation_chance)
				{
					child.genes[i] = get_random_gene();
				}
			}

			if (random_float() < cross_over_chance_split_gene)
			{
				int swap1 = static_cast<int>(better_rand() % child.genes.size());
				int swap2 = static_cast<int>(better_rand() % child.genes.size());
				std::swap(child.genes[swap1], child.genes[swap2]);
			}
		}
	
		population = next_population;
	}
}

int main()
{
	run_genetic_simulation();
}

// Now this day was hard, but fun. I tried to analyise the input data manually, didn't 
// get very far with it, theres too much data to sift through.
// Automating the analysation was kinda boring, and didn't yield great results.
// I stopped with that quite quickly.

// Instead, I thought I could use a genetic algorithm:
//  - The score of an organism can be calculated by counting the number
//    of correct bits.
//  - The genes (the swaps to make) can be randomly generated, and easily mutated
// 
// I wrote one once in highschool, I used what I remembered to write another one to 
// solve this puzzle. It takes around 30-120 seconds, but it works for any input.
// 
// Multi-threading it was difficult and not very successful, lots of unbalanced jobs.
// Simulating the adder is also quite slow. Memoization helped a lot, no need to test genes twice.
//
// Really annoying issue I ran into: I was converting the bitset to an unsigned long, **but** an
// unsigned long doesn't have enough bits to store the output in! This led to me running the 
// algorithm, after a minute it would spit out a score with 100% success (because half the bits
// weren't being tested), and me being confused about why it wasn't the correct answer. 
// Same problem happened later when i realised rand() returns an int, also not enough bits :(

