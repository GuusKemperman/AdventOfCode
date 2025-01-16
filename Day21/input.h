#pragma once
#include <array>
#include <string_view>

//#define EXAMPLE

consteval auto get_input()
{
	std::array<std::string_view, 5> arr
	{

#ifdef EXAMPLE
	"029A",
	"980A",
	"179A",
	"456A",
	"379A",
#else

"286A",
"480A",
"140A",
"413A",
"964A",
#endif
	};
	return arr;
}
