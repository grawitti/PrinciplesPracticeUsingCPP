/*
    Date: 22.11.18
    Author: Grawitti
	Description: 
    Chapter 27 – Principles and Practice Using C++   
	Task 3
*/
#include <stdlib.h>
#include <stdio.h>

void f(char* p, int x)
{
	printf("p is %s and x is %i\n",p,x);
}

int main()
{
	f("foo",7);
	f("abc",2);
	f("EFG",3);

	return 0;
}
