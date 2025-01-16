#include "input.h"

consteval bool do_match(const char* lock_or_key_1, const char* lock_or_key_2)
{
	for (int y = 0; y < key_lock_size.y; y++)
	{
		for (int x = 0; x < key_lock_size.x; x++)
		{
			int index = x + y * key_lock_size.x;

			if (lock_or_key_1[index] == '#' && 
				lock_or_key_2[index] == '#')
			{
				return false;
			}

		}
	}
	return true;
}

consteval int count_num_matching_pairs()
{
	std::string_view input = get_input();
	size_t num_keys_locks = input.size() / key_lock_size.x / key_lock_size.y;
	int num_matching_pairs{};

	for (int i = 0; i < num_keys_locks; i++)
	{
		const char* lock_or_key1 = &input[i * key_lock_size.x * key_lock_size.y];

		for (int j = i + 1; j < num_keys_locks; j++)
		{
			const char* lock_or_key2 = &input[j * key_lock_size.x * key_lock_size.y];

			num_matching_pairs += do_match(lock_or_key1, lock_or_key2);
		}
	}
	
	return num_matching_pairs;
}

int main()
{
	return count_num_matching_pairs();
}

// Expected a very difficult part 2, but there wasnt even any!