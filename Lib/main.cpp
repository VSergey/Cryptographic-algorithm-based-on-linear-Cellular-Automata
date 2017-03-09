//Небольшой тест 
#include <Field_as_array.hpp>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	
	unsigned long long start=clock();
	Crypto::Field col_test(110, 123);
	cout<<col_test.encrypt()<<endl;
	unsigned long long end=clock();
	cout<<end-start<<"тик.";
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