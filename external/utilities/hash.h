#pragma once
#include <tuple>

namespace utils
{
	static constexpr size_t combine_hashes(size_t hash1, size_t hash2)
	{
		hash1 ^= hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2);
		return hash1;
	}

	template<typename Arg1>
	size_t multi_hash(const Arg1& first)
	{
		return std::hash<Arg1>{}(first);
	}

	template<typename Arg1, typename... Args>
	size_t multi_hash(const Arg1& first, const Args&... others)
	{
		return combine_hashes(std::hash<Arg1>{}(first), multi_hash(others...));
	}

	namespace details
	{
		struct hash_tuple_t {
			constexpr bool operator==(const hash_tuple_t&) const = default;
		};
	}

	template<typename... T>
	using hashable_tuple = std::tuple<details::hash_tuple_t, T...>;

	template<typename... T>
	auto make_hashable_tuple(T&&... t)
	{
		return std::make_tuple(utils::details::hash_tuple_t{}, std::forward<T>(t)...);
	}
}

template<>
struct std::hash<utils::details::hash_tuple_t>
{
	size_t operator()(const utils::details::hash_tuple_t& t) const
	{
		return 0;
	}
};

template<typename... T>
struct std::hash<utils::hashable_tuple<T...>>
{
	size_t operator()(const utils::hashable_tuple<T...>& t) const
	{
		return std::apply(&utils::multi_hash<utils::details::hash_tuple_t, T...>, t);
	}
};