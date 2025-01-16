#include "input.h"
#include <iostream>



template<typename T>
static consteval auto abs_constexpr(T v)
{
	return v < 0 ? -v : v;
}
consteval auto is_roughle_even(auto lhs, auto rhs)
{
	return abs_constexpr(lhs - rhs) < 0.001f;
}



consteval size_t solve()
{
	auto input = get_input();
	long double num_tokens{};

	for (int i = 0; i < input.size();)
	{
		long double a_x = input[i++];
		long double a_y = input[i++];

		long double b_x = input[i++];
		long double b_y = input[i++];

		long double p_x = input[i++] + 10000000000000;
		long double p_y = input[i++] + 10000000000000;

		long double num_a = (b_y * p_x - b_x * p_y) / (b_y * a_x - b_x * a_y);

		long double num_b_x = (p_x - (num_a * a_x)) / b_x;
		long double num_b_y = (p_y - (num_a * a_y)) / b_y;

		if (is_roughle_even(static_cast<long double>(static_cast<size_t>(num_a)), num_a)
			&& is_roughle_even(static_cast<long double>(static_cast<size_t>(num_b_x)), num_b_y)
			&& is_roughle_even(num_b_x, num_b_y))
		{
			num_tokens += 3 * num_a + num_b_x;

		}
	}

	return num_tokens;
}

int main()
{
	std::cout << solve();
}