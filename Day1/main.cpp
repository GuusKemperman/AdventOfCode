#include "input.h"

template<bool ListNum, size_t S>
static consteval auto get_list(const std::array<int, S>& input)
{
	std::array<int, S / 2> list;

	for (size_t i = 0; i < S / 2; i++)
	{
		list[i] = input[i * 2 + ListNum];
	}

	return list;
}

template<typename T>
static consteval auto abs_constexpr(T v)
{
	return v < 0 ? -v : v;
}

template<size_t S>
static consteval auto get_total_dist(const std::array<int, S>& list1, const std::array<int, S>& list2)
{
	std::array<std::array<int, S>, 2> lists = { list1, list2 };

	int total_dist{};

	for (size_t i = 0; i < S; i++)
	{
		size_t num_remaining = S - i;

		const auto get_lowest_val = [num_remaining](auto& list)
			{
				auto end = list.begin() + num_remaining;
				auto back_it = end - 1;
				auto lowest_it = std::min_element(list.begin(), end);
				std::swap(*lowest_it, *back_it);
				return *back_it;
			};

		std::array<int, 2> lowest_values = { get_lowest_val(lists[0]), get_lowest_val(lists[1]) };
		int distance = abs_constexpr(lowest_values[0] - lowest_values[1]);
		total_dist += distance;
	}

	return total_dist;
}

template<size_t S>
static consteval auto get_total_dist()
{
	return get_total_dist(get_list<0>(get_input()), get_list<1>(get_input()));
}

template<size_t S>
static consteval auto compare_similarity(const std::array<int, S>& list1, const std::array<int, S>& list2)
{
	int total{};
	for (int id : list1)
	{
		size_t occurrence_count = std::count(list2.begin(), list2.end(), id);
		total += id * static_cast<int>(occurrence_count);
	}

	return total;
}

static consteval auto compare_similarity()
{
	return compare_similarity(get_list<0>(get_input()), get_list<1>(get_input()));
}

int main()
{
	// return get_total_dist();
	return compare_similarity();
}