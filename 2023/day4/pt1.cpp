#include <algorithm>
#include <ranges>
#include <print>

#include "input.h"

int main()
{
	std::string_view input = get_input();

	auto to_integers = 
		std::views::split(' ') |
		std::views::filter([](auto token) { return !token.empty(); }) |
		std::views::transform([](auto token) -> int
			{
				int res{};
				std::from_chars(&*token.begin(), &*token.end(), res);
				return res;
			});

	size_t total{};

	for (auto line : input | std::views::split('\n'))
	{
		auto winning_numbers = line |
			std::views::drop_while([](char ch) { return ch != ':'; }) |
			std::views::drop(2) |
			std::views::take_while([](char ch) { return ch != '|'; }) |
			to_integers;

		auto my_numbers = line |
			std::views::drop_while([](char ch) { return ch != '|'; }) |
			std::views::drop(2) |
			to_integers;

		auto num_winners = std::ranges::count_if(my_numbers,
			[&](int num)
			{
				bool is_winner = std::ranges::contains(winning_numbers, num);
				return is_winner;
			});

		if (num_winners == 0)
		{
			continue;
		}

		total += 1ull << static_cast<size_t>(num_winners - 1);
	}

	std::print("Total: {}", total);
}
