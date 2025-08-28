#include <fstream>
#include <sstream>
#include <print>

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
		static constexpr auto is_digit = [](char ch) { return std::isdigit(ch); };

		char first = *std::find_if(line.begin(), line.end(), is_digit);
		char second = *std::find_if(line.rbegin(), line.rend(), is_digit);

		total += (first - '0') * 10 + (second - '0');;
	}

	std::print("Total: {}", total);
}