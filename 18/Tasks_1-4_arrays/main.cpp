/*
     Date: 14.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Task 1-4 arrays
*/

#include "../../std_lib_facilities.h"

using namespace std;

int ga[] {1,2,4,8,16,32,64,128,256,512};

void f(int a[], int n)
{
	int la[10];
	for(int i=0; i<10; ++i)
	{
		la[i] = ga[i];
		cout << "la[" << i << "]=" << la[i] << endl;;
	}
	int* p = new int[n];
	for(int i=0; i<n; ++i) 
	{
		p[i]=a[i];
		cout << "p[" << i << "]=" << p[i] << endl;
	}
	delete[] p;
}

int main()
{
    try
    {
		int n = 10;
		int a[10] {0,1,2,3};
		f(a,n);

		return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
		keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception!" << '\n';
		keep_window_open();
        return 2;
    }
}
