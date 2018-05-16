#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Сколько у Вас монет достоинством в 1 цент?, нажимайте Enter после ввода значения\n";
		double oneCent = 0;
		cin >> oneCent;
		cout << "Сколько у Вас монет достоинством в 5 центов?, нажимайте Enter после ввода значения\n";
		double fiveCent = 0;
		cin >> fiveCent;
		cout << "Сколько у Вас монет достоинством в 10 центов?, нажимайте Enter после ввода значения\n";
		double tenCent = 0;
		cin >> tenCent;
		cout << "Сколько у Вас монет достоинством в 25 центов?, нажимайте Enter после ввода значения\n";
		double twentyFiveCent = 0;
		cin >> twentyFiveCent;
		cout << "Сколько у Вас монет достоинством в 50 центов?, нажимайте Enter после ввода значения\n";
		double fithtyCent = 0;
		cin >> fithtyCent;
		double sumCents = oneCent+fiveCent*5+tenCent*10+twentyFiveCent*25+fithtyCent*50;
		double sumDollars = sumCents/100;
		double cents;
		double dollars;
		cents = modf(sumDollars , &dollars); // отделение дробной части от целой
		cout 	<< "У Вас " << oneCent << " монет достоинством в 1 цент.\n"
					<< "У Вас " << fiveCent << " монет достоинством в 5 центов.\n"
					<< "У Вас " << tenCent << " монет достоинством в 10 центов\n"
					<< "У Вас " << twentyFiveCent << " монет достоинством в 25 центов.\n"
					<< "У Вас " << fithtyCent << " монетостоинством в 50 центов.\n"
					<< "Общая стоимость Вашх монет равна: " << sumCents << " центам.\n"
					<< "Общая стоимость Вашх монет в баксах равна: " << dollars << " долларов " << cents*100 << " центов.\n";
	}
