#include <iostream>
#include <iomanip>
#include "../../try2/Field.hpp"
using namespace std;
/*
Правила без коллизий:
15
51
85
105
150
170
204
240
*/
void demo_rule(unsigned short rule)
{
	cout<<rule<<'\n';
	for (int i=33; i<127; ++i)
		cout<<'\t'<<setw(3)<<i<<' '<<setw(5)<<Crypto::Field(rule, i).encrypt()<<endl;
}
int main()
{
	demo_rule(15); //не нашёл упрощения
	demo_rule(51); //вычитает из 65535 само число
	demo_rule(85); //вычитает из 65535 удвоенное число
	demo_rule(105); //не нашёл упрощения
	demo_rule(150); //не нашёл упрощения
	demo_rule(170); //передвигает биты на шаг назад (делит на 2)
	demo_rule(204); //оставляет всё, как есть
	demo_rule(240); //передвигает биты на шаг вперёд (умножает на 2)
}