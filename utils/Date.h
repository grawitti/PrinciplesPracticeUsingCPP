#include "../std_lib_facilities.h"

// DATE
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

Month inToMonth(const int& i);

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

Date inputDate();
// DATE END 