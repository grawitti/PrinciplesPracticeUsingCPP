/*
    Date: 24.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 2
*/

#include "../../std_lib_facilities.h"

using namespace std;

template <typename T, typename U>
T sum_of_mult(const vector<T> &vt, const vector<U> &vu) {	
	if(vt.size<0 || vt.size()!=vu.size()) error("Size of vectors.");
	T result=0;
	for(int i=0; i<vt.size(); ++i) { result+=vt[i]*vu[i]; }
	return result;
}

int main()
{
	try
	{
		vector<int> vi_1{1, 1, 1};
		vector<int> vi_2{3, 3, 3};
		cout << sum_of_mult(vi_1, vi_2);

		vector<string> vs_1{"1", "1", "1"};
		vector<string> vs_2{"3", "3", "3"};
		cout << sum_of_mult(vs_1, vs_2);

		vector<double> vd_1{1.1, 1.1, 1.1};
		vector<double> vd_2{3.3, 3.3, 3.3};
		cout << sum_of_mult(vd_1, vd_2);

		vector<char> vc_1{'1', '1', '1'};
		vector<char> vc_2{'3', '3', '3'};
		cout << sum_of_mult(vc_1, vc_2);

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