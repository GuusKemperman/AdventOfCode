#include "input.h"


consteval int count_xmas()
{
	constexpr auto input = get_input();
	constexpr std::string_view match = "XMAS";
	int total{};

	for (int y = 0; y < input.size(); y++)
	{
		auto row = input[y];

		for (int x = 0; x < row.size(); x++)
		{
			for (int dirY = -1; dirY <= 1; dirY++)
			{
				for (int dirX = -1; dirX <= 1; dirX++)
				{
					if (dirX == 0 && dirY == 0)
					{
						continue;
					}

					bool is_match = true;
					for (int i = 0; i < match.size(); i++)
					{
						int nbrX = y + dirX * i;
						int nbrY = x + dirY * i;

						if (nbrX < 0
							|| nbrX >= row.size()
							|| nbrY < 0
							|| nbrY >= input.size()
							|| input[nbrY][nbrX] != match[i])
						{
							is_match = false;
							break;
						}
					}

					total += is_match;
				}
			}
		}
	}

	return total;
}


consteval int count_mas_cross()
{
	constexpr auto input = get_input();
	constexpr std::string_view match = "XMAS";
	int total{};

	for (int y = 0; y < input.size(); y++)
	{
		auto row = input[y];

		for (int x = 0; x < row.size(); x++)
		{
			if (row[x] != 'A')
			{
				continue;
			}

			const auto is_match = [&](int corner_x1, int corner_y1, int corner_x2, int corner_y2)
				{
					const auto is_out_of_range = [&](int cx, int cy)
						{
							return cx < 0
								|| cx >= row.size()
								|| cy < 0
								|| cy >= input.size();
						};

					if (is_out_of_range(corner_x1, corner_y1)
						|| is_out_of_range(corner_x2, corner_y2))
					{
						return false;
					}

					char c1 = input[corner_y1][corner_x1];
					char c2 = input[corner_y2][corner_x2];

					if (c1 == 'M')
					{
						return c2 == 'S';
					}
					if (c2 == 'M')
					{
						return c1 == 'S';
					}
					return false;
				};

			if (is_match(x - 1, y - 1, x + 1, y + 1)
				&& is_match(x - 1, y + 1, x + 1, y - 1))
			{
				total++;
			}
		}
	}

	return total;
}


int main()
{
	return count_mas_cross();
}