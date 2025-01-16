#include <numeric>
#include <vector>

#include "input.h"
#include "../external/glm/glm.hpp"

consteval size_t get_num_anti_nodes()
{
	const auto input = get_input();

	// Store positions
	struct frequency
	{
		char ch{};
		std::vector<glm::ivec2> positions{};
	};
	std::vector<frequency> frequencies{};

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char ch = input[y * width + x];

			if (ch == '.')
			{
				continue;
			}

			auto existing = std::ranges::find_if(frequencies,
				[&](const frequency& f)
				{
					return f.ch == ch;
				});

			if (existing == frequencies.end())
			{
				existing = frequencies.insert(frequencies.end(), frequency{ ch });
			}

			existing->positions.emplace_back(x, y);
		}
	}

	std::array<bool, sizeof(input)> anti_nodes{};

	for (const frequency& f : frequencies)
	{
		for (glm::ivec2 p1 : f.positions)
		{
			for (glm::ivec2 p2 : f.positions)
			{
				if (p1 == p2)
				{
					continue;
				}

				glm::ivec2 delta = p1 - p2;
				glm::ivec2 anti_node_p = p1 + delta;

				if (anti_node_p.x >= 0
					&& anti_node_p.x < width
					&& anti_node_p.y >= 0
					&& anti_node_p.y < height)
				{
					anti_nodes[anti_node_p.y * width + anti_node_p.x] = true;
				}
			}
		}
	}

	int num_anti_nodes = std::reduce(anti_nodes.begin(), anti_nodes.end(), 0);
	return num_anti_nodes;
}

consteval size_t get_num_anti_nodes_with_harmonics()
{
	const auto input = get_input();

	// Store positions
	struct frequency
	{
		char ch{};
		std::vector<glm::ivec2> positions{};
	};
	std::vector<frequency> frequencies{};

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char ch = input[y * width + x];

			if (ch == '.')
			{
				continue;
			}

			auto existing = std::ranges::find_if(frequencies,
				[&](const frequency& f)
				{
					return f.ch == ch;
				});

			if (existing == frequencies.end())
			{
				existing = frequencies.insert(frequencies.end(), frequency{ ch });
			}

			existing->positions.emplace_back(x, y);
		}
	}

	std::array<bool, sizeof(input)> anti_nodes{};

	for (const frequency& f : frequencies)
	{
		for (glm::ivec2 p1 : f.positions)
		{
			for (glm::ivec2 p2 : f.positions)
			{
				if (p1 == p2)
				{
					continue;
				}

				glm::ivec2 delta = p2 - p1;
				glm::ivec2 anti_node_p = p1 + delta;

				while (anti_node_p.x >= 0
					&& anti_node_p.x < width
					&& anti_node_p.y >= 0
					&& anti_node_p.y < height)
				{
					anti_nodes[anti_node_p.y * width + anti_node_p.x] = true;
					anti_node_p += delta;
				}
			}
		}
	}

	int num_anti_nodes = std::reduce(anti_nodes.begin(), anti_nodes.end(), 0);
	return num_anti_nodes;
}

int main()
{
	return get_num_anti_nodes();
}