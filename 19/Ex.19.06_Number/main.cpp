/*
    Date: 26.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 6
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T>
class Number
{
  public:
	Number(){}
	Number(T i) : value(i) {}

	const Number& operator+(const Number& n) { return this->value+n.value; }
	const Number& operator-(const Number& n) { return this->value-n.value; }
	const Number& operator*(const Number& n) { return this->value*n.value; }
	friend ostream& operator<<(ostream& os, const Number& n){
		return os << n.value;
	}
	friend istream& operator>>(istream& is, Number& n){
		is >> n.value;
		return is; 
	}
  private:
	T value;
};

int
main()
{
	try
	{
		Number<int> a{0};
		Number<int> b{0};
		cout << "Введите a: ";
		cin >> a;
		if(!cin) error("Data format");

		cout << "Введите b: ";
		cin >> b;
		if(!cin) error("Data format");

		cout << "a+b=" << a+b << endl;
		cout << "a-b=" << a-b << endl;
		cout << "a*b=" << a*b << endl;

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