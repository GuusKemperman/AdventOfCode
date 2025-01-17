
#include <array>
#include <assert.h>
#include <bitset>
#include <immintrin.h>
#include <thread>
#include <iostream>
#include <mutex>

size_t adv(size_t reg_a, size_t combo)
{
	return reg_a / ((size_t)1 << combo);
}

static_assert(std::numeric_limits<std::int64_t>::max() >= 562949953421311ull);
std::array<std::size_t, 16> program{ 2,4,1,7,7,5,0,3,4,4,1,7,5,5,3,0 };
std::array<__m256i, 16> program_simd = []()
{
	std::array<__m256i, 16> as_simd{};

	for (int i = 0; i < program.size(); i++)
	{
		as_simd[i] = _mm256_set1_epi64x(program[i]);
	}

	return as_simd;

	}();


bool hard_coded_simd(const __m256i* input)
{
	// not sure if this is needed but paranoia
	__m256i a = _mm256_loadu_si256(input);
	__m256i b, c;

	__m256i is_valid = _mm256_setzero_si256();

	// these were used a few times, so 
	// initialise them once.
	__m256i simd1 = _mm256_set1_epi64x(1);
	__m256i simd7 = _mm256_set1_epi64x(7);

	static constexpr int size = sizeof(program) / sizeof(program[0]);
	for (int i = 0; i < size; i++)
	{
		// 2, 4: b = a % 8
		b = _mm256_and_si256(a, simd7); // Efficient modulo with mask for power-of-2

		// 1, 7: b = b ^ 7
		b = _mm256_xor_si256(b, simd7);

		// 7, 5: c = a / (1ull << b)
		__m256i shift = _mm256_sllv_epi64(simd1, b);
		c = _mm256_div_epi64(a, shift);

		// 0, 3: a = a / 8
		a = _mm256_srli_epi64(a, 3);

		// 4, 4: b = b ^ c
		b = _mm256_xor_si256(b, c);

		// 1, 7: b = b ^ 7
		b = _mm256_xor_si256(b, simd7);

		// 5, 5: output = b % 8
		__m256i output = _mm256_and_si256(b, simd7);

		__m256i cmp = _mm256_cmpeq_epi64(output, program_simd[i]);
		is_valid = _mm256_and_si256(is_valid, cmp);
	}

	std::int64_t results[4];
	_mm256_storeu_si256(reinterpret_cast<__m256i*>(results), is_valid);
	return results[0] | results[1] | results[2] | results[3];
}

template<bool print = false>
bool hard_coded(std::int64_t input)
{
	std::int64_t a = input;
	std::int64_t b{};
	std::int64_t c{};

	bool is_valid = true;
	//std::cout << std::format("{} (mod8:{}) (mod3:{}) (div8:{}) = \n", input, input % 8, input % 3, input / 8);
	for (int i = 0; i < program.size(); i++)
	{
		if (!print)
		{
			std::cout << "a = " << std::bitset<64>(a).to_string();

		}

		// 2, 4
		b = a % 8;

		// 1, 7
		b = b ^ 7;

		// 7, 5
		c = a / (1ull << b);

		// 0, 3
		a = a / 8;

		// 4, 4
		b = b ^ c;

		// 1, 7
		b = b ^ 7;

		// 5, 5
		std::int64_t output = b % 8;


		if (print)
		{
			std::cout << output << ", ";
		}
		else
		{
			std::cout << "\no = " << std::bitset<64>(output).to_string() << std::endl;

		}
	}

	std::cout << std::endl;
	return is_valid;
}

size_t single_cycle(size_t input)
{
	size_t a = input;
	size_t b = a % 8;
	b = b ^ 7;
	size_t c = a / (1ull << b);
	a = a / 8;
	b = b ^ c;
	b = b ^ 7;
	return b % 8;
}

size_t get_output_after_cycles(size_t input, size_t cycles)
{
	size_t a = input;
	size_t b;

	for (int i = 0; i < cycles; i++)
	{
		b = a % 8;
		b = b ^ 7;
		size_t c = a / (1ull << b);
		a = a / 8;
		b = b ^ c;
		b = b ^ 7;
	}

	return b % 8;
}

struct CPU
{
	union
	{
		size_t data[3]{ 0, 0, 0 };

		struct
		{
			size_t a;
			size_t b;
			size_t c;
		};
	} registers;

	size_t program_ptr = 0;
	size_t num_outputted{};

