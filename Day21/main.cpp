#include "input.h"
#include "../external/glm/glm.hpp"
#include "../external/utilities/algorithm/memoizer.h"
#include <string>
#include <charconv>
#include <format>
#include <vector>
#include <algorithm>
#include <execution>

struct directional_key_pad;

template<int Width, int Height>
struct key_pad
{
	glm::ivec2 curr_pos{};
	static constexpr glm::ivec2 size{ Width, Height };
};

struct numeric_key_pad : key_pad<3, 4>
{
	static constexpr std::array<char, 3 * 4> buttons
	{
		'7', '8', '9',
		'4', '5', '6',
		'1', '2', '3',
		 0,  '0', 'A',
	};

	constexpr numeric_key_pad()
	{
		curr_pos = { 2, 3 };
	}

	constexpr glm::ivec2 get_desired_button(char button)
	{
		switch (button)
		{
		case 'A': return { 2, 3 };
		case '0': return { 1, 3 };
		case '1': return { 0, 2 };
		case '2': return { 1, 2 };
		case '3': return { 2, 2 };
		case '4': return { 0, 1 };
		case '5': return { 1, 1 };
		case '6': return { 2, 1 };
		case '7': return { 0, 0 };
		case '8': return { 1, 0 };
		case '9': return { 2, 0 };
		}
		std::unreachable();
	};
};

struct directional_key_pad : key_pad<3, 2>
{
	constexpr bool operator==(const directional_key_pad& other) const { return curr_pos == other.curr_pos; }

	static constexpr std::array<char, 3 * 2> buttons
	{
		 0,  '^', 'A',
		'<', 'v', '>',
	};

	constexpr directional_key_pad()
	{
		curr_pos = { 2, 0 };
	}

	constexpr glm::ivec2 get_desired_button(char button)
	{
		switch (button)
		{
		case 'A': return { 2, 0 };
		case '^': return { 1, 0 };
		case '<': return { 0, 1 };
		case '>': return { 2, 1 };
		case 'v': return { 1, 1 };
		}
		std::unreachable();
	};
};

static constexpr size_t num_robots = 25;
using robot_pads = std::array<directional_key_pad, num_robots>;

template<>
struct std::hash<utils::hashable_tuple<char, robot_pads, int>>
{
	size_t operator()(const utils::hashable_tuple<char, robot_pads, int>& t) const
	{
		// only hash the robot pads that are still to come
		int next_index = std::get<int>(t);
		const robot_pads& pads = std::get<robot_pads>(t);
		size_t hash = utils::multi_hash(0x1235679, std::get<char>(t), next_index);

		for (int i = next_index; i < pads.size(); i++)
		{
			hash = utils::multi_hash(hash, pads[i].curr_pos.x, pads[i].curr_pos.y);
		}

		return hash;
	}
};

bool operator==(const utils::hashable_tuple<char, robot_pads, int>& lhs, const utils::hashable_tuple<char, robot_pads, int>& rhs)
{
	if (std::get<char>(lhs) != std::get<char>(rhs)
		|| std::get<int>(lhs) != std::get<int>(rhs))
	{
		return false;
	}

	int next_index = std::get<int>(lhs);
	const robot_pads& pads_lhs = std::get<robot_pads>(lhs);
	const robot_pads& pads_rhs = std::get<robot_pads>(rhs);

	for (int i = next_index; i < pads_lhs.size(); i++)
	{
		if (pads_lhs[i] != pads_rhs[i])
		{
			return false;
		}
	}

	return true;
}

template<>
struct std::hash<robot_pads>
{
	size_t operator()(const robot_pads& pads) const
	{
		size_t hash = 0x1235679;

		for (auto& pad : pads)
		{
			hash = utils::multi_hash(hash, pad.curr_pos.x, pad.curr_pos.y);
		}

		return hash;
	}
};

std::pair<size_t, robot_pads> get_sequence_length_memoized(char desired_output, robot_pads key_pads, int key_pad_index);

size_t get_sequence_length(char desired_output, auto& key_pad, auto& key_pads, int next_key_pad_index)
{
	glm::ivec2 desired_button = key_pad.get_desired_button(desired_output);
	glm::ivec2 delta = desired_button - key_pad.curr_pos;

	glm::vec<2, char> buttons{ delta.x > 0 ? '>' : '<', delta.y > 0 ? 'v' : '^' };

	if (next_key_pad_index == key_pads.size())
	{
		key_pad.curr_pos = desired_button;
		return glm::abs(delta.x) + glm::abs(delta.y) + 1;
	}

	glm::vec<2, size_t> axis_scores{ std::numeric_limits<size_t>::max() };
	std::array axis_pads{ key_pads, key_pads };

	for (int axis = 0; axis < 2; axis++)
	{
		glm::ivec2 delta_axis{};
		delta_axis[axis] = delta[axis];

		glm::ivec2 delta_not_axis{};

		int index1D = key_pad.curr_pos.x + delta_axis.x + (key_pad.curr_pos.y + delta_axis.y) * key_pad.size.x;
		bool is_axis_allowed = key_pad.buttons[index1D] != 0;

		if (!is_axis_allowed)
		{
			continue;
		}

		axis_scores[axis] = 0;
		for (size_t i = 0; i < glm::abs(delta[axis]); i++)
		{
			auto [length_addition, pads_state] = utils::memoize<&get_sequence_length_memoized>(buttons[axis],
				axis_pads[axis],
				next_key_pad_index);
			axis_scores[axis] += length_addition;
			axis_pads[axis] = pads_state;
		}

		for (size_t i = 0; i < glm::abs(delta[!axis]); i++)
		{
			auto [length_addition, pads_state] = utils::memoize<&get_sequence_length_memoized>(buttons[!axis],
				axis_pads[axis],
				next_key_pad_index);
			axis_scores[axis] += length_addition;
			axis_pads[axis] = pads_state;
		}

		auto [length_addition, pads_state] = utils::memoize<&get_sequence_length_memoized>('A',
			axis_pads[axis],
			next_key_pad_index);
		axis_scores[axis] += length_addition;
		axis_pads[axis] = pads_state;
	}

	key_pad.curr_pos = desired_button;

	if (axis_scores[0] < axis_scores[1])
	{
		key_pads = axis_pads[0];
		key_pad.curr_pos = desired_button;
		return axis_scores[0];
	}
	else
	{
		key_pads = axis_pads[1];
		key_pad.curr_pos = desired_button;
		return axis_scores[1];
	}
}

