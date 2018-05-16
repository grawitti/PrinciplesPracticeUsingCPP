#include <iostream>
#include <vector>
#include "../std_lib_facilities.h"

using namespace std;
const int NULLYEAR = 1970;
const vector<int> fullMounthDays {31,59,90,120,151,181,212,243,273,304,334,365};
const double DAYSINYEAR = 365.25;

int yearToDays (const int& year) 
{
	return (year - NULLYEAR)*DAYSINYEAR;
}

int mounthToDays (const int& m)
{
	if (m < 1 || m > 12) error("Месяц не может быть меньше 1 и больше 12.");
	if (m == 1) return 0;
	if (m == 2) return fullMounthDays[0];
	if (m > 2) {
		return fullMounthDays[m-2];
	}
}

int dateToDays(const int& year, const int& mounth, const int& day) {
	return yearToDays(year)+mounthToDays(mounth)+day;
}

int daysToYear (const int& d) 
{
	return NULLYEAR+d/DAYSINYEAR;
}

int daysToMounth(const int& d) {
	int temp = d/DAYSINYEAR;
	temp = d - temp*DAYSINYEAR;
	if (temp <= fullMounthDays[0]) return 1;
	for (int i = 0; i < fullMounthDays.size(); ++i) {
		if (temp > fullMounthDays[i] && temp <= fullMounthDays[i+1]) return i+2;
	}
}

int daysToDay (const int& d) {
	return d - (yearToDays(daysToYear(d))+mounthToDays(daysToMounth(d)));
}

int main()
{
	int d,y,m,day;
	y = 2017;
	m = 2;
	day = 31;
	cout << day << '.' << m << '.' << y << endl;
	
	d = dateToDays(y,m,day);
	cout << "d = " << d << endl;

	int yy,mm,dd;
	yy = daysToYear(d);
	cout << "yy = " << yy << endl;
		
	mm = daysToMounth(d);
	cout << "mm = " << mm << endl;
	
	dd = daysToDay(d);
	cout << "dd = " << dd << endl;

	keep_window_open();
}
