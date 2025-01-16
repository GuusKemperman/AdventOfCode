#include <bitset>
#include <queue>

#include "input.h"
#include "../external/glm/glm.hpp"

int get_fence_cost()
{
	int total_cost{};
	auto input = get_input();

	std::bitset<sizeof(input)> closed{};
	std::queue<glm::ivec2> open{};

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int index = x + y * width;
			if (closed[index])
			{
				continue;
			}

			char expected_ch = input[x + y * width];
			int perimeter{};
			int area{};
			open.emplace(x, y);

			while (!open.empty())
			{
				glm::ivec2 curr = open.front();
				open.pop();

				int closedIndex = curr.x + width * curr.y;
				if (closed[closedIndex])
				{
					continue;
				}
				closed[closedIndex] = true;
				area++;

				for (int offset_x = 0, offset_y = -1, i = 0; i < 4; i++)
				{
					std::swap(offset_x, offset_y);
					offset_y = -offset_y;

					glm::ivec2 nbr = curr + glm::ivec2{ offset_x, offset_y };

					if (nbr.x < 0
						|| nbr.x >= width
						|| nbr.y < 0
						|| nbr.y >= height
						|| input[nbr.x + width * nbr.y] != expected_ch)
					{
						perimeter++;
						continue;
					}

					open.emplace(nbr);
				}
			}

			total_cost += area * perimeter;
		}
	}

	return total_cost;
}


int get_fence_cost_with_sides()
{
	int total_cost{};
	auto input = get_input();

	std::bitset<sizeof(input)> closed{};
	std::queue<glm::ivec2> open{};

	struct fence
	{
		constexpr bool operator==(const fence&) const = default;
		glm::ivec2 front{};
		glm::ivec2 back{};
	};
	std::vector<fence> fences{};

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int index = x + y * width;
			if (closed[index])
			{
				continue;
			}

			char expected_ch = input[x + y * width];
			int area{};
			open.emplace(x, y);

			while (!open.empty())
			{
				glm::ivec2 curr = open.front();
				open.pop();

				int closedIndex = curr.x + width * curr.y;
				if (closed[closedIndex])
				{
					continue;
				}
				closed[closedIndex] = true;
				area++;

				for (int offset_x = 0, offset_y = -1, i = 0; i < 4; i++)
				{
					std::swap(offset_x, offset_y);
					offset_y = -offset_y;

					glm::ivec2 nbr = curr + glm::ivec2{ offset_x, offset_y };

					if (nbr.x < 0
						|| nbr.x >= width
						|| nbr.y < 0
						|| nbr.y >= height
						|| input[nbr.x + width * nbr.y] != expected_ch)
					{
						fences.emplace_back(curr, nbr);
						continue;
					}

					open.emplace(nbr);
				}
			}

			int num_sides = 0;
			while (!fences.empty())
			{
				num_sides++;
				fence start = fences.back();
				fences.pop_back();

				glm::ivec2 fence_forward = start.front - start.back;

				const auto remove_side = [&](glm::ivec2 direction)
					{
						fence curr_fence = start;
						while (true)
						{
							fence next_fence = { curr_fence.front + direction, curr_fence.back + direction };
							auto it = std::find(fences.begin(), fences.end(), next_fence);

							if (it == fences.end())
							{
								return;
							}

							fences.erase(it);
							curr_fence = next_fence;
						}
					};

				remove_side({ fence_forward.y, -fence_forward.x });
				remove_side({ -fence_forward.y, fence_forward.x });
			}

			total_cost += area * num_sides;
		}
	}

	return total_cost;
}

int main()
{
	return get_fence_cost_with_sides();
}