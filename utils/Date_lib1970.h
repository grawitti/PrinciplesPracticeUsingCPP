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

// Проверка условий год
bool isYear(const int& y) {
	static const int MIN = 1; // Минималльное и максимальное значение для года
	static const int MAX = 3000;
	if (y >= MIN && y <= MAX) return true;
	else return false;
}
// Проверка на месяц
bool isMonth(const int& m) {
	if (m >= 1 && m <= 12) return true; // 12 месяцев в году
	else return false;
}

bool leapyear(const int& y);

// Возвращает количество дней в месяце
int daysInMonth(const int& y, const int& m, const int& d){
	if (d<=0) throw(1);
	int days = 31;
	switch (m) {
		case 2:
			days = (leapyear(y))?29:28;
			break;
		case 4: case 6: case 9: case 11: 
			days = 30;
			break;
		default:
			break;
	}
	return days;
}

// Провкрка на коррекнтный день
bool isDay (const int& y, const int& m, const int& d){
	if (d<=0) return false;
	int days = daysInMonth(y,m,d);
	if (days<d) return false;
	return true;
}

// Проверка на корректность даты
bool isDate(const int& y, const int& m, const int& d) {
	if (!(isYear(y))) return false;
	if (!(isMonth(m))) return false;
	if (!(isDay(y,m,d))) return false;
	return true;
}

// Недель в году. В Григорианском и Юлианском календарях 52 недели в году, не зависимо от типа года
int weekOfYear (const int& y) {
	return 365/7;
}

const int NULLYEAR = 1970;
const vector<int> fullMounthDays {31,59,90,120,151,181,212,243,273,304,334,365};
const double DAYSINYEAR = 365.25;

int yearToDays (const int& year) 
{
	return (year - NULLYEAR)*DAYSINYEAR;
}

int mounthToDays (const int& m)
{
	if (m < 1 || m > 12) throw(1);
	if (m == 1) return 0;
	if (m == 2) return fullMounthDays[0];
	if (m > 2) {
		return fullMounthDays[m-2];
	}
}

int dateToDays(const int& year, const int& mounth, const int& day) 
{
	return yearToDays(year)+mounthToDays(mounth)+day;
}


class Date {
public:
	Date(int dd) :d{dd} {	}
	Date();
	int getDays() const { return d; }
	friend ostream& operator<<(ostream& os, const Date& dd);
	friend bool operator==(const Date& d1, const Date& d2); 
private:
	int d{1};
};

int year (const Date& d) 
{
	return NULLYEAR+d.getDays()/DAYSINYEAR;
}

int month(const Date& d) {
	int temp = d.getDays()/DAYSINYEAR;
	temp = d.getDays() - temp*DAYSINYEAR;
	if (temp <= fullMounthDays[0]) return 1;
	for (int i = 0; i < fullMounthDays.size(); ++i) {
		if (temp > fullMounthDays[i] && temp <= fullMounthDays[i+1]) return i+2;
	}
}

int day (const Date& d) {
	return d.getDays() - (yearToDays(year(d))+mounthToDays(month(d)));
}

// Перегрузка оператора <<
ostream& operator<<(ostream& os, const Date& d) {
	return os << day(d)
			<< '.' << month(d)
			<< '.' << year(d) << " г.";
}

// Перегрузка оператора ==
bool operator==(const Date& d1, const Date& d2) {
	return d1 == d2;
}

// Увеличивает дату Date d на int n деней
Date addDay(const Date& d, const int& n)
{
	return d.getDays()+n;
}

// Если год высокостный, делиться на 4 без отстатка, то возвращает true
bool leapyear(const int& y) {
	if (!(y%4)) return true;
	else return false;
}

// Возвращает введеную дату
Date inputDate() {
	cout << "Введите год:" << endl;
	int year = getIntFromCin();
	cout << "Введите месяц:" << endl;
	int month = getIntFromCin();
	cout << "Введите день:" << endl;
	int day = getIntFromCin();
	return {dateToDays(year,month,day)};
}

// Вычисление дня недели по дате: день недели = (день + код месяца + код года) % 7
// Код веков для расчета дня недели: 0 век - 6, 1 век - 4, 2 век - 2, 3 век - 0, 4 век - 6,...
int getCodeOfEpoch(const int& y) {
	if (y < 0) return -1; // год не может быть отрицательный
	int epoch = 1;
	if (y >= 100) epoch = y/100; // перевод года в век начиная с 1 века = 100 год
	const vector<int> codesTempl{6,4,2,0};
	vector<int> codes;
	for (int i = 0; i <= epoch; ++i) {
		for (int x : codesTempl) {
			codes.push_back(x);
		}
	}
	return codes[epoch];
}

// Код года: код года = (код века + последние две цифры года + последние две цифры года / 4) % 7
int getCodeOfYear(const int& y) {
	if (y < 0) return -1; // год не может быть отрицательный
	int yy = y%100;
	double result = getCodeOfEpoch(y)+yy+(yy/4.0);
	//cout << "double(" << result << "), int(" << int(result) << ") %7" << endl;
	return int(result)%7;
}

/* Код месяца
	1 — январь, октябрь;
	2 — май;
	3 — август;
	4 — февраль, март, ноябрь;
	5 — июнь;
	6 — декабрь, сентябрь;
	0 — апрель, июль.
*/
int getCodeOfMounth(const int& m) {
	switch (m) {
		case 1: case 10:
			return 1;
		case 5:
			return 2;
		case 8:
			return 3;
		case 2: case 3: case 11:
			return 4;
		case 6:
			return 5;
		case 12: case 9:
			return 6;
		case 4: case 7:
			return 0;
		default:
			cerr << "Ошибка: Месяца номер: " << m << " не существует!";
			return -1;
	}
}

// День недели, возвращает int 0-6, 0 - суббота.
int dayOfWeek (const Date& d) {
	return (day(d) + getCodeOfMounth(month(d)) + getCodeOfYear(year(d))) %7;
}

// Человеческий вывод дня недели 0 - суббота
string getStringDayOfWeek (const int& i) {
	switch (i) {
		case 0:
			return "Суббота";
		case 1:
			return "Воскресенье";
		case 2:
			return "Понедельник";
		case 3:
			return "Вторник";
		case 4:
			return "Среда";
		case 5:
			return "Четверг";
		case 6:
			return "Пятница";
		default:
			return "Ошибка: день может быть: 0 - 6";
	}
}

// Следующий рабочий день. Принимает Date, возвращает Date
Date nextWorkDay(const Date& d) {
	switch (dayOfWeek(d)) {
		case 0:
			return addDay(d,2);
		case 6:
			return addDay(d,3);
		default:
			return addDay(d,1);
	}
}
