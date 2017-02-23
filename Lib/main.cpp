#include <iostream>
#include "Field.cpp"
#include "Rule.cpp"
using namespace std;

int main()
{
	Field f('9', Rule(110));
	cout<<f();
}