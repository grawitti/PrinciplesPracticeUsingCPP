#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	vector<double> numbers;
	double number;
	double minNumber;
	double maxNumber;
	while (true) {
		cin >> number;
		numbers.push_back(number);
		for (double x : numbers) {
			//cout << "x= " << x << '\n';
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
	}
}
