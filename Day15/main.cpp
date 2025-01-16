#include <vector>

#include "input.h"
#include <Windows.h>

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

auto execute_program_day1()
{
	auto map = get_map();

	glm::ivec2 robot{};

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (map[x + y * size.x] == '@')
			{
				robot = { x, y };
				goto solve;
			}
		}
	}

solve:
	for (char instruction : robot_program)
	{
		glm::ivec2 dir;
		switch (instruction)
		{
		case '^': dir = { 0, -1 }; break;
		case '>': dir = { 1,  0 }; break;
		case '<': dir = { -1,  0 }; break;
		case 'v': dir = { 0,  1 }; break;
		}

		glm::ivec2 first_open_space = robot;

		while (1)
		{
			first_open_space += dir;
			char type = map[first_open_space.x + first_open_space.y * size.x];

			if (type == '#')
			{
				goto end_of_loop;
			}

			if (type == '.')
			{
				break;
			}
		}

		glm::ivec2 curr = first_open_space;
		while (curr != robot)
		{
			glm::ivec2 next = curr - dir;
			std::swap(map[curr.x + curr.y * size.y], map[next.x + next.y * size.y]);
			curr = next;
		}
		robot += dir;

	end_of_loop:;
	}

	int score{};

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (map[x + y * size.x] == 'O')
			{
				score += x + y * 100;
			}
		}
	}
	return score;
}

struct box
{
	glm::ivec2 box_min() const { return p; }
	glm::ivec2 box_max() const { return p + glm::ivec2{ 1, 0 }; }

	bool is_overlapping(glm::ivec2 point) const
	{
		return point.x >= box_min().x
			&& point.x <= box_max().x
			&& point.y >= box_min().y
			&& point.y <= box_max().y;
	}

	bool is_overlapping(box other) const
	{
		return box_min().x <= other.box_max().x
			&& box_max().x >= other.box_min().x
			&& box_max().y >= other.box_min().y
			&& box_min().y <= other.box_max().y;
	}

	glm::ivec2 p{};
};

auto execute_program_day2()
{
	std::vector<box> boxes{};

	std::array map = [&boxes]()
		{
			auto old_map = get_map();

			std::array<char, size.x * 2 * size.y> new_map;

			for (int y = 0, new_map_i = 0; y < size.y; y++)
			{
				for (int x = 0; x < size.x; x++, new_map_i += 2)
				{
					switch (old_map[x + y * size.x])
					{
					case '#':
						new_map[new_map_i] = '#';
						new_map[new_map_i + 1] = '#';
						break;
					case '.':
						new_map[new_map_i] = '.';
						new_map[new_map_i + 1] = '.';
						break;
					case 'O':
						boxes.emplace_back(glm::ivec2{ x * 2, y });
						new_map[new_map_i] = '.';
						new_map[new_map_i + 1] = '.';
						break;
					case '@':
						new_map[new_map_i] = '@';
						new_map[new_map_i + 1] = '.';
						break;
					}
				}
			}

			return new_map;
		}();



	glm::ivec2 robot{};

	constexpr glm::ivec2 double_size = size * glm::ivec2{ 2, 1 };
	constexpr glm::ivec2 size = double_size;

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (map[x + y * size.x] == '@')
			{
				robot = { x, y };
			}
		}
	}


	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			auto collided_with = std::find_if(boxes.begin(), boxes.end(),
				[x, y](const box& box)
				{
					return box.is_overlapping(glm::ivec2{ x, y });
				});

			if (collided_with == boxes.end())
			{
				putchar(map[x + y * size.x]);
			}
			else if (collided_with->p.x == x)
			{
				putchar('[');
			}
			else
			{
				putchar(']');
			}
		}
		putchar('\n');
	}

	const auto simulate_move = [&](auto& self,
		std::vector<box>& boxes,
		box& current,
		glm::ivec2 dir) -> bool
		{
			current.p += dir;

			// Check if we ran into wall
			for (int y = current.box_min().y; y <= current.box_max().y; y++)
			{
				for (int x = current.box_min().x; x <= current.box_max().x; x++)
				{
					if (map[x + y * size.x] == '#')
					{
						return false;
					}
				}
			}

			// Lets move all the boxes we are overlapping with,
			// and recurse.

			for (box& other_box : boxes)
			{
				if (&other_box == &current)
				{
					continue;
				}

				if (!other_box.is_overlapping(current))
				{
					continue;
				}

				if (!self(self, boxes, other_box, dir))
				{
					return false;
				}
			}

			return true;
		};

	while (1)
	{
		for (char instruction : robot_program)
		{
			glm::ivec2 dir;
			switch (instruction)
			{
			case '^': dir = { 0, -1 }; break;
			case '>': dir = { 1,  0 }; break;
			case '<': dir = { -1,  0 }; break;
			case 'v': dir = { 0,  1 }; break;
			}

			glm::ivec2 next_pos = robot + dir;

			if (map[next_pos.x + next_pos.y * size.x] == '#')
			{
				continue;
			}

			std::vector<box> copy = boxes;

			auto collided_with = std::find_if(copy.begin(), copy.end(),
				[next_pos](const box& box)
				{
					return box.is_overlapping(next_pos);
				});

			if (collided_with != copy.end()
				&& !simulate_move(simulate_move, copy, *collided_with, dir))
			{
				continue;
			}

			for (int i = 0; i < boxes.size(); i++)
			{
				if (copy[i].p == boxes[i].p)
				{
					continue;
				}

				SetCharInConsole(boxes[i].box_min(), '.');
				SetCharInConsole(boxes[i].box_max(), '.');
			}

			SetCharInConsole(robot, '.');

			for (int i = 0; i < boxes.size(); i++)
			{
				if (copy[i].p == boxes[i].p)
				{
					continue;
				}

				SetCharInConsole(copy[i].box_min(), '[');
				SetCharInConsole(copy[i].box_max(), ']');
			}

			SetCharInConsole(next_pos, '@');
			std::swap(copy, boxes);
			robot = next_pos;

		}

	}

	int score{};

	for (box& box : boxes)
	{
		score += box.box_min().x + box.box_min().y * 100;
	}

	SetCharInConsole(double_size, '\n');

	return score;
}

int main()
{
	return execute_program_day2();
}