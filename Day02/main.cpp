#include "input.h"
#include "iostream"

consteval int num_safe_reports()
{
	auto input = get_input();

	int total_safe{};

	for (auto begin_of_sequence = input.begin(); begin_of_sequence != input.end();)
	{
		auto end_of_sequence = std::find(begin_of_sequence, input.end(), -1);

		if (*(end_of_sequence - 1) < *begin_of_sequence)
		{
			std::reverse(begin_of_sequence, end_of_sequence);
		}

		bool is_safe = true;
		for (auto it = begin_of_sequence + 1; it != end_of_sequence; ++it)
		{
			int prev = *(it - 1);
			int curr = *it;
			int delta = curr - prev;

			if (delta > 3
				|| delta <= 0)
			{
				is_safe = false;
				break;
			}
		}

		total_safe += is_safe;
		begin_of_sequence = end_of_sequence + 1;
	}

	return total_safe;
}

consteval int num_safe_reports_with_dampener()
{
	auto input = get_input();

	int total_safe{};

	for (auto begin_of_sequence = input.begin(); begin_of_sequence != input.end();)
	{
		auto end_of_sequence = std::find(begin_of_sequence, input.end(), -1);

		if (*(end_of_sequence - 1) < *begin_of_sequence)
		{
			std::reverse(begin_of_sequence, end_of_sequence);
		}

		bool is_really_safe = false;

		for (auto ignored = begin_of_sequence; ignored != end_of_sequence; ++ignored)
		{
			bool is_safe = true;

			for (auto it = begin_of_sequence; it != end_of_sequence; ++it)
			{
				if (it == ignored)
				{
					continue;
				}

				auto prev_it = it == begin_of_sequence ? it : it - 1;

				if (prev_it == ignored)
				{
					prev_it = prev_it == begin_of_sequence ? it : prev_it - 1;
				}

				auto next_it = it == end_of_sequence - 1 ? it : it + 1;

				if (next_it == ignored)
				{
					next_it = next_it == end_of_sequence - 1 ? it : next_it + 1;
				}


				int prev = prev_it == it ? *it - 1 : *prev_it;
				int next = next_it == it ? *it + 1 : *next_it;
				int curr = *it;

				int delta_prev = curr - prev;
				int delta_next = next - curr;

				if (delta_prev > 3
					|| delta_prev <= 0
					|| delta_next > 3
					|| delta_next <= 0)
				{
					is_safe = false;
					break;
				}
			}

			if (is_safe)
			{
				is_really_safe = true;
				break;
			}
		}

		total_safe += is_really_safe;
		begin_of_sequence = end_of_sequence + 1;
	}

	return total_safe;
}

int main()
{
	return num_safe_reports_with_dampener();
}