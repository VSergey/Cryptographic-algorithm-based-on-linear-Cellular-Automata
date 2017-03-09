#ifndef LIB_RULE_H
#define LIB_RULE_H

#include <vector>
#include <cstddef>
namespace Crypto
{
	class Rule
	{
		/*
			Хранит состояние клеток по середине в следующем поколении при каждом случае окрестности.
		*/
		std::vector < bool > state;
		public:
			/*
				Принимает номер элементарного клеточного автомата.
			*/
			Rule(const unsigned short number)
			{
				//возможны 8 случаев окрестности
				state.resize(8);
				//получаем состояния
				//читайте про коды Вольфрама
				for (size_t i = 0; i < 8; ++i)
					state[i] = number & (1 << i);
			}
			/*
				Принимает случай окрестности в виде десятичного целого числа.
				Возвращает состояние клетки посередине в следующем поколении.
			*/
			bool operator[] (const unsigned short neighbourhood) const noexcept
			{
				return state[neighbourhood];
			}
	};
}
#endif