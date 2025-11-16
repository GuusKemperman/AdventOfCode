#include <algorithm>
#include <ranges>
#include <print>
#include <vector>
#include <numeric>

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

	std::vector<size_t> num_matching_cards{};

	for (auto line : input 
		| std::views::split('\n') 
		| std::views::filter([](auto line) { return !line.empty(); }))
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

		num_matching_cards.emplace_back(static_cast<size_t>(num_winners));
	}

	std::vector<size_t> num_cards(num_matching_cards.size(), 1);


	for (auto [card_id, num_matches] : num_matching_cards | std::views::enumerate)
	{
		size_t multiplicant = num_cards[card_id];

		for (size_t i = 1; i <= num_matches; i++)
		{
			num_cards[card_id + i] += multiplicant;
		}
	}

	size_t total = std::reduce(num_cards.begin(), num_cards.end());
	std::print("Total: {}", total);
}