	template<bool CountOnly>
	bool run()
	{
		while (program_ptr < program.size())
		{
			size_t instruction = program[program_ptr];
			size_t literal_operand = program[program_ptr + 1];
			size_t combo_operand = literal_operand >= 4 && literal_operand <= 6 ? registers.data[literal_operand - 4] : literal_operand;

			switch (instruction)
			{
			case 0: // ADV
			{
				registers.a = adv(registers.a, combo_operand);
				program_ptr += 2;
				break;
			}
			case 1: // bxl
			{
				registers.b = registers.b ^ literal_operand;
				program_ptr += 2;
				break;
			}
			case 2: // bst
			{
				registers.b = combo_operand % 8;
				program_ptr += 2;
				break;
			}
			case 3: // jnz
			{
				if (registers.a == 0)
				{
					program_ptr += 2;
				}
				else
				{
					program_ptr = literal_operand;
				}
				break;
			}
			case 4: // bxc
			{
				registers.b = registers.b ^ registers.c;
				program_ptr += 2;
				break;
			}
			case 5: // out
			{
				if constexpr (CountOnly)
				{
					num_outputted++;
					program_ptr += 2;
					break;
				}
				else
				{
					size_t printed = combo_operand % 8;

					if (num_outputted >= program.size()
						|| printed != program[num_outputted])
					{
						return false;
					}

					num_outputted++;
					program_ptr += 2;
					break;
				}
			}
			case 6: // bdv
			{
				registers.b = adv(registers.a, combo_operand);
				program_ptr += 2;
				break;
			}
			case 7: // cdv
			{
				registers.c = adv(registers.a, combo_operand);
				program_ptr += 2;
				break;
			}
			}
		}

		return num_outputted == program.size();
	}
};

int main()
{
	const auto recurse_find = [](auto& self, size_t total_input, size_t program_index) -> size_t
		{
			if (program_index == program.size())
			{
				return total_input;
			}

			for (size_t i = 0; i < 8; i++)
			{
				size_t input = (i << ((program_index) * 3ull)) | total_input;

				if (get_output_after_cycles(input, program_index + 1) == program[program_index])
				{
					size_t child_input = self(self, input, program_index + 1);
					if (child_input != 0)
					{
						return child_input;
					}
				}
			}

			return 0;
		};

	for (size_t i = 0; i < 8; i++)
	{
		size_t total_input = recurse_find(recurse_find, i, 0);
		hard_coded<true>(total_input);
	}

	// old bruteforcing approach
#if 0

	size_t min_range = 0;
	size_t max_range = std::numeric_limits<size_t>::max();
	size_t first_with_correct_length = std::numeric_limits<size_t>::max();
	size_t last_with_correct_length = std::numeric_limits<size_t>::max();

	while (min_range < max_range)
	{
		size_t middle = (min_range + max_range) / 2;

		CPU cpu{};
		cpu.registers.a = middle;

		cpu.run<true>();

		if (cpu.num_outputted < program.size())
		{
			min_range = middle + 1;
		}
		else if (cpu.num_outputted > program.size())
		{
			max_range = middle - 1;
			last_with_correct_length = middle;
		}
		else
		{
			first_with_correct_length = middle;
			max_range = middle - 1;
		}
	}

	std::cout << std::format("Exploring between {} and {}\n", first_with_correct_length, last_with_correct_length);

	constexpr size_t num_threads = 16;

	std::mutex result_mutex{};
	std::atomic result = std::numeric_limits<size_t>::max();

	auto brute_forcer = [&](size_t thread_num)
		{
			std::cout << "Launched thread\n";

			size_t num_per_thread_per_iteration = num_threads * 4;
			__m256i increment = _mm256_set1_epi64x(num_per_thread_per_iteration);

			std::int64_t start = first_with_correct_length + thread_num * 4;
			std::array starts_arr{ start, start + 1, start + 2, start + 3 };
			__m256i current_a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(starts_arr.data()));

			while (true)
			{
				start += num_per_thread_per_iteration;
				if (start % 1'000'000'000ull <= num_per_thread_per_iteration)
				{
					std::cout << std::format("thread {} on {}'s attempt\n", thread_num, start);
				}

				if (hard_coded_simd(&current_a))
				{
					std::lock_guard l{ result_mutex };

					std::int64_t results[4];
					_mm256_storeu_si256(reinterpret_cast<__m256i*>(results), current_a);

					std::cout << "thread " << thread_num << " found ~" << results[0] << std::endl;
					return;
				}

				current_a = _mm256_add_epi64(current_a, increment);
			}
		};

	std::array<std::thread, num_threads> threads{};

	for (size_t i = 0; i < num_threads; i++)
	{
		threads[i] = std::thread{ brute_forcer, i };
	}

	for (std::thread& thr : threads)
	{
		thr.join();
	}

	std::cout << result;
#endif
}

// Terribly difficult day.
// I started with trying to bruteforce it. I translated
// the program to C++ so itd be faster, and then used SIMD
// to optimise it. I discovered that the number of letters
// printed correlated to the size of the input, so I used
// binary search to find the minimum and maximum value the
// solution could be in. Bur even with all cores working away,
// it was taking an eternity.

// I started looking for a better solution:
// 
// The input has 3-bit sections that shift with every iteration.
// Even better:
// - Each cycle can be calculated independly
// - We know that at the end of the program a = [0-7], since a / 8 = 0
// - Multiply those by 8 (because the only time we modify a is by dividing by 8), and you get
//   all the possible values a could be in the previous cycle
// - For each possible value, check if the expected output is produced to prune the branch
//
// This new solution solved it in nanoseconds
