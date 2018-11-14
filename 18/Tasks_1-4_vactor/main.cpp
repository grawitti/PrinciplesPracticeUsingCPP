/*
     Date: 14.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Task 1-4 vectors
*/

#include "../../std_lib_facilities.h"

using namespace std;

vector<int> gv {1,2,4,8,16,32,64,128,256,512};

void f(vector<int> vi)
{
	vector<int>  lv(vi.size());
	for(int i=0; i<gv.size(); ++i)
	{
		lv[i] = gv[i];
		cout << lv[i] << endl;
	}
	vector<int> lv2 = vi;
	for(int i : lv2) cout << i << endl;
}

// Возвращает факториал целого числа - n
int fac(int n)
{
    return n>1 ? n*fac(n-1) : 1;
}

int main()
{
    try
    {
		f(gv);

		vector<int> vv;
		for(int i=0; i<10; ++i) vv.push_back(fac(i));
		f(vv);

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
