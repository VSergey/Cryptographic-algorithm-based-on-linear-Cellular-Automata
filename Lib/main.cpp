//Небольшой тест
#include <Field>
#include <ncurses.h>
#include <iostream>
using namespace std;

int main()
{
	for (unsigned short i = 0; i<65535; ++i)
	{
		Field unicode_test(110, i);
		cout<<unicode_test()<<'\n';
	}
}
/*
Проверка

Начальное состояние: 
00000000000000000000000000000001

Окрестность->состояние (правило 110):
111 0
110 1
101 1
100 0
011 1
010 1
001 1
000 0

Первое поколение:
00000000000000000000000000000011

Или:
1->3
*/