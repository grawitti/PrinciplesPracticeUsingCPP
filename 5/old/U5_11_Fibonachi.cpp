#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include"std_lib_facilities.h"
using namespace std;
/*
Программа создания и печати последовательности Фибоначи: 1 1 2 3 5 8 13 21 34 ...
*/

int main ()
{
	try	{
		vector<int> fibonachi = {1, 1};
		for (int i = 0; i < 46 ; i++) {
			if (i > 1) fibonachi.push_back(fibonachi[i-2] + fibonachi[i-1]);
		}
		for (int x : fibonachi) cout << x << ' ';
	}
	catch (runtime_error& e)
	{
		cout << e.what() << '\n';
	}
}
