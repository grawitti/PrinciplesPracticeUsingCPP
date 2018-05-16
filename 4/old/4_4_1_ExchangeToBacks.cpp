
#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите значение и валюту, которую необходимо перевести в $\n"
				 << "r - Рубли,\n"
				 << "e - Евро,\n"
				 << "p - Фунты стерлинов,\n"
				 << "$ - Доллары.\n"
				 << "Например для перевода 10 рублей в доллары, наберите: 10 r\n"
				 << "Не забывайте ПРОБЕЛ между значением и валютой\n"
				 << "После окончания ввода нажмите Enter\n";
		char moneyUnit = ' ';
		double moneyValue = 0;
		cin >> moneyValue >> moneyUnit;
		constexpr double rubInBacks = 61.21;
		constexpr double backsInEuro = 1.12;
		constexpr double backsInPSterling = 1.97;
		switch (moneyUnit) {
			case '$':
				cout << moneyValue << " $ = " << moneyValue << " $\n";
				break;
			case 'r':
				cout << moneyValue << " рублей = " << moneyValue/rubInBacks << " $\n";
				break;
			case 'e':
					cout << moneyValue << " евро = " << moneyValue*backsInEuro << " $\n";
					break;
			case 'p':
					cout << moneyValue << " фунтов ст. = " << moneyValue*backsInPSterling << " $\n";
					break;
			default:
				cout << "Я не знаю такую валюту " << moneyUnit << "!\n";
				break;
		}
	}
