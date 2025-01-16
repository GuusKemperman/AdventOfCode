#include <bitset>
#include <iostream>
#include <queue>
#include <string>

#include "input.h"
#include "../external/glm/glm.hpp"


consteval int get_safety(int num_steps)
{
	std::array<int, 4> num_in_quadrants{};
	auto input = get_input();
	for (int i = 0; i < input.size(); i += 4)
	{
		glm::ivec2 p = { input[i], input[i + 1] };
		glm::ivec2 v = { input[i + 2], input[i + 3] };

		p += v * num_steps;

		for (int j = 0; j < 2; j++)
		{
			p[j] %= size[j];

			if (p[j] < 0)
			{
				p[j] = size[j] + p[j];
			}
		}

		glm::ivec2 half_size = size / 2;

		if (p.x < half_size.x)
		{
			if (p.y < half_size.y)
			{
				num_in_quadrants[0]++;
			}
			else if (p.y > half_size.y)
			{
				num_in_quadrants[1]++;
			}
		}
		else if (p.x > half_size.x)
		{
			if (p.y < half_size.y)
			{
				num_in_quadrants[2]++;
			}
			else if (p.y > half_size.y)
			{
				num_in_quadrants[3]++;
			}
		}
	}

	return num_in_quadrants[0] * num_in_quadrants[1] * num_in_quadrants[2] * num_in_quadrants[3];
}


void print(int num_steps)
{
	std::array<int, 4> num_in_quadrants{};
	std::array<int, size.x * size.y> painting{};

	static std::vector<glm::ivec2> open{};
	static std::vector<glm::ivec2> positions{};
	positions.clear();

	auto input = get_input();
	for (int i = 0; i < input.size(); i += 4)
	{
		glm::ivec2 p = { input[i], input[i + 1] };
		glm::ivec2 v = { input[i + 2], input[i + 3] };

		p += v * num_steps;

		for (int j = 0; j < 2; j++)
		{
			p[j] %= size[j];

			if (p[j] < 0)
			{
				p[j] = size[j] + p[j];
			}
		}

		positions.emplace_back(p);
		painting[p.x + p.y * size.x]++;
	}

	std::bitset<size.x* size.y> closed{};
	static int highest_num_guards_ever{};
	int highest_num_guards_together_this_step{};

	for (glm::ivec2 p : positions)
	{
		if (closed[p.x + size.x * p.y])
		{
			continue;
		}

		open.emplace_back(p);
		int num_guards_together{};

		while (!open.empty())
		{
			glm::ivec2 curr = open.back();
			open.pop_back();

			int closedIndex = curr.x + size.x * curr.y;
			if (closed[closedIndex])
			{
				continue;
			}
			closed[closedIndex] = true;
			num_guards_together += painting[curr.x + size.x * curr.y];

			for (int offset_x = 0, offset_y = -1, i = 0; i < 4; i++)
			{
				std::swap(offset_x, offset_y);
				offset_y = -offset_y;

				glm::ivec2 nbr = curr + glm::ivec2{ offset_x, offset_y };

				if (nbr.x < 0
					|| nbr.x >= size.x
					|| nbr.y < 0
					|| nbr.y >= size.y
					|| painting[nbr.x + size.x * nbr.y] == 0)
				{
					continue;
				}

				open.emplace_back(nbr);
			}
		}

		highest_num_guards_together_this_step = std::max(num_guards_together, highest_num_guards_together_this_step);
		
	}

	if (highest_num_guards_together_this_step > highest_num_guards_ever)
	{
		highest_num_guards_ever = highest_num_guards_together_this_step;
	}
	else
	{
		return;
	}

	std::cout << "Simulated " << num_steps << " steps, " << highest_num_guards_together_this_step << " together\n";

	std::string str{};
	str.reserve((size.x + 1) * size.y);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			str.append(std::to_string(painting[x + y * size.x]));
		}
		str.push_back('\n');
	}
	std::cout << str << std::endl;
}

int main()
{
	for (int i = 1; true; i++)
	{
		print(i);
	}
}