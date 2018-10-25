/**
 Дата создания: 06.03.18
 Автор: Руслан
 Назначение: Класс Date (Календарь), версия из раздела 9.7.1. today = 19 мая 1963 года,
 tomorrow = today+1. Вывод в поток cout today и tomorrow.
 Глава 9, зад. 4, стр. 387, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"


	//Приветствие
void welcomeMessage () {
	cout << "Класс Date (Календарь), версия из раздела 9.7.1. today = 19 мая 1963 года, "
	     << "tomorrow = today+1.\n";
}

enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year {
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) :y{x} {if (x<min || max<=x) throw Invalid{}; }
	int year() { return y; }
private:
	int y;
};

class Date {
public:
	Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} { }
	void add_day(int n);
	friend ostream& operator<<(ostream& os, const Date& dd);
	Year year() { return y; }
	Month month() { return m; }
	int day() { return d; }
private:
	Year y{Year{1985}};
	Month m{Month::jun};
	int d{13};
};

void Date::add_day(int n) {
		d = (d+n > 31) ?(d+n)-31 :d = d+n;
}

ostream& operator<<(ostream& os, Date& d) {
	return os << d.day()
						<< '.' << int(d.month());
						// << '.' << d.year() << " г.";
}

int main() {
	try {
		welcomeMessage();
		Date today{Year{1963},Month::may,33};
		Date tomorrow = today;
		tomorrow.add_day(1);
		cout << "today: "<< today << "\ntomorrow: " << tomorrow << endl;
	}
		catch (exception& e) {
			cerr << "\nОшибка: " << e.what() << endl;
			return 1;
		}
		catch (...) {
			cerr << "\nНеизвестное исключение!\n";
			return 2;
		}
}



