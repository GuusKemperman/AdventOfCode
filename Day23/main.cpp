#include "input.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <algorithm>

// Combine the name of a PC into a number for ease of use
constexpr std::uint16_t make_id(char lhs, char rhs)
{
	return ((+lhs) << 8) | +rhs;
}

// Fast max with three items, for hashing while creating consistent
// results regardless of argument order
constexpr std::uint64_t make_set_id(std::uint16_t pc1, std::uint16_t pc2, std::uint16_t pc3)
{
	std::uint16_t highest, middlest, lowest;

	if (pc1 > pc2) {
		if (pc1 > pc3) {
			highest = pc1;
			middlest = (pc2 > pc3) ? pc2 : pc3;
			lowest = (pc2 > pc3) ? pc3 : pc2;
		}
		else {
			highest = pc3;
			middlest = pc1;
			lowest = pc2;
		}
	}
	else {
		if (pc2 > pc3) {
			highest = pc2;
			middlest = (pc1 > pc3) ? pc1 : pc3;
			lowest = (pc1 > pc3) ? pc3 : pc1;
		}
		else {
			highest = pc3;
			middlest = pc2;
			lowest = pc1;
		}
	}

	return static_cast<std::uint64_t>(highest) << 32 |
		static_cast<std::uint64_t>(middlest) << 16 |
		static_cast<std::uint64_t>(lowest);
}

constexpr auto break_id(std::uint16_t id)
{
	return std::make_pair<char, char>((id >> 8) & std::numeric_limits<char>::max(), id & std::numeric_limits<char>::max());
}

// Fun fact -> some compilers optimise this function to a single instruction
constexpr auto num_on_bits(std::uint64_t num)
{
	std::uint64_t bits_on{};

	do
	{
		bits_on += num & 1;
	} while (num >>= 1);

	return bits_on;
}

struct pc
{
	std::uint16_t id{};
	std::vector<std::reference_wrapper<const pc>> connected_pcs{};
};

bool operator==(const pc& lhs, const pc& rhs) { return lhs.id == rhs.id; }

auto get_pcs()
{
	std::unordered_map<std::uint16_t, pc> pcs{};
	auto input = get_input();

	for (int i = 0; i < input.size(); i += 4)
	{
		std::uint16_t id1 = make_id(input[i], input[i + 1]);
		std::uint16_t id2 = make_id(input[i + 2], input[i + 3]);

		pc& pc1 = pcs[id1];
		pc& pc2 = pcs[id2];

		pc1.id = id1;
		pc2.id = id2;

		pc1.connected_pcs.emplace_back(pc2);
		pc2.connected_pcs.emplace_back(pc1);		
	}

	return pcs;
}

// Day1
auto get_num_groups_with_t()
{
	auto pcs = get_pcs();
	std::unordered_set<std::uint64_t> sets{};

	for (const auto& [start_id, start_pc] : pcs)
	{
		if (break_id(start_id).first != 't')
		{
			continue;
		}

		for (int i = 0; i < start_pc.connected_pcs.size(); i++)
		{
			const pc& pc1 = start_pc.connected_pcs[i];

			for (int j = i + 1; j < start_pc.connected_pcs.size(); j++)
			{
				const pc& pc2 = start_pc.connected_pcs[j];

				if (std::find(pc1.connected_pcs.begin(), pc1.connected_pcs.end(), pc2) == pc1.connected_pcs.end())
				{
					continue;
				}

				sets.emplace(make_set_id(start_id, pc1.id, pc2.id));
			}
		}
	}

	return sets.size();
}

// Day2
auto get_largest_lan_party()
{
	std::vector<std::reference_wrapper<const pc>> largest_set{};
	auto pcs = get_pcs();

	std::vector<std::reference_wrapper<const pc>> network{};

	for (const auto& [start_id, start_pc] : pcs)
	{
		// Generate subsets of start_pc.pcs whose size is larger than largest_set

		// + 1 cus our own pc is in it too
		std::uint64_t largest_possible_subset = start_pc.connected_pcs.size() + 1;

		if (largest_possible_subset <= largest_set.size())
		{
			continue;
		}

		std::uint64_t num_sets = 2 << start_pc.connected_pcs.size();

		for (std::uint64_t set_num = 0; set_num < num_sets; set_num++)
		{
			if (num_on_bits(set_num) + 1 <= largest_set.size())
			{
				continue;
			}

			network.clear();
			network.emplace_back(start_pc);

			for (std::uint64_t i = 0; i < start_pc.connected_pcs.size(); i++)
			{
				if (set_num & (1ull << i))
				{
					network.emplace_back(start_pc.connected_pcs[i]);
				}
			}

			// Check if its a valid network, every pc must be connected to every other pc
			for (int i = 0; i < network.size(); i++)
			{
				const pc& pc_in_network = network[i];
				for (int j = i + 1; j < network.size(); j++)
				{
					const pc& other_pc_in_network = network[j];

					if (std::ranges::find(pc_in_network.connected_pcs, other_pc_in_network) == pc_in_network.connected_pcs.end())
					{
						goto invalid_network;
					}
				}
			}

			largest_set = network;

		invalid_network:;
		}
	}

	std::vector<std::string> ids{};

	for (const pc& pc : largest_set)
	{
		std::string& str = ids.emplace_back();
		str.push_back(break_id(pc.id).first);
		str.push_back(break_id(pc.id).second);
	}

	std::sort(ids.begin(), ids.end());

	for (const std::string& str : ids)
	{
		std::cout << str << ",";
	}
}

int main()
{
	get_largest_lan_party();
}

// For day2:
// 
// For every PC, you have all the computers it's connected to.
// Now you're looking for a network that that PC would be a part of;
// Since every PC in that network you are looking for would be connected 
// to eachother, you can assume that the current PC would be a part of that
// network + some other computers the PC is connected to.
// 
// You can generate over all possible subsets of the PCs that the current PC is
// connected to. Check if every computer in that network is connected to every
// other computer in the network. If it is? Great! You found a LAN party. 
// 
// Do this for every PC and find the largest one.
// 
// This was a fun day


