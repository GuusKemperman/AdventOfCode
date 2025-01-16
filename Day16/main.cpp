#include <bitset>
#include <iostream>
#include <numeric>
#include <optional>
#include <Windows.h>

#include "input.h"

void SetCharInConsole(glm::ivec2 p, char ch)
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
		SetConsoleTextAttribute(hConsole, 10);
		putchar(ch);
		SetConsoleTextAttribute(hConsole, 15);
	}
}

int lowest_score = std::numeric_limits<int>::max();
static constexpr auto input = get_input();
std::array<int, size.x* size.y * 4> previous_scores{};
glm::ivec2 end{};
std::bitset<size.x * size.y> winning_seats{};
glm::ivec2 start_pos{};
glm::ivec2 start_dir{ 1, 0 };

template<bool IsDay2>
bool recurse_proceed_day1(glm::ivec2 pos, glm::ivec2 dir, int path_score)
{
	if (path_score > lowest_score)
	{
		return false;
	}

	if (pos == end)
	{
		if constexpr (IsDay2)
		{
			return path_score == lowest_score;
		}
		else
		{
			lowest_score = std::min(lowest_score, path_score);
			return false;
		}
	}

	if (input[pos.x + pos.y * size.x] == '#')
	{
		return false;
	}

	int dir_as_int;

	if (dir == glm::ivec2{ 1, 0 })
	{
		dir_as_int = 0;
	}
	else if (dir == glm::ivec2{ -1, 0 })
	{
		dir_as_int = 1;
	}
	else if (dir == glm::ivec2{ 0, 1 })
	{
		dir_as_int = 2;
	}
	else if (dir == glm::ivec2{ 0, -1 })
	{
		dir_as_int = 3;
	}

	int closed_index = pos.x + pos.y * size.x + dir_as_int * size.x * size.y;

	int previous_score = previous_scores[closed_index];

	if (previous_score != 0 && previous_score < path_score)
	{
		return false;
	}
	previous_scores[closed_index] = path_score;

	if constexpr (!IsDay2)
	{
		//SetCharInConsole(pos, 'X');
	}

	const auto explore_dir = [&](glm::ivec2 next_dir, int next_path_score)
		{
			glm::ivec2 next_pos = pos + next_dir;
			bool was_winning_path = recurse_proceed_day1<IsDay2>(next_pos, next_dir, next_path_score);

			if constexpr (IsDay2)
			{
				if (was_winning_path)
				{
					SetCharInConsole(next_pos, 'O');
					winning_seats[next_pos.x + next_pos.y * size.x] = was_winning_path;
				}

			}

			return was_winning_path;
		};

	bool was_winning_path = false;
	was_winning_path |= explore_dir(dir, path_score + 1);
	was_winning_path |= explore_dir({ -dir.y, dir.x }, path_score + 1001);
	was_winning_path |= explore_dir({ dir.y, -dir.x }, path_score + 1001);
	was_winning_path |= explore_dir(-dir, path_score + 2001);
	return was_winning_path;
}

void parse_map()
{
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			char type = input[x + y * size.x];
			putchar(type);

			switch (type)
			{
			case 'S':
				start_pos = { x, y };
				break;
			case 'E':
				end = { x, y };
			}
		}
		putchar('\n');
	}

}

int get_score_shortest_path()
{
	recurse_proceed_day1<false>(start_pos, start_dir, 0);
	std::cout << "Lowest path: " << lowest_score << std::endl;
	return lowest_score;
}

int count_num_winning_seats()
{
	previous_scores = {};
	recurse_proceed_day1<true>(start_pos, start_dir, 0);

	int total{};
	for (int y = 0; y < size.y; y++)
	{
		for (int x= 0; x < size.x; x++)
		{
			if (winning_seats[x + y * size.x])
			{
				total++;
			}
		}
	}

	return total + 1; // Plus start
}

int main()
{
	parse_map();
	get_score_shortest_path();
	return count_num_winning_seats();
}