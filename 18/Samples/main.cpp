/*
     Date: 14.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Examples 18.4.2
*/

#include "../../std_lib_facilities.h"

using namespace std;

struct X {
	int val;

	void out(const string& s, int nv)
	{
		cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
	}
	X() { out("X() ",0); val=0; } // Default constructor
	X(int v) { val=v; out( "X(int) ",v ); }
	X(const X& x) { val=x.val; out("X(X&) ",x.val); } // Copy constructor
	X& operator=(const X& a) // Copy assigning
	{
		out("X::operator=()",a.val);
		val=a.val;
		return *this;
	}
	~X() { out("~X()",0); } // Destructor
};

X glob(2);

X copy(X a) { return a; }

X copy2(X a) { X aa = a;; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) {X a(i); return new X(a); }

struct XX {X a; X b;};

int main()
{
    try
    {
		X loc {4};
		X loc2 {loc};
		loc = X{5};
		loc2 = copy(loc);
		loc2 = copy2(loc);
		X loc3 {6};
		X& r = ref_to(loc);
		delete make(7);
		delete make(8);
		vector<X> v(4);
		XX loc4;
		X* p = new X{9};
		delete p;
		X* pp = new X[5];
		delete[] pp;

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
