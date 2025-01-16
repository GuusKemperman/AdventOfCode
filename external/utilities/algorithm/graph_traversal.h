#pragma once
#include <vector>

namespace utils
{
	template<typename node>
	class breadth_first_search
	{
	public:
		node* get_next();

		template<typename... Args>
		void push_and_visit(Args&&... args);

		void clear();

		std::queue<node> open{};


	};



}