/**
 Дата создания: 02.04.18
 Автор: Руслан
 Назначение: Реализация класса Money.
 Глава 9, упр. 14, стр. 390, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
**/

#include "../std_lib_facilities.h"

// Округление если >= 0,5 вверх, <= 0,5 вниз. Например 1,5 == 2 или 3,49 == 3
long rounding (const double& d) 
{
	if (d < 0) 
	{
		double positive = -d;
		if ((positive-int(positive)) >= 0.5) return long(d)-1;
		else return long(d);
	}
	if ((d-int(d)) >= 0.5) return long(d)+1;
	else return long(d);
}

class Money 
{
public:
	long cents () const { return c; }
	friend ostream& operator<< (ostream& os, const Money& m);
	friend istream& operator>> (istream& is, Money& m);
	friend Money operator+ (const Money& m1, const Money& m2);
	friend Money operator- (const Money& m1, const Money& m2);
	friend Money operator* (const Money& m1, const Money& m2);
	friend Money operator/ (const Money& m1, const Money& m2);

	Money () {  }
	Money (long cc) : c{cc} {  }

private:
	long c{0};
};

ostream& operator<< (ostream& os, const Money& m) 
{
	return os << '$' << m.cents()/100.0; // Вывод центов в долларах, в 1 долларе 100 центов
}

istream& operator>> (istream& is, Money& m)
{
	double dollars = -1.0;
	is >> dollars;
	if (!is) return is;
	m = {long(dollars*100)}; // Ввод в долларах, переводим в центы.
	return is;
}

Money operator+ (const Money& m1, const Money& m2)
{
	return {m1.cents() + m2.cents()};
}

Money operator- (const Money& m1, const Money& m2)
{
	double d = ((m1.cents()/100.0) - (m2.cents()/100.0))*100.0;
	return {rounding(d)};
}

Money operator* (const Money& m1, const Money& m2)
{
	double d = ((m1.cents()/100.0) * (m2.cents()/100.0))*100.0;
	return {rounding(d)};
}

Money operator/ (const Money& m1, const Money& m2)
{
	double d = ((m1.cents()/100.0) / (m2.cents()/100.0))*100.0;
	return {rounding(d)};
}

int main() {
	try {

	cout << "Money 9.14\n";

	cout << "Введите первую сумму в долларах: ";
	Money m;
	cin >> m;
	cout << "Введите вторую сумму в долларах: ";
	Money m2;
	cin >> m2;
	cout << "m = " << m << ", m2 = " << m2 << endl;
	cout << "m + m2 = " << m + m2 << endl;
	cout << "m * m2 = " << m * m2 << endl;
	cout << "m / m2 = " << m / m2 << endl;
	cout << "m - m2 = " << m - m2 << endl;
	cout << "1 / 3 = " << 1.0 / 3 << endl;

    keep_window_open();
		
	}
	catch (exception& e) {
		cerr << "\nОшибка: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (int& e) {
		cerr << "\nОшибка: Год, месяц или день введены некорректно." << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "\nНеизвестное исключение!\n";
		keep_window_open();
		return 2;
	}
}
