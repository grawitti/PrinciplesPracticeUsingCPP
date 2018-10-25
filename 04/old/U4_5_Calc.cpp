#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


// Основная функция
int main () {
	char manipulator;
	double numberOne;
	double numberTwo;
	cout << "Для продолжения введите любой символ и нажмине Enter, для выхода введите q и нажмите Enter" << '\n';
	//char quit;
	cin >> manipulator;
	while (manipulator != 'q') {
		cout << "Введите оператор и два числа через пробел." << '\n'
				 << "Например: + 2 2 Для сложения 2 + 2" << '\n';
		cin >> manipulator >> numberOne >> numberTwo;
		double result;
		switch (manipulator) {
			case '+': {
				result = numberOne + numberTwo;
				cout << "Результат: " << numberOne << manipulator << numberTwo << "="<< result << '\n';
				break;
			}
			case '-': {
				result = numberOne - numberTwo;
				cout << "Результат: " << numberOne << manipulator << numberTwo << "="<< result << '\n';
				break;
			}
			case '*': {
			result = numberOne * numberTwo;
			cout << "Результат: " << numberOne << manipulator << numberTwo << "="<< result << '\n';
			break;
			}
			case '/': {
			result = numberOne / numberTwo;
			cout << "Результат: " << numberOne << manipulator << numberTwo << "="<< result << '\n';
			break;
			}
			default: {
				std::cout << "Ошибка. Введите корректные значения." << '\n';
				return 0;
			break;
			}
		}
	}
}
