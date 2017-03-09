// Ура!!!
#ifndef LIB_FIELD_H
#define LIB_FIELD_H

//нам понадобится
//тип size_t
#include <cstddef>
//макрос CHAR_BIT
#include <climits>
//тип Rule
#include <Rule.hpp>
namespace Crypto
{
	class Field
	{
		const Rule rule;
		std::vector < bool > current; //текущее поле
		std::vector < bool > next; //временное поле для просчёта следующего поколения
		const size_t lenght = sizeof(unsigned short) * CHAR_BIT; //размер поля (часто испльзуется)
		public:
		//Внимание! Конструктор Rule не explicit, можно передавать первым аргументом число [0;255]
			Field(const Rule & rule, const unsigned short field):rule(rule)
			{
				//ставим размеры
				current.resize(lenght);
				next.resize(lenght);
				//записываем биты числа в поле (по порядку)
				for (size_t i = 0; i < lenght; ++i)
					current[lenght - 1 - i] = field & (1 << i);
			}
			//считаем следующее поколение и возвращаем его
			unsigned short encrypt()
			{
				//пробегаем обычные клетки
				for (size_t i = 1; i < lenght - 1; ++i)
					next[i] = rule[current[i - 1] * 4 + current[i] * 2 + current[i + 1]]; //запрашиваем следующее состояние, передавая окрестность в десятичном виде
				//обрабатываем крайние клетки
				//замыкаем поле в кольцо
				next[0] = rule[current[lenght - 1] * 4 + current[0] * 2 + current[1]];
				next[lenght - 1] = rule[current[lenght - 2] * 4 + current[lenght - 1] * 2 + current[0]];
				//теперь новое поколение стало нынешним
				for (size_t i = 0; i < lenght; ++i)
					current[i] = next[i];
				//переводим в десятичную систему счисления и возвращаем текущее поколение
				unsigned short field = 0;
				for (size_t i = 0; i < lenght; ++i)
					field += current[lenght - 1 - i] * (1 << i);
				return field;
			}
	};
}
#endif