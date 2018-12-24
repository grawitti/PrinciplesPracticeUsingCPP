/*
    Date: 21.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Task - 1-10
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T> 
struct S {
	public:
		S(T v) :val(v) {}
		T& get();
		const T& get() const;
		T& operator=(const T& v);
	private:
		T val;
};

template<typename T> 
T& S<T>::get() { return val; }

template<typename T> 
const T& S<T>::get() const { return val; }

template<typename T> 
T& S<T>::operator=(const T& v) {
	if(this==&v) return *this;
	val = v.val;
	return *this;
}

template<typename T> 
void read_val(T& v) {
	cin >> v;
	if(!cin) error("Data format.");
}

template<typename T>
ostream& operator << (ostream &os, const vector<T>& v) 
{
	os << '{';
	for(int i = 0; i<v.size(); ++i) {
		os << v[i];
		if (i<v.size()-1) os << ',';
	}
	return os << '}';
}

template<typename T>
istream& operator >> (istream &is, vector<T>& vt) 
{
	char ch1, ch2;
	T temp;
	vector<T> v_temp;
	is >> ch1;
	if(!is) return is;
	if(ch1!='{') {
		is.clear(ios_base::failbit);
		return is;
	}
	while (is>>temp>>ch2 && ch2== ',') {
		v_temp.push_back(temp);
	}
	if(ch2!='}') {
		is.clear(ios_base::failbit);
		return is;
	}
	v_temp.push_back(temp);
	vt = v_temp;
	return is;
}

int main()
{
	try
	{	
		/*
		int i;
		read_val(i);
		S<int> si{i};

		char c;
		read_val(c);
		S<char> sc{c};

		double d;
		read_val(d);
		S<double> sd{d};

		string s;
		read_val(s);
		S<string> ss{s};

		S<vector<int>> svi{{1,2,3}};

		cout << si.get() << endl
			<< sc.get() << endl
			<< sd.get() << endl
			<< ss.get() << endl;

		for(int i : svi.get()) cout << i << ' ';
		cout << endl;

		S<int> si2{0};
		si = si2;

		cout << si.get() << endl
			<< sc.get() << endl
			<< sd.get() << endl
			<< ss.get() << endl;
		*/

		vector<char> vc;
		// cin >> vc;
		read_val(vc);
		cout << vc << endl;

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