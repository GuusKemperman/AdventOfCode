#include <bitset>
#include <format>
#include <queue>
#include <Windows.h>

#include "input.h"


void SetCharInConsole(glm::ivec2 p, char ch, int col = 10)
{
	// Create a COORD structure and fill in its members.
	// This specifies the new position of the cursor that we will set.
	COORD coord;
	coord.X = p.x;
	coord.Y = p.y;

	// Obtain a handle to the console screen buffer.
	// (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
	// in conjunction with the GetStdHandle() to retrieve the handle.)
	// Note that because it is a standard handle, we don't need to close it.
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Finally, call the SetConsoleCursorPosition function.
	if (SetConsoleCursorPosition(hConsole, coord))
	{
		// Uh-oh! The function call failed, so you need to handle the error.
		// You can call GetLastError() to get a more specific error code.
		// ...
		SetConsoleTextAttribute(hConsole, col);
		putchar(ch);
		SetConsoleTextAttribute(hConsole, 15);
	}

}

consteval auto get_map()
{
	const auto input = get_input();

	std::array<int, size.x* size.y> map{};
	//std::fill(map.begin(), map.end(), std::numeric_limits<int>::max());

	for (int i = 0; i < 1024; i++)
	{
		glm::ivec2 p = input[i];
		map[p.x + p.y * size.x] = true;
	}

	return map;
}

int get_dist_to_exit()
{
	glm::ivec2 start{};
	glm::ivec2 end{ size - glm::ivec2{1} };

	struct node
	{
		glm::ivec2 pos{};
		int num_moves_made{};
	};

	std::queue<node> open{};
	open.emplace(start, 0);

	std::bitset<size.x * size.y> closed{};

	static constexpr auto map = get_map();

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (map[x + y * size.x])
			{
				putchar('#');
			}
			else
			{
				putchar('.');
			}
		}
		putchar('\n');
	}

	while (!open.empty())
	{
		auto [curr, moves_made] = open.front();
		open.pop();

		if (curr.x < 0
			|| curr.x >= size.x
			|| curr.y < 0
			|| curr.y >= size.y
			|| map[curr.x + curr.y * size.x]
			|| closed[curr.x + curr.y * size.x])
		{
			continue;
		}
		closed[curr.x + curr.y * size.x] = true;
		SetCharInConsole(curr, '.');

		if (curr == end)
		{
			return moves_made;
		}

		const auto explore_nbr = [&](glm::ivec2 off)
			{
				open.emplace(curr + off, moves_made + 1);
			};

		explore_nbr({  0, -1 });
		explore_nbr({  0,  1 });
		explore_nbr({  1, 0 });
		explore_nbr({ -1, 0 });
	}

	return -1;
}

constexpr glm::vec2 get_num_safely_reach_exit()
{
	auto input = get_input();
	std::bitset<size.x* size.y> map{};
	std::array<int, size.x * size.y * 2> open{};
	
	glm::ivec2 end{ size - glm::ivec2{1} };

	for (int i = 0; i < input.size(); i++)
	{
		{
			glm::ivec2 p = input[i];
			map[p.x + p.y * size.x] = true;
		}

		size_t open_begin = 2;
		size_t open_end = open_begin + 2;

		std::bitset<size.x* size.y> closed{};

		bool end_found = false;

		while (open_begin != open_end 
			&& open_begin < open.size())
		{
			glm::ivec2 curr = { open[open_begin], open[open_begin + 1] };
			open_begin += 2;

			if (curr == end)
			{
				end_found = true;
				break;
			}

			const auto explore_nbr = [&](glm::ivec2 off)
				{
					glm::ivec2 nbr = curr + off;

					if (nbr.x < 0
						|| nbr.x >= size.x
						|| nbr.y < 0
						|| nbr.y >= size.y
						|| map[nbr.x + nbr.y * size.x]
						|| closed[nbr.x + nbr.y * size.x])
					{
						return;
					}
					closed[nbr.x + nbr.y * size.x] = true;
					open[open_end] = nbr.x;
					open[open_end + 1] = nbr.y;
					open_end += 2;
				};

			explore_nbr({ 0, -1 });
			explore_nbr({ 0,  1 });
			explore_nbr({ 1, 0 });
			explore_nbr({ -1, 0 });
		}

		if (!end_found)
		{
			return input[i];
		}
	}
	return {-1, -1};
}


int main()
{
	glm::ivec2 p = get_num_safely_reach_exit();
	std::puts(std::format("{}, {}\n", p.x, p.y).c_str());
}


