#include <algorithm>
#include <ranges>
#include <print>
#include <mdspan>
#include <unordered_map>

#include "input.h"

int main()
{
	std::string_view input = get_input();

	std::int64_t width = std::distance(input.begin(), std::find(input.begin(), input.end(), '\n'));
	std::int64_t height = std::ranges::count(input, '\n');

	std::mdspan map = std::mdspan{ input.data(), height, width + 1 };

	std::unordered_map<const char*, std::vector<size_t>> found_keys{};

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

			for (std::int64_t nbr_y = std::max(y - 1, 0ll); nbr_y <= std::min(y + 1, height - 1); nbr_y++)
			{
				for (std::int64_t nbr_x = std::max(x - 1, 0ll); nbr_x <= std::min(x + num_digits, width - 1); nbr_x++)
				{
					const char* ch = &map[nbr_y, nbr_x];
					if (*ch == '*')
					{
						found_keys[ch].emplace_back(num);
					}
				}
			}

			x += num_digits;
		}
	}

	size_t total{};

	for (const auto& vec : std::views::values(found_keys))
	{
		if (vec.size() == 2)
		{
			total += vec[0] * vec[1];
		}
	}

	std::print("Total: {}", total);
}
