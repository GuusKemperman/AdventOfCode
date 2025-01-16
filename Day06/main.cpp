#include <bitset>
#include <optional>

#include "input.h"

 int count_path_length()
{
	auto input = get_input();

	struct path_point
	{
		int pos_x{};
		int pos_y{};
		int dir_x{};
		int dir_y{};

		constexpr bool operator==(const path_point&) const  = default;
		constexpr bool operator<(const path_point& other) const {
			if (pos_x != other.pos_x) return pos_x < other.pos_x;
			if (pos_y != other.pos_y) return pos_y < other.pos_y;
			if (dir_x != other.dir_x) return dir_x < other.dir_x;
			return dir_y < other.dir_y;
		}
	};

	path_point current{};

	for (int y = 0; y < input.size(); y++)
	{
		auto& line = input[y];
		for (int x = 0; x < line.size(); x++)
		{
			const char ch = line[x];

			// Specifically tailored to my input
			if (ch == '^')
			{
				current.pos_x = x;
				current.pos_y = y;
				current.dir_x = 0;
				current.dir_y = -1;
				break;
			}
		}
	}

	int total = 0;
	path_point start = current;

	const auto progress_path_point = [&input](path_point current) -> std::optional<path_point>
		{
			path_point next_current{};

			next_current.pos_x = current.pos_x + current.dir_x;
			next_current.pos_y = current.pos_y + current.dir_y;

			if (next_current.pos_y >= 0
				&& next_current.pos_y < input.size()
				&& next_current.pos_x >= 0
				&& next_current.pos_x < input[0].size())
			{
				bool is_obstacle = input[next_current.pos_y][next_current.pos_x] == '#';

				if (is_obstacle)
				{
					int tmp = current.dir_x;
					current.dir_x = -current.dir_y;
					current.dir_y = tmp;
				}
				else
				{
					current.pos_x = next_current.pos_x;
					current.pos_y = next_current.pos_y;
				}

				return current;
			}
			return std::nullopt;
		};

	while (true)
	{

		if (auto next = progress_path_point(current))
		{
			current = *next;
			input[current.pos_y][current.pos_x] = 'X';
		}
		else
		{
			break;
		}
	}

	// sorted vector
	std::bitset<sizeof(input) * 4> was_taken{};

	for (int y = 0; y < input.size(); y++)
	{
		auto& line = input[y];
		for (int x = 0; x < line.size(); x++)
		{
			char& ch = line[x];

			if (ch != 'X')
			{
				continue;
			}

			ch = '#';

			was_taken.reset();
			path_point current = start;

			bool is_loop = false;

			while (true)
			{
				int index1D = current.pos_y * line.size() + current.pos_x;

				if (current.dir_x == 0 && current.dir_y == -1)
				{
					index1D += sizeof(input);
				}
				else if (current.dir_x == 1 && current.dir_y == 0)
				{
					index1D += sizeof(input) * 2;
				}
				else if (current.dir_x == 0 && current.dir_y == 1)
				{
					index1D += sizeof(input) * 3;
				}

				if (was_taken[index1D])
				{
					is_loop = true;
					break;
				}
				was_taken[index1D] = true;

				if (auto next = progress_path_point(current))
				{
					current = *next;
				}
				else
				{
					break;
				}
			}

			if (is_loop)
			{
				total++;
			}

			ch = 'X';
		}
	}
	return total;
}

int main()
{
	return count_path_length();
}