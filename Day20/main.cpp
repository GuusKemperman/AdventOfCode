#include "input.h"
#include <bitset>
#include <queue>
#include <format>
#include <execution>

template<int CheatDuration>
int get_num_good_cheats()
{
	auto input = get_input();

	glm::ivec2 end{};
	glm::ivec2 start{};
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			const char ch = input[x + y * size.x];
			if (ch == 'S')
			{
				start = { x, y };
			}
			else if (ch == 'E')
			{
				end = { x, y };
			}
		}
	}

	auto get_dist_to_end = [=](glm::ivec2 cheat_start, glm::ivec2 cheat_end) -> int
		{
			struct node
			{
				glm::ivec2 pos{};
				int dist{};
			};

			static thread_local std::queue<node> open{};
			
			while (!open.empty()) { open.pop(); };

			open.emplace(start, 0);
			std::bitset<size.x * size.y> closed{};
			closed[start.x + start.y * size.x] = true;

			while (!open.empty())
			{
				auto [curr, curr_dist] = open.front();
				open.pop();

				if (curr == end)
				{
					return curr_dist;
				}

				if (curr == cheat_start
					&& !closed[cheat_end.x + cheat_end.y * size.x])
				{
					int cheat_dist = glm::abs(cheat_start.x - cheat_end.x) + glm::abs(cheat_start.y - cheat_end.y);
					open.emplace(cheat_end, curr_dist + cheat_dist);
					closed[cheat_end.x + cheat_end.y * size.x] = true;
					continue;
				}
				auto explore_nbr = [&](glm::ivec2 off)
					{
						glm::ivec2 nbr = curr + off;

						if (nbr.x < 0
							|| nbr.x >= size.x
							|| nbr.y < 0
							|| nbr.y >= size.y)
						{
							return;
						}

						int index1D = nbr.x + nbr.y * size.x;

						if (!closed[index1D] && input[index1D] != '#')
						{
							closed[index1D] = true;
							open.emplace(nbr, curr_dist + 1);
						}
					};

				explore_nbr({ 1, 0 });
				explore_nbr({ 0, 1 });
				explore_nbr({ -1, 0 });
				explore_nbr({ 0,-1 });
			}
			return std::numeric_limits<int>::max();
		};

	int default_dist = get_dist_to_end({}, {});

	std::atomic<size_t> num_cheats{};

	std::for_each_n(std::execution::par_unseq, input.begin(), size.x * size.y,
		[&](const char& ch)
		{
			int index = static_cast<int>(&ch - &input[0]);

			if ((index % 1'000) == 0)
			{
				puts(std::format("{}/{}\n", index, input.size()).c_str());
			}

			glm::ivec2 cheat_start = { index % size.x, index / size.x };
			
			if (input[cheat_start.x + cheat_start.y * size.x] == '#')
			{
				return;
			}

			for (int off_y = -CheatDuration; off_y <= CheatDuration; off_y++)
			{
				for (int off_x = -CheatDuration; off_x <= CheatDuration; off_x++)
				{
					glm::ivec2 cheat_end = cheat_start + glm::ivec2{ off_x, off_y };

					int cheat_dist = glm::abs(cheat_start.x - cheat_end.x) + glm::abs(cheat_start.y - cheat_end.y);

					if (cheat_dist > CheatDuration
						|| cheat_end.x < 0
						|| cheat_end.x >= size.x
						|| cheat_end.y < 0
						|| cheat_end.y >= size.y
						|| input[cheat_end.x + cheat_end.y * size.x] == '#')
					{
						continue;
					}

					int dist_if_cheat_here = get_dist_to_end(cheat_start, cheat_end);
					int cheat_saved = default_dist - dist_if_cheat_here;

					if (default_dist - dist_if_cheat_here >= 100)
					{
						num_cheats++;
					}
				}
			}
		});

	return num_cheats;
}

int main()
{
	return get_num_good_cheats<2>();
}

// Very easy, just go over each position and try cheating. 
// We have a small square of positions that we could reach 
// around the point where we started cheating.
// 
// We do regular pathfinding to the end, but we make 'portals':
// - One at the position where we start cheating.
// - One at the position that we could reach within that cheat duration.
// 
// When we reach the start position, teleport to the cheat end position 
// and add the manhattan distance between the two points to the distance
// already travelled. At the end, you have the total distance from start
// to end given a specific cheat.
//
// Do this for each possible cheat!
//
// Found a weird constexpr thing too, why doesn't this work?
// constexpr auto input = get_input();
// const char& ch = input[0];
// int index = &ch - input.data(); 
// assert(index == 0); // This fails??