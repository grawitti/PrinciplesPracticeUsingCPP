/**
 Дата создания: 19.01.18
 Автор: Руслан
 Назначение: Класс Date (Календарь), версия из раздела 9.4.1. today = 19 мая 1963 года,
 tomorrow = today+1. Вывод в поток cout today и tomorrow.
 Глава 9, зад. 1, стр. 387, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "Класс Date (Календарь), версия из раздела 9.4.1. today = 19 мая 1963 года, "
	     << "tomorrow = today+1.\n";
}

// Простая структура Date
struct Date {
	int y = 1985; // год
	int m = 7; // месяц
	int d = 13; // день
	void init_day (Date& dd, int y, int m, int d); // проверка является ли y,m,d правльной датой
	void add_day(Date& dd, int n); // увеличивает объект dd на n дней
	friend ostream& operator<<(ostream& os, const Date& dd);
};

void Date::init_day (Date& dd, int y, int m, int d) {
	if ((2200 > y && y > 1500) && (m > 0 && m <= 12) && (d > 0 && d <= 31)) {
		dd.y = y;
		dd.m = m;
		dd.d = d;
	}
}

void Date::add_day(Date& dd, int n) {
		dd.d = (dd.d + n > 31)? (dd.d+n)-31: dd.d = dd.d+n;
}

ostream& operator<<(ostream& os, const Date& dd) {
	if (dd.m < 10) {
		return os << dd.d
						<< ".0" << dd.m
						<< '.' << dd.y << " г.";
	} else return os << dd.d
						<< '.' << dd.m
						<< '.' << dd.y << " г.";
}

int main() {
	try {
		welcomeMessage();
		Date today{};
		today.init_day(today,2017,-11,5);
		Date tomorrow = today;
		tomorrow.add_day(tomorrow,1);
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
