#include "Ex9.9.h"

//Размер членского взноса
const double& defaultFee () {
	static double amount = 100.0;
	return amount;
}

// Класс Patron (клиенты библиотеки)
string Patron::getPatronName() const {return patroname;}
int Patron::getLibNumber() const {return libNumber;}
double Patron::getPatronFee() const {return patronFee;}

// Оплачен ли членский взнос?
bool Patron::getFeeStatus() {
	if (getPatronFee() < defaultFee()) return true;
	else return false;
}

// Перегрузка оператора << для класса Patron
ostream& operator<< (ostream& os, const Patron& p) {
	return os << p.getLibNumber() << " - "
						<< p.getPatronName() << " - " 
            << p.getPatronFee() << endl;//" - "
            //<< p.getFeeStatus() << endl;
}