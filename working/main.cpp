/*
    Date: 11.01.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 7
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T>
class Number
{
  public:
	Number(){}
	Number(T i) : value(i) {}

	friend Number operator+(Number& n1, Number& n2) { return n1.value+n2.value; }
	//const Number& operator-(const Number& n) { return this->value-n.value; }
	//const Number& operator*(const Number& n) { return this->value*n.value; }
	friend Number operator-(Number& n1, Number& n2) { return n1.value-n2.value; }
	friend Number operator*(Number& n1, Number& n2) { return n1.value*n2.value; }
	friend Number operator%(Number& n1, Number& n2) { return n1.value%n2.value; }
	friend ostream& operator<<(ostream& os, const Number& n){
		return os << n.value;
	}
	friend istream& operator>>(istream& is, Number& n){
		is >> n.value;
		return is; 
	}
	T value;
  private:
};

template <typename T, typename U>
T sum_of_mult(vector<Number<T>> &vt, vector<Number<U>> &vu) {	
	if(vt.size()<0 || vt.size()!=vu.size()) error("Size of vectors.");
	double result = 0;
	if(sizeof(T)>1 && sizeof(U)>1 && sizeof(T)!=24 && sizeof(U)!=24) {
		for(int i=0; i<vt.size(); i++) {
			result+=static_cast<double>(vt[i].value)*static_cast<double>(vu[i].value);
		}
	}
	return static_cast<T>(result);
}

int main()
{
	try
	{
		Number<double> a{0};
		Number<double> b{0};
		cout << "Введите a: ";
		cin >> a;
		if(!cin) error("Data format");

		cout << "Введите b: ";
		cin >> b;
		if(!cin) error("Data format");

		cout << "a+b=" << a+b << endl;
		cout << "a-b=" << a-b << endl;
		cout << "a*b=" << a*b << endl;

		vector<Number<double>> vnd;
		vnd.push_back(a);
		vnd.push_back(b);

		Number<int> c;
		Number<int> d;

		cout << "Введите c: ";
		cin >> c;
		if(!cin) error("Data format");

		cout << "Введите d: ";
		cin >> d;
		if(!cin) error("Data format");

		vector<Number<int>> vni;
		vni.push_back(c);
		vni.push_back(d);

		double dd = sum_of_mult(vnd,vni);
		cout << dd << endl;

		cout << "c\%d=" << c%d << endl;
		//cout << "a\%d=" << a%d << endl;

		keep_window_open();
		return 0;
	}
	catch (const exception &e)
	{
		cerr << "Exception: " << e.what() << ";\n";
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
