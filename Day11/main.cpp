#include <array>
#include <iostream>

#include "../external/utilities/algorithm/memoizer.h"

constexpr size_t pow_int(size_t base, size_t exponent)
{
	return exponent == 0 ? 1 : base * pow_int(base, exponent - 1);
}

constexpr size_t get_num_digits(size_t num)
{
	size_t digits{};
	do
	{
		++digits;
		num /= 10;
	} while (num > 0);
	return digits;
}

// This doesn't work as well, guess why!
template<typename... Args>
auto dumb_memoize(auto func, Args&&... args) -> std::invoke_result_t<decltype(func), Args...>
{
	using Ret = std::invoke_result_t<decltype(func), Args...>;

	// Don't forward, we might have to move the args into the function
	size_t key = utils::multi_hash(args...);
	static std::unordered_map<size_t, Ret> cached = []()
		{
			std::cout << "Created cached" << std::endl;
			return std::unordered_map<size_t, Ret>{};
		}();

	if (auto it = cached.find(key); it != cached.end())
	{
		return it->second;
	}

	auto it = cached.emplace(key, func(std::forward<Args>(args)...));
	return it.first->second;
}

size_t count_num_stones(int num_steps)
{
	std::array<size_t, 8> input = { 773, 79858, 0, 71, 213357, 2937, 1, 3998391, };

	auto recursive_step = [&](auto& self, size_t num, uint8_t steps_remaining) -> size_t
		{
			if (steps_remaining == 0)
			{
				return 0;
			}
			steps_remaining--;

			if (num == 0)
			{
				return self(self, 1, steps_remaining);
			}

			size_t num_digits = get_num_digits(num);

			if (num_digits % 2)
			{
				return self(self, num * 2024, steps_remaining);
			}

			size_t half_digits = num_digits / 2;
			size_t right_half = num % pow_int(10, half_digits);

			for (size_t i = 0; i < half_digits; i++)
			{
				num /= 10;
			}
			return self(self, right_half, steps_remaining) + self(self, num, steps_remaining) + 1;
		};
	size_t num_stones = input.size();

	for (size_t num : input)
	{
		num_stones += recursive_step(recursive_step, num, num_steps);
	}

	return num_stones;
}

size_t count_num_stones_with_memoize(size_t num, uint8_t steps_remaining)
{
	if (steps_remaining == 0)
	{
		return 0;
	}
	steps_remaining--;

	if (num == 0)
	{
		return utils::memoize<&count_num_stones_with_memoize>(1, steps_remaining);
	}

	size_t num_digits = get_num_digits(num);

	if (num_digits % 2)
	{
		return utils::memoize<&count_num_stones_with_memoize>(num * 2024, steps_remaining);
	}

	size_t half_digits = num_digits / 2;
	size_t right_half = num % pow_int(10, half_digits);

	for (size_t i = 0; i < half_digits; i++)
	{
		num /= 10;
	}
	return utils::memoize<&count_num_stones_with_memoize>(right_half, steps_remaining) + utils::memoize<&count_num_stones_with_memoize>(num, steps_remaining) + 1;
}

size_t count_num_stones_with_dumb_memoize(size_t num, uint8_t steps_remaining)
{
	if (steps_remaining == 0)
	{
		return 0;
	}
	steps_remaining--;

	if (num == 0)
	{
		return dumb_memoize(&count_num_stones_with_dumb_memoize, 1, steps_remaining);
	}

	size_t num_digits = get_num_digits(num);

	if (num_digits % 2)
	{
		return dumb_memoize(&count_num_stones_with_dumb_memoize, num * 2024, steps_remaining);
	}

	size_t half_digits = num_digits / 2;
	size_t right_half = num % pow_int(10, half_digits);

	for (size_t i = 0; i < half_digits; i++)
	{
		num /= 10;
	}
	return dumb_memoize(&count_num_stones_with_dumb_memoize, right_half, steps_remaining) + dumb_memoize(&count_num_stones_with_dumb_memoize, num, steps_remaining) + 1;
}

size_t count_num_stones_with_memoizer(int num_steps)
{
	std::array<size_t, 8> input = { 773, 79858, 0, 71, 213357, 2937, 1, 3998391, };

	size_t num_stones = input.size();

	for (size_t num : input)
	{
		num_stones += utils::memoize<&count_num_stones_with_memoize>(num, num_steps);
	}

	return num_stones;
}

size_t count_num_stones_with_dumb_memoizer(int num_steps)
{
	std::array<size_t, 8> input = { 773, 79858, 0, 71, 213357, 2937, 1, 3998391, };

	size_t num_stones = input.size();

	for (size_t num : input)
	{
		num_stones += dumb_memoize(&count_num_stones_with_dumb_memoize, num, num_steps);
	}

	return num_stones;
}

int main()
{
	// std::cout << "This will not finish running before the guild is over:" << std::endl;
	// std::cout << count_num_stones(75) << std::endl;

	// 237149922829154
	std::cout << "Better:\n";
	std::cout << count_num_stones_with_dumb_memoizer(75) << std::endl;

	std::cout << "Good:\n";
	std::cout << count_num_stones_with_memoizer(75) << std::endl;
}
