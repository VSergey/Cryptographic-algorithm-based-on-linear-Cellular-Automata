//Небольшой тест
#include <Field.hpp>
#include <iostream>
#include <locale>
#include <cstdio>
using namespace std;

int main()
{

	Crypto::Field test(110, 'L');
	wchar_t l=test.encrypt();
	wcout<<(wchar_t)test.encrypt()<<endl;
	wprintf(&l);
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