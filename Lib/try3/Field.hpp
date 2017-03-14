#ifndef LIB_FIELD_H
#define LIB_FIELD_H

#include <cstddef>
#include <climits>
#include <vector>
namespace Crypto
{
	class Field
	{
		/*
			Хранит правило перехода состояний клеток.
			Текущее состояние всех клеток поля.
			Вспомогательное поле для просчёта следующего поколения.
			Размер поля - часто используемая константа.
		*/
		const Rule rule;
		std::vector < bool > current;
		std::vector < bool > next;
		const size_t length = sizeof(unsigned short) * CHAR_BIT;
		public:
		/*
			Получаем номер клеточного автомата в виде объекта rule и код символа для зашифровки.
			Устанавливаем размеры и инициализируем поле двоичными разрядами кодируемого числа.
			Внимание! Конструктор Rule не explicit, вместо первого аргумента можно передать целое число [0;255].
		*/
			Field(const Rule & rule, const unsigned short code):rule(rule)
			{
				//ставим размеры
				current.resize(length);
				next.resize(length);
				//записываем биты числа в поле (по порядку)
				for (size_t i = 0; i < length; ++i)
					current[length - 1 - i] = code & (1 << i);
			}
			/*
				Считаем следующее поколение.
				Возвращаем его в виде десятичного числа.
			*/
			unsigned short encrypt()
			{
				//пробегаем обычные клетки
				for (size_t i = 1; i < length - 1; ++i)
					next[i] = rule[current[i - 1] * 4 + current[i] * 2 + current[i + 1]]; //запрашиваем следующее состояние, передавая окрестность в десятичном виде
				//обрабатываем крайние клетки
				//замыкаем поле в кольцо
				next[0] = rule[current[length - 1] * 4 + current[0] * 2 + current[1]];
				next[lenght - 1] = rule[current[length - 2] * 4 + current[length - 1] * 2 + current[0]];
				//теперь новое поколение стало нынешним
				for (size_t i = 0; i < length; ++i)
					current[i] = next[i];
				//переводим в десятичную систему счисления и возвращаем текущее поколение
				unsigned short code = 0;
				for (size_t i = 0; i < length; ++i)
					code += current[length - 1 - i] * (1 << i);
				return code;
			}
	};
}
#endif
