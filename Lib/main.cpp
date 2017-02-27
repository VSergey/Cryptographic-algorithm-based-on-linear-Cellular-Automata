//Небольшой тест
#include <Field.hpp>
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i<256; ++i)
	{
		cout<<(int)Field(110, i)()<<endl;
	}
}