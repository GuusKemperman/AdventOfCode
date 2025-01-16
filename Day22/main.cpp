#include "input.h"
#include <format>
#include <unordered_map>
#include "../external/utilities/hash.h"

constexpr size_t single_step(size_t hash)
{
	hash = (hash ^ (hash * 64ull)) % 16777216ull;
	hash = (hash ^ (hash / 32ull)) % 16777216ull;
	hash = (hash ^ (hash * 2048ull)) % 16777216ull;
	return hash;
}

struct gain
{
	size_t num_bananas{};
	size_t updated_most_recently_at_original_num{ std::numeric_limits<size_t>::max() };
};

using sequence = std::array<std::int64_t, 4>;

template<>
struct std::hash<sequence>
{
	size_t operator()(const sequence& seq) const
	{
		size_t hash = 0x1235869;

		for (auto& num : seq)
		{
			hash = utils::multi_hash(hash, num);
		}

		return hash;
	}
};

size_t get_best_sequence(size_t steps)
{
	std::unordered_map<sequence, gain> data_base{};

	sequence curr_sequence;
	std::fill(curr_sequence.begin(), curr_sequence.end(), std::numeric_limits<std::int64_t>::max());

	for (size_t initial_num : get_input())
	{
		size_t num = initial_num;
		for (size_t step = 0; step < steps; step++)
		{
			size_t next_num = single_step(num);
			size_t num_bananas = num % 10ull;
			size_t next_num_bananas = next_num % 10ull;
			std::int64_t diff = static_cast<std::int64_t>(next_num_bananas) - static_cast<std::int64_t>(num_bananas);

			num = next_num;

			for (int i = 1; i < curr_sequence.size(); i++)
			{
				curr_sequence[i - 1] = curr_sequence[i];
			}
			curr_sequence.back() = diff;

			auto it = data_base.find(curr_sequence);

			if (it != data_base.end())
			{
				if (it->second.updated_most_recently_at_original_num == initial_num)
				{
					continue;
				}
				it->second.updated_most_recently_at_original_num = initial_num;
				it->second.num_bananas += next_num_bananas;
			
				continue;
			}

			data_base.emplace(curr_sequence, gain{ next_num_bananas, step });
		}
	}

	auto best_sequence = std::max_element(data_base.begin(), data_base.end(),
		[](const auto& lhs, const auto& rhs)
		{
			return lhs.second.num_bananas < rhs.second.num_bananas;
		});

	return best_sequence->second.num_bananas;
}

int main()
{
	puts(std::format("{}\n", get_best_sequence(2000ull)).c_str());
}

// Just iterate over the offers and find the best sequence
