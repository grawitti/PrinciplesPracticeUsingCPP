/*
    Date: 25.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 5
*/

#include "../../std_lib_facilities.h"

using namespace std;

class Int
{
  public:
	Int(){}
	Int(int i) : value(i) {}

	const Int& operator+(const Int& i) { return this->value+i.value; }
	const Int& operator-(const Int& i) { return this->value-i.value; }
	const Int& operator*(const Int& i) { return this->value*i.value; }
	friend ostream& operator<<(ostream& os, const Int& i){
		return os << i.value;
	}
	friend istream& operator>>(istream& is, Int& i){
		return is >> i.value;
	}
  private:
	int value;
};

int
main()
{
	try
	{
		Int a;
		Int b;
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