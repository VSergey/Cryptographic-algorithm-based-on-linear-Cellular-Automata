/*
Программа:клеточный автомат
Автор:kukushechka
Дата:08/04/2016 Время:11:36 Описание: программа, шифрующая данные с помощью элементарного клеточного автомата.

Обновления:
v1.9 19/02/2017
Изменены права доступа к функции заполнения поля
Улучшена читабельность

v1.8 18/02/2017
Изменён вывод эволюции
Изменено копирование нового поля в старое

v1.7 12/02/2017
Введены комментарии
Введена проверка входных данных
Исправлена ошибка размера поля

v1.6 11/02/2017
Обновлена структура проекта
Удалён лишний код
Смена предназначения
Смена описания

v 1.5 07/10/2016
Переход к представлению правил перехода состояний в виде кода Вольфрама.

 v 1.0 05/10/2016
 Переход на ОО модель
 Введены правила перехода состояний
 Введено игровое поле
 Оптимизирована проверка  окрестности
 Поле представлено в виде кольца
 Исправлены ошибки хранения состояний

v 0.8 08/04/2016
Введено описание проекта.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <stdexcept>
using namespace std;

//правило перехода
class Rule
{
	//состояния
	int state[8];
  public:
  //получаем состояние в зависимости от окрестности
	int when(int condition) const
	{
		return state[condition];
	}
	explicit Rule(unsigned short ruleNumber)
	{
		if (ruleNumber > 255)
			throw out_of_range("Неверный номер правила!");
		//разбиваем на разряды
		for (int i = 0; i < 8; ++i)
		{
			state[i] = ruleNumber % 2;
			ruleNumber /= 2;
		}
	}
	Rule()
	{
		cout << "Введите номер правила. Если вы ничего не поняли, то введите число от 0 до 255 включительно:\n";
		unsigned short ruleNumber;
		//проверка ввода
		while (true)
		{
			cin >> ruleNumber;
			if (!cin||ruleNumber>255)
			{
				cout<<"Ошибка, введите натуральное число меньше 255!\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		//разбиваем на разряды
		for (int i = 0; i < 8; ++i)
		{
			state[i] = ruleNumber % 2;
			ruleNumber /= 2;
		}
	}
};

//поле
class Field
{
	Rule rule;
	//текущее поколение
	vector < int >currentField;
	//следующее
	vector < int >nextField;
	//заполняем поле
	void fill()
	{
		cout<<"Введите символ для зашифровки: ";
		char c;
		cin >> c;
		for (int i = currentField.size() - 1; i >= 0; --i)
		{
			currentField[i] = c % 2;
			c /= 2;
		}
	}
  public:
	Field(Rule rule):rule(rule)
	{
		cout << "Введите длинну поля: ";
		unsigned lenght;
		//проверка ввода
		while (true)
		{
			cin >> lenght;
			if (!cin)
			{
				cout<<"Ошибка, введите положительное число!\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		currentField.resize(lenght);
		nextField.resize(lenght);
		fill();
	}
	Field(const int lenght, Rule rule):rule(rule)
	{
		currentField.resize(lenght);
		nextField.resize(lenght);
		fill();
	}
	//просчёт следующего поколения
	void operator () ()
	{
		//перебираем все клетки
		for (int coun = 1; coun < currentField.size()-1; ++coun)
		{
			nextField[coun] = rule.when(currentField[coun-1]+currentField[coun]*2+currentField[coun+1]*4);
		}
		nextField[0] = rule.when(currentField[currentField.size()-1]+currentField[0]*2+currentField[1]*4);
		nextField[currentField.size()-1] = rule.when(currentField[currentField.size()-2]+currentField[currentField.size()-1]*2+currentField[0]*4);
		//просчитали поколение
		copy(nextField.begin(), nextField.end(), currentField.begin());
	}
	//вывод
	void show()
	{
		char num = 0;
		//выводим клетки + переводим поле в код символа
		for (int cou = 0, base = 64; cou < nextField.size(); ++cou, base /= 2)
		{
			cout << nextField[cou];
			num += (nextField[cou] % 2) * base;
		}
		//выводим символ
		cout << '\t';
		if (isprint(num))
		{
			cout << '=' << '\t' << num;
		}
		else
		{
			cout<< "Спецсимвол #" << (int) num;
		}
		cout << endl;
	}
	//getter'ы и setter'ы
	void setRule(Rule newRule)
	{
		rule = newRule;
	}
	Rule getRule()
	{
		return rule;
	}
	unsigned getLenght()
	{
		return currentField.size();
	}
};

int main()
{
	//выхода нет
	while (true)
	{
		//правило перехода состояний
		Rule rule;
		//символ->1 байт->8 бит, но 1 бит под знак
		Field field(7, rule);
		const unsigned long long start = clock();
		//выводим 256 поколений
		for (int i = 1; i < 257; ++i)
		{
			field();
			cout << setw(3) << i;
			cout << ')' << ' ';
			field.show();
		}
		const unsigned long long end = clock();
		unsigned short dif = end - start;
		cout<<endl<<"Кодирование выполнено за "<<dif<<"тик. (или ~"<<((float)dif)/CLOCKS_PER_SEC<<"сек.)"<<endl<<endl;
	}
}