#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// Основная функция
int main () {
	vector<string> words {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char swicher;
	cout << "Введите символ: d если надо преобразовать число в слово" << '\n'
			 << "Введите символ: w если надо преобразовать слово в число" << '\n';
	cin >> swicher;
	switch (swicher) {
		case 'd': {
			cout << "Введите число от 0 до 9, программа преобразует его в слово." << '\n';
			for (int digit; cin >> digit; ) {
				if (0 > digit || digit > 9) {
					std::cout << "Ошибка! Введите число от 0-9." << '\n';
					break;
				}
				cout << words[digit] << '\n';
			}
			break;
		}
		case 'w': {
			cout << "Введите слово от zero до nine, программа преобразует его в число." << '\n';
			for (string word; cin >> word; ) {
				if (word == "q") {
					std::cout << "Выход." << '\n';
					return 0;
				}
				for (int i = 0; i <= words.size(); i++) {
					if (word == words[i]) {
						cout << i << '\n';
						i = words.size()+1;
					}	else { 
							continue; 
						}
			}
			break;
		}
		default: {
			cout << "Ошибка." << '\n';
			return 0;
		}
	}
} 
}
