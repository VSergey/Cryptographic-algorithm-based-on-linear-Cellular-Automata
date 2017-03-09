//Небольшой тест
#include <Field.hpp>
#include <iostream>
using namespace std;

int main()
{
	for (unsigned short i = 65; i<91; ++i)
	{
		Crypto::Field col_test(110, i);
		cout<<(char)i<<" = "<<col_test.encrypt()<<'\n';
	}
	for (unsigned short i = 97; i<123; ++i)
	{
		Crypto::Field col_test(110, i);
		cout<<(char)i<<" = "<<col_test.encrypt()<<'\n';
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