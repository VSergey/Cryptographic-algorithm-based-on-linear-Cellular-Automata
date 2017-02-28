//Ура!!!
#include <algorithm>
#include <cstddef>
#include <Rule.hpp>

class Field
{
	Rule2 rule;
	std::vector < bool > current;
	std::vector < bool > next;
	size_t lenght;
  public:
	  Field(const Rule2& rule, const unsigned char field) noexcept:rule(rule)
	{
		lenght = 8;
		current.resize(lenght);
		next.resize(lenght);
		for (size_t i = 0, j = lenght - 1;  i < lenght; ++i, --j)
		{
			current[j] = field & (1 << i);
		}
	}
	unsigned char operator () () noexcept
	{
		for (size_t i = 1; i < lenght - 1; ++i)
		{
			next[i] = rule[current[i-1] * 4 + current[i] * 2+ current[i+1]];
		}
		next[0] = rule[current[lenght-1] * 4 + current[0] * 2 + current[1]];
		next[lenght-1] = rule[current[lenght-2] * 4 + current[lenght-1] * 2 + current[0]];
		copy(next.begin(), next.end(), current.begin());
		unsigned char field=0;
		for (size_t i = 0, j = lenght - 1;  i<lenght; ++i, --j)
			field+=current[j]*(1<<i);
		return field;
	}
};
