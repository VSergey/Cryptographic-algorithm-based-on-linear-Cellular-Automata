// Ура!!! 
#ifndef LIB_RULE_H
#define LIB_RULE_H

#include <vector>
#include <cstddef>
namespace Crypto
{
	class Rule
	{
		std::vector < bool > state;
		public:
			Rule(const unsigned short number)
			{
				state.resize(8);
				for (size_t i = 0; i < 8; ++i)
					state[i] = number & (1 << i);
			}
			bool operator[] (const unsigned short neighbourhood) const noexcept
			{
				return state[neighbourhood];
			}
	};
}
#endif