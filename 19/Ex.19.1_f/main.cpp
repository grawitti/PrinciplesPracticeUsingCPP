/*
    Date: 24.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 1
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T> 
vector<T> f(vector<T> v1, vector<T> v2) {
	if(v1.size() < 1 || v1.size()!=v2.size()) error("Vector size error.",v1.size());
	for(int i = 0; i<v1.size(); ++i) v1[i]+=v2[i];
	return v1;
}

int main()
{
	try
	{	
		vector<int> vi_1 {1,1,1};
		vector<int> vi_2 {3,3,3};
		vector<int> vi_12 = f(vi_1,vi_2);

		for(int i : vi_12) cout << i << ' ';
		cout << endl;

		vector<string> vs_1 {"1","1","1"};
		vector<string> vs_2 {"3","3","3"};
		vector<string> vs_12 = f(vs_1,vs_2);

		for(string s : vs_12) cout << s << ' ';
		cout << endl;	

		vector<double> vd_1 {1.1,1.1,1.1};
		vector<double> vd_2 {3.3,3.3,3.3};
		vector<double> vd_12 = f(vd_1,vd_2);

		for(double d : vd_12) cout << d << ' ';
		cout << endl;	
		
		vector<char> vc_1 {'1','1','1'};
		vector<char> vc_2 {'3','3','3'};
		vector<char> vc_12 = f(vc_1,vc_2);

		for(char c : vc_12) cout << c << ' ';
		cout << endl;

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