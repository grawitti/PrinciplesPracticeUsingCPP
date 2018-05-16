/**
 Дата создания: 19.01.18
 Автор: Руслан
 Назначение: Класс Date (Календарь), версия из раздела 9.7.4.
**/

#include "../9/Ex9.9/Ex9.9.h"

void Date::add_day(int n) {
		d = (d+n > 31) ?(d+n)-31 :d = d+n;
}

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
		error("Неверно ввели месяц.");
		break;
	}
	error("Неверно ввели месяц.");
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

