/*
    Date: 21.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Task - 1-10
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T> struct S {
	public:
		S(T v) :val(v) {}
		T& get(T& val);
	private:
		T val;
};

template<typename T> T& S::get(T& val) {
	return val;
}

int main()
{
	try
	{	
		S<int> si{12};
		S<char> sc{'c'};
		S<double> sd{2.3};
		S<string> ss{"string"};
		S<vector<int>> svi{{1,2,3}};

		cout << get(si.val) << endl
			<< sc.val << endl
			<< sd.val << endl
			<< ss.val << endl;

		for(int i : svi.val) cout << i << ' ';
		cout << endl;

		cout << get(si.val) << endl;

		return 0;
	}
	catch (const exception &e)
	{
		cerr << "Exception: " << e.what() << '\n';
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