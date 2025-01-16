#include <algorithm>

#include "input.h"
#include <execution>
#include "../external/utilities/algorithm/memoizer.h"

struct better_lookup
{
	char added_col{};
	std::vector<better_lookup> children{};
	int num_ended_here{};
};

template<>
struct std::hash<better_lookup>
{
	size_t operator()(const better_lookup& l) const noexcept
	{
		// sketchy but easier here
		return reinterpret_cast<std::uintptr_t>(&l);
	}
};

bool operator==(const better_lookup& lhs, const better_lookup& rhs)
{
	// sketchy but easier here
	return &lhs == &rhs;
}

better_lookup get_better_lookup()
{
	auto inventory = get_inventory();
	better_lookup look_up{};

	for (std::string_view str : inventory)
	{
		auto add_to_look_up = [](auto& self,
			better_lookup& look_up, 
			std::string_view remaining_str)
			{
				if (remaining_str.empty())
				{
					look_up.num_ended_here++;
					return;
				}

				auto child = std::find_if(look_up.children.begin(),
					look_up.children.end(),
					[&](const better_lookup& child)
					{
						return child.added_col == remaining_str.front();
					});

				if (child == look_up.children.end())
				{
					look_up.children.emplace_back(remaining_str.front());
					child = look_up.children.end() - 1;
				}

				self(self, *child, remaining_str.substr(1));
			};
		add_to_look_up(add_to_look_up, look_up, str);
	}
	return look_up;
}

auto look_up_root = get_better_lookup();

// String by value, so we can store it in memoization
size_t count_num_designs_possible(const better_lookup& curr_look_up, std::string remaining_design)
{
	if (remaining_design.empty())
	{
		return curr_look_up.num_ended_here;
	}

	auto child = std::find_if(curr_look_up.children.begin(),
		curr_look_up.children.end(),
		[&](const better_lookup& child)
		{
			return child.added_col == remaining_design.front();
		});

	if (child == curr_look_up.children.end())
	{
		return 0;
	}

	size_t num_possible_if_continue = utils::memoize<count_num_designs_possible>(*child, remaining_design.substr(1));
	size_t num_possible_if_restart = child->num_ended_here != 0 ?
		child->num_ended_here * utils::memoize<count_num_designs_possible>(look_up_root, remaining_design.substr(1))
		: 0;

	return num_possible_if_continue + num_possible_if_restart;
}

size_t count_num_possible_designs()
{
	auto designs = get_designs();
	size_t num_possible = 0;
	for (std::string_view design : designs)
	{
		num_possible += utils::memoize<count_num_designs_possible>(look_up_root, std::string{ design });
	}

	return num_possible;
}

int main()
{
	puts(std::format("{}\n", count_num_possible_designs()).c_str());
}

// Reflection:
// First wrote a structure for faster lookup. I forgot the name, but I researched it once
// when implementing a search bar. Essentially store strings as a 'graph', with each node
// containing the letter that was added, and children. The children also have letters that were
// added, so if you recurse down the graph from parent to child while checking the letters added,
// you can very quickly find all strings that start with a given string. If a child's letter doesn't
// match the expected letter, you stop recursing and move on to the next child.
// 
// Was made much faster using memoization. Two optimizations are better than one, but reducing
// complexity is far better than speeding up individual cycles, so memoization shouldve 
// received initial focus





