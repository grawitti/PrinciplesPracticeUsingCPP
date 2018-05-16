#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	vector<double> numbers;
	vector<int> moda(9999999);
	double number;
	double minNumber;
	double maxNumber;
	int modNumber;
	while (true) {
		cin >> number;
		numbers.push_back(number);
		moda[number]=moda[number]+1;
			for (int i = 0; i <= moda.size(); i++) {
				if (moda[i] > 0) {
					if (moda[i] > moda[modNumber]) {
						modNumber = i;
						cout << "Мода: " << modNumber << '\n';
					}
				}
			}
			for (double x : numbers) {
			//cout << "x= " << x << '\n';
			if (numbers.size() == 1) {
				modNumber = x;
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
