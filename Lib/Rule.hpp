//Ура!!!
#include <stdexcept>
#include <vector>
#include <cstddef>

class Rule
{
	std::vector<bool> state;
	public:
		Rule2(const unsigned short number)
		{
			state.resize(8);
			if (number < 256)
			{
				for (size_t i = 0; i < 8; ++i)
					state[i] = number & (1<<i);
			}
			else
				throw std::out_of_range( "Неверный номер правила!" );
		} 
		bool operator[] (const unsigned short neighborhood) const
		{
			if (neighborhood < 8)
				return state[neighborhood];
			else
				throw std::out_of_range( "Неверный случай окрестности" );
		}
};