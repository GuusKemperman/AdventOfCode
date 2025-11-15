#include <ranges>
#include <print>

#include "input.h"

int main()
{
	std::string_view input = get_input();
	int total{};

	for (auto line : input | std::views::split('\n'))
	{
		static constexpr auto is_digit = [](char ch) { return std::isdigit(ch); };
		
		char first = *std::ranges::find_if(line, is_digit);
		char second = *std::ranges::find_if(line | std::views::reverse, is_digit); 

		total += (first - '0') * 10 + (second - '0');
	}

	std::print("Total: {}", total);
}
