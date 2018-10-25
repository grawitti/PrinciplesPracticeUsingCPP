/**
 Дата создания: 19.01.18
 Автор: Руслан
 Назначение: Класс Date (Календарь), версия из раздела 9.7.4. today = 19 мая 1963 года,
 tomorrow = today+1. Вывод в поток cout today и tomorrow. Файл используется для заданий 9 гл.
 Глава 9, зад. 5, стр. 387, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year {
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) :y{x} {if (x<min || max<=x) throw Invalid{}; }
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

int main() {
	try {
		cout << "Класс Date (Календарь), версия из раздела 9.7.4. today = 19 мая 1963 года, "
			<< "tomorrow = today+1.\n";

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



