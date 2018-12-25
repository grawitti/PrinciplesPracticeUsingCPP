/*
    Date: 25.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 3
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T, typename A>
class Pair {
	public:
	Pair(T tt, A aa) : t(tt), a(aa) {}
	T t;
	A a;
};

int main()
{
	try
	{
		vector<Pair<int,char>> vp;

		char c;
		int i = 0;
		cout << "Enter Pair - int and char:";
		while(c!='.') {
			cin >> i >> c;
			if(!cin) error("Data format");
			vp.push_back({i,c});
		}

		for(Pair<int,char> p : vp) cout << p.t << ", " << p.a << endl;


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