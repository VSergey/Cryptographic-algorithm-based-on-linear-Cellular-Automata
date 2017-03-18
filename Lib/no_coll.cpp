#include <iostream>
#include <vector>
#include <set>
#include "try2/Field.hpp"
using namespace std;
/* 
   Правила с отсутствием коллизий: 169 286 */

int main()
{
	bool flag = true;
	for (int j = 0; j < 256; ++j)
	{
		set < unsigned >a;
		cout<<'\n'<<j;
		for (int i = 0; i < 65535; ++i)
		{
			Crypto::Field test(j, i);
			if (!a.insert(test.encrypt()).second)
			{
				cout<<'\t'<<i;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout<<'\n'<<j;
		}
		flag=true;
	}
}