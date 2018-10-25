#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	vector<double> numbers;
	double number;
	for (int i = 0; i < 2; i++) {
		cin >> number;
		numbers.push_back(number);
	}
	if (numbers[0] < numbers[1]) {
			cout << "Наименьшее значение равно: " << numbers[0] << '\n'
			<< "Наибольшее значение равно: " << numbers[1] << '\n';
	} else if (numbers[0] == numbers[1]) {
		cout << "Числа равны: " << '\n';
	} else {
		cout << "Наименьшее значение равно: " << numbers[1] << '\n'
		<< "Наибольшее значение равно: " << numbers[0] << '\n';
	}
}
