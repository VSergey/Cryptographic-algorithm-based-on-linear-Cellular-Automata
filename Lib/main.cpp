//Узнаём ключ по исходному тексту и шифротексту
#include "try1/Field.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;
typedef unsigned long long ull;

int main()
{
	// создаём случайные данные
	/*
		number1 - ключ
		number2 - количество состояний
		lenght - длинна строки
		plain - открытый текст
		cipher - шифротекст
	*/
	srand(time(0));
	unsigned short number1 = rand() % 256;
	unsigned short number2 = rand() % 100;
	unsigned short length = rand() % 9 + 1;
	vector<unsigned short>plain;
	//заполняем строку печатаемыми символами
	for (unsigned short i = 0; i < length; ++i)
		plain.push_back(rand() % 94 + 33);
	vector<unsigned short> cipher;
	//шифруем исходную строку
	for (unsigned short i = 0; i < length; ++i)
	{
		Crypto::Field temp(number1, plain[i]);
		for (unsigned short j = 0; j < number2 - 1; ++j)
			temp.encrypt();
		cipher.push_back(temp.encrypt());
	}
	cout << "Верный результат " << number1 << endl;
	
	// начинаем взлом
	ull start = clock();
	//вектор возможных значений ключа для каждого символа
	vector < vector <unsigned short> >maybe;
	maybe.resize(length);
	//перебираем все возможные ключи для кажого символа
	for (unsigned short i=0; i<length; ++i)
	{
		for (unsigned short ruleNumber=0; ruleNumber<256; ++ruleNumber)
		{
			Crypto::Field chance(ruleNumber, plain[i]);
			//неизвестно сколько поколений, но они зацикливаются, поэтому считаем 100
			for (unsigned short j=0; j<100; ++j)
			{
				unsigned short a = chance.encrypt();
				if (a==cipher[i])
				{
					//заносим
					maybe[i].push_back(ruleNumber);
					break;
				}
			}
		}
	}
	ull end = clock();
	cout << "Вычислено за " << end - start << " тик." << endl;
	//выводим возможные
	for (unsigned short i = 0; i < length; ++i)
	{
		cout<<i+1<<')';
		for (unsigned short j = 0; j < maybe[i].size(); ++j)
			cout<<maybe[i][j]<<' ';
		cout<<'\n';
	}
}
/*
Проверка
------------------------
Начальное состояние: 
00000000000000000000000000000001
------------------------
Окрестность->состояние (правило 110):
111 0
110 1
101 1
100 0
011 1
010 1
001 1
000 0
------------------------
Первое поколение:
00000000000000000000000000000011
+++++++++++++++++++
Или:
1->3
*/