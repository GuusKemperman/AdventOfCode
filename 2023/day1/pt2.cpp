#include <fstream>
#include <sstream>
#include <print>
#include <array>
#include <string_view>

int main()
{
	std::ifstream file{ "input.txt" };

	if (!file.is_open())
	{
		throw std::invalid_argument{ "missing input" };
	}

	int total{};

	for (std::string line{}; std::getline(file, line);)
	{
		auto find_digit = 
			[&](int curr, int dir) -> int
			{
				for (; curr < static_cast<int>(line.length()); curr += dir)
				{
					if (std::isdigit(line[curr]))
					{
						return line[curr] - '0';
					}

					static constexpr std::array<std::string_view, 9> digits =
					{
						"one",
						"two",
						"three",
						"four",
						"five",
						"six",
						"seven",
						"eight",
						"nine"
					};

					for (size_t digit_idx = 0; digit_idx < digits.size(); digit_idx++)
					{
						if (line.substr(curr, digits[digit_idx].length()) == digits[digit_idx])
						{
							return static_cast<int>(digit_idx) + 1;
						}
					}
				}

				throw std::invalid_argument{ "expected digit" };
			};

		int num = find_digit(0, 1) * 10 + find_digit(static_cast<int>(line.length()) - 1, -1);
		total += num;
	}

	std::print("Total: {}", total);
}