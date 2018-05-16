#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	cout << "Программа приводит введеные значения длинны к сантиметрам, "
			<< "считает сумму ввденых значений и велечин, сортирует их по возрастанию и выводит результат." << '\n' << '\n'
			<< "Доступные следующие значения единицы измерения: cm, m, in, ft"
			<< "Ввдедите величину длинны и единицу измерения через пробел и нажмите Enter для продолжения" << '\n'
			<< "Например: 1 cm" << '\n';
	vector<double> numbers;
	double number;
	string mesUnit;
	double minNumber;
	double maxNumber;
	double sumOfNumber = 0;
	while (true) {
		cin >> number >> mesUnit;
		if (mesUnit == "m") {
			number = number * 100;
			numbers.push_back(number);
			sumOfNumber+=number;
		} else if (mesUnit == "in") {
			number = number * 2.54;
			numbers.push_back(number);
			sumOfNumber+=number;
		} else if (mesUnit == "ft") {
			number = number * 30.48;
			numbers.push_back(number);
			sumOfNumber+=number;
		} else if (mesUnit == "cm") {
			numbers.push_back(number);
			sumOfNumber+=number;
		} else if (mesUnit == "|") {
			cout << "Выход!" << '\n';
			sort(numbers.begin(), numbers.end());
			for (double x : numbers) {
				cout << x << '\t';
			}
			cout << '\n' << "Сумма всех введеных значений в cm: " << sumOfNumber << '\n';
			cout << "Количество введеных значений: " << numbers.size() << '\n';
			return 0;
		} else {
			cout << "Ошибка!" << '\n';
			cout << "Введено не корректное значение единицы измерения или величины."
			<< "Доступные следующие значения единицы измерения: cm, m, in, ft" << '\n';
			sort(numbers.begin(), numbers.end());
			for (double x : numbers) {
				cout << x << '\t';
			}
			cout << '\n' << "Сумма всех введеных значений в cm: " << sumOfNumber << '\n';
			cout << "Количество введеных значений: " << numbers.size() << '\n';
			return 0;
		}
	for (double x : numbers) {
			//cout << "x= " << x << '\n';
			if (x == 0) {
				cout << "Ошибка!" << '\n';
				cout << "Введено не корректное значение. Оно может быть только числом!" << '\n';
				sort(numbers.begin(), numbers.end());
				for (double x : numbers) {
					cout << x << '\t';
				}
				cout << '\n' << "Сумма всех введеных значений в cm: " << sumOfNumber << '\n';
				cout << "Количество введеных значений: " << numbers.size() << '\n';
				return 0;
			}
			if (numbers.size() == 1) {
				minNumber = x;
				maxNumber = x;
				cout << "Это первое введеное число" << '\n';
			} else if (x < minNumber) {
				minNumber = x;
				cout << "Наименьшее среди введенных" << '\n';
			} else if (x > maxNumber) {
				maxNumber = x;
				cout << "Наибольшее среди введенных" << '\n';
			}
		}
		cout	<< "Ввдедите следующее значение длинны и единицу измерения через пробел и нажмите Enter для продолжения" << '\n';
	}
}
