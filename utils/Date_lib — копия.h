#include<iostream>
//#include<iomanip>
//#include<fstream>
#include<sstream>
//#include<cmath>
//#include<cstdlib>
#include<string>
//#include<list>
//#include <forward_list>
#include<vector>
//#include<unordered_map>
//#include<algorithm>
//#include <array>
//#include <regex>
//#include<random>
//#include<stdexcept>
#include "io_lib.h"

using namespace std;

enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year {
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) :y{x} {if (x<min || max<=x) throw Invalid{}; }
	//Year();
	int year() const { return y; }
	friend bool operator== (const Year& y1, const Year& y2);
private:
	int y;
};

class Date {
public:
	Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} { }
	Date();
	void add_day(int n);
	friend ostream& operator<<(ostream& os, const Date& dd);
	Year year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }
private:
	Year y{Year{1985}};
	Month m{Month::jun};
	int d{13};
};

// Увеличивает дату на 1 день
void Date::add_day(int n) {
		d = (d+n > 31) ?(d+n)-31 :d = d+n;
}

// Перегрузка оператора <<
ostream& operator<<(ostream& os, const Date& d) {
	Year y{d.year()};
	int yy = y.year();
	return os << d.day()
						<< '.' << int(d.month())
						 << '.' << yy << " г.";
}

// Перегрузка оператора ==
bool operator==(const Year& y1, const Year& y2) {
	return y1.year() == y2.year();
}

// Если год высокостный, делиться на 4 без отстатка, то возвращает true
bool leapyear(const Date& d) {
	cout << "ГОД:" << Year{d.year()}.year() << endl;
	if (!(Year{d.year()}.year()%4)) return true;
	else return false;
}
// int to Month
Month inToMonth(const int& i) {
	switch(i) {
		case 1:
			return Month::jan;
		case 2:
			return Month::feb;
		case 3:
			return Month::mar;
		case 4:
			return Month::apr;
		case 5:
			return Month::may;
		case 6:
			return Month::jun;
		case 7:
			return Month::jul;
		case 8:
			return Month::aug;
		case 9:
			return Month::sep;
		case 10:
			return Month::oct;
		case 11:
			return Month::nov;
		case 12:
			return Month::dec;
		default:
		cerr << "Неверно ввели месяц.\n";
		break;
	}
	exit(1);
}

// Возвращает введеную дату
Date inputDate() {
	cout << "Введите год:" << endl;
	int year = getIntFromCin();
	cout << "Введите месяц:" << endl;
	Month month = inToMonth(getIntFromCin());
	cout << "Введите день:" << endl;
	int day = getIntFromCin();
	return {Year{year},month,day};
}

