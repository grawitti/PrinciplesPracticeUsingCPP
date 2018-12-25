/*
    Date: 25.12.18
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

	const T& operator+(const T& i) { return this->value+i.value; }
	const T& operator-(const T& i) { return this->value-i.value; }
	const T& operator*(const T& i) { return this->value*i.value; }
	friend ostream& operator<<(ostream& os, const T& i){
		return os << i.value;
	}
	friend istream& operator>>(istream& is, T& i){
		return is >> i.value;
	}
  private:
	T value;
};

int
main()
{
	try
	{
		Number<int> a;
		Number<int> b;
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