#include <algorithm>
#include <iostream>
#include <string>

#include "input.h"
#include <list>
#include <vector>

auto get_uncondensed_input()
{
	std::vector<int> memory{};

	auto input = get_input();

	bool is_next_empty = false;
	int index{};
	for (int size : input)
	{
		int id = is_next_empty ? -1 : index++;
		memory.insert(memory.end(), size, id);
		is_next_empty = !is_next_empty;
	}
	return memory;
}

auto get_check_sum(const auto& memory)
{
	size_t check_sum{};
	for (size_t i = 0; i < memory.size(); i++)
	{
		if (memory[i] == -1)
		{
			continue;
		}

		size_t id = memory[i];
		check_sum += i * id;
	}

	return check_sum;
}

auto get_fragmented()
{
	auto memory = get_uncondensed_input();

	auto empty_iterator = memory.begin();
	auto block_iterator = memory.rbegin();

	while (true)
	{
		empty_iterator = std::find(empty_iterator, memory.end(), -1);
		block_iterator = std::find_if(block_iterator, memory.rend(), [](int n) { return n != -1; });

		if (empty_iterator == memory.end()
			|| block_iterator == memory.rend()
			|| empty_iterator >= block_iterator.base())
		{
			break;
		}

		std::swap(*empty_iterator, *block_iterator);
	}

	return get_check_sum(memory);
}

auto get_unfragmented()
{
	struct page
	{
		int id{};
		int size{};
	};
	std::list<page> pages{};

	auto input = get_input();

	bool is_next_empty = false;
	int next_id{};
	for (int size : input)
	{
		int id = is_next_empty ? -1 : next_id++;
		pages.emplace_back(id, size);
		is_next_empty = !is_next_empty;
	}

	while (next_id --> 0)
	{

		auto full_page_it = std::find_if(pages.begin(), pages.end(),
			[next_id](const page& page)
			{
				return page.id == next_id;
			});

		auto empty_page_it = std::find_if(pages.begin(), full_page_it,
			[&](const page& page)
			{
				return page.id == -1 && page.size >= full_page_it->size;
			});

		if (empty_page_it == full_page_it)
		{
			continue;
		}

		int number_of_slots_left = empty_page_it->size - full_page_it->size;
		std::swap(*empty_page_it, *full_page_it);

		full_page_it->size -= number_of_slots_left;

		// Combine pages
		if (std::next(full_page_it) != pages.end()
			&& std::next(full_page_it)->id == -1)
		{
			full_page_it->size += std::next(full_page_it)->size;
			pages.erase(std::next(full_page_it));
		}

		if (full_page_it != pages.begin()
			&& std::prev(full_page_it)->id == -1)
		{
			full_page_it->size += std::prev(full_page_it)->size;
			pages.erase(std::prev(full_page_it));
		}

		if (number_of_slots_left > 0)
		{
			pages.emplace(std::next(empty_page_it), -1, number_of_slots_left);
		}
	}

	size_t check_sum{};
	int index{};

	for (const auto& page : pages)
	{
		if (page.id == -1)
		{
			index += page.size;
			continue;
		}

		for (int i = 0; i < page.size; i++, index++)
		{
			check_sum += index * page.id;
		}
	}

	return check_sum;


	//auto memory = get_uncondensed_input();
 //	auto block_start_2 = memory.rbegin();
	//auto block_end_2 = memory.rbegin();

	//int lowest_id_processed = *std::find_if(block_end_2, memory.rend(),
	//	[](int n)
	//	{
	//		return n != -1;
	//	});

	//while (true)
	//{
	//	block_start_2 = std::find_if(block_end_2, memory.rend(),
	//		[](int n)
	//		{
	//			return n != -1;
	//		});

	//	if (block_start_2 == memory.rend())
	//	{
	//		break;
	//	}

	//	block_end_2 = std::find_if(block_start_2, memory.rend(), 
	//		[block_start_2](int n)
	//		{
	//			return n != *block_start_2;
	//		});

	//	if (*block_start_2 > lowest_id_processed)
	//	{
	//		continue;
	//	}
	//	lowest_id_processed = *block_start_2;

	//	if (block_end_2 == memory.rend())
	//	{
	//		break;
	//	}

	//	size_t block_size = std::distance(block_start_2, block_end_2);

	//	auto start_of_empty_page = memory.begin();
	//	bool is_page_large_enough = false;

	//	for (; start_of_empty_page < block_end_2.base();)
	//	{
	//		start_of_empty_page = std::find(start_of_empty_page, memory.end(), -1);
	//		auto end_of_empty_page = std::find_if(start_of_empty_page, memory.end(),
	//			[](int n) { return n != -1; });

	//		size_t empty_page_size = std::distance(start_of_empty_page, end_of_empty_page);

	//		if (empty_page_size >= block_size)
	//		{
	//			is_page_large_enough = true;
	//			break;
	//		}

	//		start_of_empty_page = end_of_empty_page;
	//	}

	//	if (!is_page_large_enough)
	//	{
	//		continue;
	//	}

	//	for (auto it = start_of_empty_page; it != start_of_empty_page + block_size; ++it)
	//	{
	//		*it = *block_start_2;
	//	}

	//	for (auto it = block_start_2; it != block_end_2; ++it)
	//	{
	//		*it = -1;
	//	}
	//}

	//return get_check_sum(memory);
}

int main()
{
	std::cout << get_unfragmented() << std::endl;
}