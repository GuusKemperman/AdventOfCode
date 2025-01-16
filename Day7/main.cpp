#include <iostream>
#include <string>

#include "input.h"

constexpr size_t pow_int(size_t base, size_t exponent)
{
	return exponent == 0 ? 1 : base * pow_int(base, exponent - 1);
}

constexpr size_t num_digits(size_t num)
{
	size_t digits{};
	do
	{
		++digits;
		num /= 10;
	} while (num > 0);
	return digits;
}


consteval size_t count_num_valid_calculations()
{
	const auto input = get_input();
	size_t total = 0;

	for (auto it = input.begin(); it != input.end();)
	{
		size_t expected_result = *it;
		auto args_begin = it + 1;
		auto args_end = std::find(args_begin, input.end(), - 1);
		it = args_end + 1;

		size_t num_args = std::distance(args_begin, args_end);
		size_t num_operands = num_args - 1;
		size_t num_permutations = 1ull << num_operands;

		for (int permutation = 0; permutation <= num_permutations; permutation++)
		{
			size_t result = *args_begin;
			for (int operand_num = 0; operand_num < num_operands; operand_num++)
			{
				size_t num = *(args_begin + operand_num + 1);
				int is_multiplication = permutation & (1 << operand_num);

				if (is_multiplication)
				{
					result *= num;
				}
				else
				{
					result += num;
				}
			}

			if (result == expected_result)
			{
				total += expected_result;
				break;
			}
		}
	}

	return total;
}

 size_t count_num_valid_calculations_pt2()
{
	const auto input = get_input();
	size_t total = 0;

	for (auto it = input.begin(); it != input.end();)
	{
		size_t expected_result = *it;
		auto args_begin = it + 1;
		auto args_end = std::find(args_begin, input.end(), -1);
		it = args_end + 1;

		size_t num_args = std::distance(args_begin, args_end);
		size_t num_operands = num_args - 1;
		size_t num_permutations = pow_int(3, num_operands);

		std::array<char, 16> operands{};

		for (int permutation = 0; permutation <= num_permutations; permutation++)
		{
			size_t result = *args_begin;
			for (int operand_num = 0; operand_num < num_operands; operand_num++)
			{
				size_t num = *(args_begin + operand_num + 1);

				switch (operands[operand_num])
				{
				case 0:
				{
					result += num;
					break;
				}
				case 1:
				{
					result *= num;
					break;
				}
				case 2:
				{
					size_t digits_in_num = num_digits(num);
					result *= pow_int(10, digits_in_num);
					result += num;
					break;
				}
				}

				if (result > expected_result)
				{
					break;
				}
			}

			if (result == expected_result)
			{
				total += expected_result;
				break;
			}

			for (char& op : operands)
			{
				op++;
				if (op == 3)
				{
					op = 0;
				}
				else
				{
					break;
				}
			}
		}
	}

	return total;
}

int main()
{
	std::cout << count_num_valid_calculations_pt2() << std::endl;
}