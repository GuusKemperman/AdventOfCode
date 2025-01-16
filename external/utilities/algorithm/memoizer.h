#pragma once
#include <functional>
#include <unordered_map>
#include <mutex>
#include "../hash.h"

namespace utils
{
	namespace details
	{
		template<auto, typename>
		struct mem_helper
		{
			// Not a signature
		};

		template<auto Func, typename Ret, typename... Params>
		struct mem_helper<Func, std::function<Ret(Params...)>>
		{
			static auto& get_cached()
			{
				static std::unordered_map<hashable_tuple<Params...>, Ret> cached{};
				return cached;
			}

			static inline std::mutex mut{};

			template<typename... Args>
			static Ret memoize(Args&&... args)
			{
				// Don't forward, we might have to move the args into the function
				auto key = make_hashable_tuple<Params...>(std::forward<Params>(args)...);

				auto& cached = get_cached();

				{
					std::lock_guard __{ mut };
					if (auto it = cached.find(key); it != cached.end())
					{
						return it->second;
					}
				}

				auto result = Func(std::forward<Args>(args)...);

				std::lock_guard __{ mut };
				auto it = cached.emplace(key, std::move(result));
				return it.first->second;
			}
		};
	}

	template<auto Func, typename... Args>
	auto memoize(Args&&... args)
	{
		// We borrow std::function's deduction guides,
		// because deducing functors ourselves gets annoying real quick
		using STD_Func_Type = decltype(std::function{ Func });
		return details::mem_helper<Func, STD_Func_Type>::memoize(std::forward<Args>(args)...);
	}
}