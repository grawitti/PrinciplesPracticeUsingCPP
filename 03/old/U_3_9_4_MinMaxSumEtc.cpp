
#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите 2 числа, после каждого числа нажимайте Enter\n";
		double valueA = 0;
		double valueB = 0;
		cin>>valueA>>valueB;
		cout << "1 Число: " << valueA << "\n2 Число: " << valueB << " \n"
				 << "Сумма чисел = " << valueA+valueB << "\n"
				 << "Произведение чисел = " << valueA*valueB << "\n"
				 << "Разность чисел = " << valueA-valueB << "\n"
				 << "Частное чисел = " << valueA/valueB << "\n";
		if (valueA<valueB)
		{
			cout << "Наименьшее число 1 = " << valueA << "\n"
					 << "Наибольшее число 2 = " << valueB << "\n";
		}
			else
			{
				cout << "Наименьшее число 2 = " << valueB << "\n"
					 	 << "Наибольшее число 1 = " << valueA << "\n";
			}
	}
