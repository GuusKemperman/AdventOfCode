#include <fstream>
#include <sstream>
#include <print>
#include <ranges>
#include <unordered_map>

int main()
{
	std::ifstream file{ "input.txt" };

	if (!file.is_open())
	{
		throw std::invalid_argument{ "missing input" };
	}

	int total{};

	int game_id = 1;
	for (std::string game{}; std::getline(file, game); game_id++)
	{
		auto start = std::ranges::find(game, ':');

		auto to_string = [](auto&& r) -> std::string_view
		{
			const auto data = &*r.begin();
			const auto size = static_cast<std::size_t>(std::ranges::distance(r));

			return { data, size };
		};

		std::unordered_map<std::string, int> min_colors_in_bag{};

		for (std::string_view round : game |
			std::ranges::views::drop(game.find(':') + 2) |
			std::ranges::views::split(';') |
			std::ranges::views::transform(to_string))
		{
			for (std::string_view color_and_count : round |
				std::ranges::views::split(',') |
				std::ranges::views::transform(to_string))
			{
				std::stringstream str{ std::string{ color_and_count } };

				int count;
				std::string color;
				str >> count >> color;

				int& in_bag = min_colors_in_bag[color];
				in_bag = std::max(in_bag, count);
			}
		}

		if (min_colors_in_bag["red"] <= 12 &&
			min_colors_in_bag["green"] <= 13 &&
			min_colors_in_bag["blue"] <= 14)
		{
			total += game_id;
		}
	}

	std::print("Total: {}", total);
}
