/**
 Дата создания: 26.03.18
 Автор: Руслан
 Назначение: Реализация класса Rational.
 Глава 9, упр. 13, стр. 390, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
**/

#include "../std_lib_facilities.h"

// Наибольший общий делитель
int calcNOD(int m, int n)
{
	if (m < 0 || n < 0) 
	{
		m = -m;
		n = -n;
	}
	if (m == n)  return m;
	int d = m - n;
	int div;
	if (d < 0)
	{
		d = -d; 
		div = calcNOD(m, d);
	} else div = calcNOD(n, d); 
		return div;
}

// Наименьшее общее кратное
int calcNOK(int m, int n) 
{ 
  return m*n / calcNOD(m, n); // НОК = m*n / НОД(m,n) 
}

class Rational 
{
public:
	int numerator() const { return n; }
	int cognizant() const { return c; }
	double getDouble() const { return double(n)/double(c); }

	Rational() {}
	Rational(int nn) : n{nn} {  }
	Rational(int nn, int cc) : n{nn}, c{cc} {  }

	friend ostream&	operator<<(ostream& os, const Rational& r);
	friend Rational	operator+(const Rational& r1, const Rational& r2);
	friend Rational	operator-(const Rational& r1, const Rational& r2);
	friend Rational	operator*(const Rational& r1, const Rational& r2);
	friend Rational	operator/(const Rational& r1, const Rational& r2);
	friend bool	operator==(const Rational& r1, const Rational& r2);

private:
	int n{1}; // числиель 1/
	int c{1}; // знаминатель /1
};

ostream& operator<<(ostream& os, const Rational& r) 
{
	return os << r.numerator() << '/'
			<< r.cognizant() << ' ';
}

// Сокращение рациональных чисел
Rational reduction (const Rational& r) {
	if (calcNOD(r.numerator(),r.cognizant()) > 1)
	{
		Rational red{r};
		return {red.numerator()/calcNOD(red.numerator(),red.cognizant()),red.cognizant()/calcNOD(red.numerator(),red.cognizant())};
	}
	return r;
}

// Сложение рациональных чисел a/c + b/c = a+b/c ,a/b + c/d = a*(НОК(b,d)/b)+с(НОК(b,d)/d)/НОК(b,d)
/*Rational operator+(const Rational& r1, const Rational& r2)
{
	Rational rr1 = reduction(r1);
	Rational rr2 = reduction(r2);
	Rational result;
	if (rr1.cognizant() == rr2.cognizant())
	{
		result = {rr1.numerator()+rr2.numerator(),rr1.cognizant()};
		return reduction(result);
	}
	else 
	{
		int NOK = calcNOK(rr1.cognizant(),rr2.cognizant());
		result = {rr1.numerator()*(NOK/rr1.cognizant())+rr2.numerator()*(NOK/rr2.cognizant()),NOK};
		return reduction(result);
	}
}
*/

Rational operator+(const Rational& r1, const Rational& r2)
{
	if (r1.cognizant() == r2.cognizant()) return reduction({r1.numerator()+r2.numerator(),r1.cognizant()});
	else
	{
		int NOK = calcNOK(r1.cognizant(),r2.cognizant());
		return reduction({r1.numerator()*(NOK/r1.cognizant())+r2.numerator()*(NOK/r2.cognizant()),NOK});
	}
}

// Вычитание рациональных чисел, тоже что и сложение только со знаком -
Rational operator-(const Rational& r1, const Rational& r2)
{
	if ((r1.numerator()-r2.numerator()) == 0) return {0,0};
	if (r1.cognizant() == r2.cognizant()) return reduction({r1.numerator()-r2.numerator(),r1.cognizant()});
	else
	{
		int NOK = calcNOK(r1.cognizant(),r2.cognizant());
		return reduction({r1.numerator()*(NOK/r1.cognizant())-r2.numerator()*(NOK/r2.cognizant()),NOK});
	}
}

// Умножение рациональных чисел, a/b * c/d = a*c/b*d
Rational operator*(const Rational& r1, const Rational& r2)
{
	return reduction({r1.numerator()*r2.numerator(),r1.cognizant()*r2.cognizant()});
}

// Деление рациональных чисел, a/b / c/d = a*d/b*c
Rational operator/(const Rational& r1, const Rational& r2)
{
	return reduction({r1.numerator()*r2.cognizant(),r1.cognizant()*r2.numerator()});
}

// Сравнение рациональных чисел
bool operator==(const Rational& r1, const Rational& r2)
{
	return r1.numerator() == r2.numerator() &&
		r1.cognizant() == r2.cognizant();
}

int main() {
	try {

	cout << "Rarional 0.9.13\n";

	Rational r1{-2,-4};
	cout << r1 << endl;

	Rational r2{2,4};
	cout << r2 << endl;

	cout << reduction(r1) << " + " << reduction(r2) << " = " << r1+r2 << endl;
	cout << reduction(r1) << " - " << reduction(r2) << " = " << r1-r2 << endl;

	cout << reduction(r1) << " * " << reduction(r2) << " = " << r1*r2 << endl;
	cout << reduction(r1) <<  " / " << reduction(r2) << " = " << r1/r2 << endl;
	
	if (r1 == r2) cout << "Числа равны.\n";
	else cout << "Числа не равны.\n";

	cout << "getDouble r1 = " << r1.getDouble() << ", getDouble r2 = " << r2.getDouble() << endl;
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
