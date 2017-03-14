// Небольшой тест
#include "try1/Field.hpp"
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
typedef unsigned long long ull;

int main()
{
	// создаём случайные данные
	srand(time(0));
	unsigned short number1 = rand() % 256;
	unsigned short number2 = rand() % 100;
	unsigned short length = rand() % 10;
	vector<unsigned short>plain;
	for (unsigned short i = 0; i < length; ++i)
		plain.push_back(rand() % 88 + 40);
	vector<unsigned short> cipher;
	for (unsigned short i = 0; i < length; ++i)
	{
		Crypto::Field temp(number1, plain[i]);
		for (unsigned short j = 0; j < number2 - 1; ++j)
			temp.encrypt();
		cipher.push_back(temp.encrypt());
	}
	cout << number1 << endl <<  number2 << endl;
	
	// начинаем взлом
	ull start = clock();
	vector < unsigned short >maybe;
	for (unsigned short i=0; i<length; ++i)
	{
		for (unsigned short ruleNumber=0; ruleNumber<256; ++ruleNumber)
		{
			Crypto::Field chance(ruleNumber, plain[i]);
			for (unsigned short j=0; j<100; ++j)
			{
				unsigned short a = chance.encrypt();
				if (a==cipher[i])
				{
					maybe.push_back(ruleNumber);
					cout<<i<<')'<<a<<'='<<cipher[i]<<' '<<ruleNumber<<' '<<j<<endl;
				}
			}
		}
	}
	ull end = clock();
	cout << "Вычислено за " << end - start << " тик." << endl;
}