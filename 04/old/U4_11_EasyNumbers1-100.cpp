#include<iostream>
#include<cmath>
#include<vector>
//#include<cstdlib>
//#include<ctime>
using namespace std;

// Основная функция
int main () {
	int beginNumber = 3;
	int endNumbers;
	cout << "Введите число до которго необходимо найти простые (натуральные) числа: " << '\n';
	cin >> endNumbers;
	vector<int> easyNumbers {2};
	for ( ; beginNumber <= endNumbers; beginNumber++) {
		int count = 0;
		for (int x : easyNumbers) {
			if (beginNumber%x == 0 and beginNumber>x) {
				count++;
				break;
			}
		}
		if (count == 0) {
			easyNumbers.push_back(beginNumber);
		}
	}
	cout << "Простые числа от " << easyNumbers[0] << " до " << endNumbers << '\n';
	for (int x : easyNumbers) {
		cout << x << '\n';
	}
	cout << "Количество простых (натуральных) чисел: " << easyNumbers.size() << '\n';
}
