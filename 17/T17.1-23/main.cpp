/*
     Date: 09.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Task 1-23
*/

#include "../../std_lib_facilities.h"

using namespace std;

// Print (n) elements of array (a) to stream (os) 
void print_array(ostream& os, int* a, int n)
{
	os << a << endl;
	for (int i = 0; i < n; ++i) os << a[i] << endl;
}

// To print vector<int> (vi) to stream (os)
void print_vector(ostream& os, const vector<int>& vi)
{
	for (int x : vi) os << x << endl;
}

int main()
{
    try
    {
		// Path 1
		int n = 20;
		int k = 100;

		int* pi = new int[n];
		for(int i = 0; i < n; ++i) pi[i]=k+i;

		cout << "Print array of int:\n";
		print_array(cout, pi, n);
		delete[] pi;

		vector<int> vi;
		for(int i = 0; i<n; ++i) vi.push_back(k+i);

		cout << "Print vector<int> vi:\n";
		print_vector(cout,vi);

		// Path 2
		int* p1 = new int(7);
		cout << "p1: " << p1 << ", *p1: " << *p1 << endl;

		n = 7;
		k = 2;
		int* p2 = new int[n];
		for(int i = 0; i < n; ++i) p2[i]=pow(k,i);
		cout << "To print array p2:\n";
		print_array(cout,p2,n);

		int* p3 = p2;
		p2 = p1;
		p3 = p2;
		cout << "p1: " << p1 << ", " << *p1 << endl
			<< "p2: " << p2 << ", " << *p2 << endl;

		delete[] p2;

		n = 10;
		int* p4 = new int[n];
		for(int i = 0; i < n; ++i) p4[i]=pow(k,i);
		print_array(cout,p4,n);

		int* p5 = new int[n];
		for(int i = 0; i<n; ++i) p5[i] = p4[i];
		print_array(cout,p5,n);

		// 10-12 vector
		vector<int> vi2;
		for(int i = 0; i<n; ++i) vi2.push_back(pow(k,i));
		print_vector(cout,vi2);

		vector<int> vi3(n);
		for (int i=0; i<n; ++i) vi3[i]=vi2[i]; 
		print_vector(cout,vi3);

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