std::pair<size_t, robot_pads> get_sequence_length_memoized(char desired_output, robot_pads key_pads, int key_pad_index)
{
	auto& key_pad =  key_pads[key_pad_index];
	size_t length = get_sequence_length(desired_output, key_pad, key_pads, key_pad_index + 1);
	return { length, key_pads };
}

size_t get_sequence_length(char desired_output, numeric_key_pad& key_pad, auto& key_pads)
{
	return get_sequence_length(desired_output, key_pad, key_pads, 0);
}

std::string get_sequence(std::string_view desired_output, auto& key_pad)
{
	std::string sequence{};

	for (char ch : desired_output)
	{
		glm::ivec2 desired_button = key_pad.get_desired_button(ch);
		glm::ivec2 delta = desired_button - key_pad.curr_pos;

		char button_x = delta.x > 0 ? '>' : '<';
		char button_y = delta.y > 0 ? 'v' : '^';

		auto get_button_score = [](char button)
			{
				switch (button)
				{
				case '^': return 1;
				case '>': return 1;
				case 'v': return 2;
				case '<': return 3;
				}
				std::unreachable();
			};
		
		int score_x = get_button_score(button_x);
		int score_y = get_button_score(button_y);

		bool is_x_first_allowed = key_pad.buttons[key_pad.curr_pos.x + delta.x + key_pad.curr_pos.y * key_pad.size.x] != 0;

		if (score_x > score_y && is_x_first_allowed)
		{
			sequence.append(glm::abs(delta.x), button_x);
			sequence.append(glm::abs(delta.y), button_y);
		}
		else
		{
			sequence.append(glm::abs(delta.y), button_y);
			sequence.append(glm::abs(delta.x), button_x);
		}

		sequence.push_back('A');
		key_pad.curr_pos = desired_button;
	}

	return sequence;
}

size_t get_complexity()
{
	auto input = get_input();

	std::mutex total_mutex{};
	size_t total = 0;

	std::for_each(/*std::execution::par_unseq, */input.begin(), input.end(),
		[&](std::string_view code)
		{
			numeric_key_pad numeric_pad{};
			robot_pads directional_pads{};

			std::string total_string_to_input{};

			size_t total_length = 0;

			for (char ch : code)
			{
				total_length += get_sequence_length(ch, numeric_pad, directional_pads);
			}

			size_t numeric_code;
			std::from_chars(code.data(), code.data() + code.size(), numeric_code);

			puts(std::format("\n\nCode {} = {} * {} = {}\n\n", code, total_length, numeric_code, numeric_code * total_length).c_str());

			total_mutex.lock();
			total += numeric_code * total_length;
			total_mutex.unlock();
		});

	return total;
}

int main()
{
	puts(std::format("{}!\n", get_complexity()).c_str());
	return 0;
}

// Reflection:
// God this was misery, hardest puzzle of the year.
// My solutions kept working for the example, but not for my actual input, 
// making things considerably harder.
//
// You also have to go from button 1 to button 2; you can either do that
// by doing the vertical movement followed by horizontal movement,
// or the other way around, horizontal followed by vertical movement.
// Now if you only have one keypad; it doesn't matter which way you take,
// they both have the same distance. But once you get a chain, one of
// them might be faster than the other.
// 
// I analysed the logic and noticed some keys are further from 'A' than others,
// so I came with theories:
	// Expensive keys ('<') and 'v') should be back-to-back
	// Expensive keys are far from A, should be done first.
// I think i was onto something, but I wasn't able to fletch this out into a working solution. 
// 
// It got way easier when I realised that I could just bruteforce it. 
// I also realised, you don't have to store any string (you definitely 
// will run out of memory), you can just recurse directly. 
// There are only 6 positions each robot hand could be in, which means
// there arent a lot of possible 'states'. Especially since, if you're 
// at a certain keypad and you want to find out the fastest way from the 
// current button to the next button, you only have to examine keypads that 
// can (in)directly control the current keypad, keypads further down the line
// can be ignored. This made the puzzle a great candidate for memoization. I try
// vertical-first and horizontal-first everytime I have to move from button
// to button, followed by walking up the line of robots to compute 
// the total presses needed by the human. In the numeric keypad, I choose 
// the option (vertical or horizontal) based on which one had the least number
// of human presses.
// 
// I also learned you can use a ternary for the lhs of an assignment:
// *(cond ? &lhs : &rhs) = 1;

