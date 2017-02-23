#include <iostream>
#include <Field.h>
#include <Rule.h>
using namespace std;

int main()
{
	Field f('9', Rule(110));
	cout<<f();
}