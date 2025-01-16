#include <bitset>
#include <queue>

#include "input.h"
#include "../external/glm/glm.hpp"

 auto count_num_trail_scores(bool is_day_2)
{
	const auto input = get_input();
	int total{};

	std::bitset<sizeof(input)> closed{};
	std::queue<glm::ivec2> open{};

	for (int y = 0; y < input.size(); y++)
	{
		for (int x = 0; x < input[0].size(); x++)
		{
			auto type = input[y][x];

			if (type != 0)
			{
				continue;
			}

			closed = {};
			open.emplace(x, y);

			while (!open.empty())
			{
				glm::ivec2 curr = open.front();
				open.pop();

				int closedIndex = curr.x + input[0].size() * curr.y;
				if (!is_day_2 && closed[closedIndex])
				{
					continue;
				}
				closed[closedIndex] = true;

				int curr_height = input[curr.y][curr.x];
				total += curr_height == 9;

				for (int offset_x = 0, offset_y = -1, i = 0; i < 4; i++)
				{
					std::swap(offset_x, offset_y);
					offset_y = -offset_y;

					glm::ivec2 nbr = curr + glm::ivec2{ offset_x, offset_y };

					if (nbr.x < 0
						|| nbr.x >= input[0].size()
						|| nbr.y < 0
						|| nbr.y >= input.size()
						|| input[nbr.y][nbr.x] != curr_height + 1)
					{
						continue;
					}

					open.emplace(nbr);
				}
			}
		}
	}
	return total;
}

int main()
{
	return count_num_trail_scores(false);
}