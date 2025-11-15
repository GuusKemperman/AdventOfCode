#include <algorithm>
#include <ranges>
#include <print>
#include <mdspan>

#include "input.h"

int main()
{
	std::string_view input = get_input();

	std::int64_t width = std::distance(input.begin(), std::find(input.begin(), input.end(), '\n'));
	std::int64_t height = std::ranges::count(input, '\n');

	std::mdspan map = std::mdspan{ input.data(), height, width + 1 };
	size_t total{};

	for (std::int64_t y = 0; y < height; y++)
	{
		for (std::int64_t x = 0; x < width; x++)
		{
			if (!std::isdigit(map[y, x]))
			{
				continue;
			}

			std::int64_t num_digits = *std::ranges::find_if(std::ranges::iota_view(x, width),
				[&](std::int64_t nbr_x)
				{
					return !std::isdigit(map[y, nbr_x]);
				}) - x;

			size_t num = 0;
			std::from_chars(&map[y, x], &map[y, x + num_digits], num);

			bool has_neighbouring_symbol = [&]
			{
					for (std::int64_t nbr_y = std::max(y - 1, 0ll); nbr_y <= std::min(y + 1, height - 1); nbr_y++)
					{
						for (std::int64_t nbr_x = std::max(x - 1, 0ll); nbr_x <= std::min(x + num_digits, width - 1); nbr_x++)
						{
							char ch = map[nbr_y, nbr_x];
							if (ch != '.' && !std::isdigit(ch))
							{
								return true;
							}
						}
					}
					return false;
				}();

			x += num_digits;

			if (has_neighbouring_symbol)
			{
				total += num;
			}
		}
	}

	std::print("Total: {}", total);
}
