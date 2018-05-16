#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

vector<char> variants {'k', 'n', 'b'};
int magicNumber = 76345;
char userVar;
char aiVar;
char forQuit;

// Функция при победе игрока
void win(char uVar, char aVar) {
	cout << "Выбор игрока: " << uVar << '\t' << "Выбор компьютера: " << aVar << '\n';
	cout << "Вы выграли!)" << '\n';
	cout << "Сыграем еще разок? y если ДА" << '\n';
	cin >> forQuit;

}

// Функция при проигрыше игрока
void lose(char uVar, char aVar) {
	cout << "Выбор игрока: " << uVar << '\t' << "Выбор компьютера: " << aVar << '\n';
	cout << "Вы проиграли!(" << '\n';
	cout << "Сыграем еще разок? y если ДА" << '\n';
	cin >> forQuit;
}

// Функция при совпадении
void standoff(char uVar, char aVar) {
	cout << "Выбор игрока: " << uVar << '\t' << "Выбор компьютера: " << aVar << '\n';
	cout << "Ничья(" << '\n';
	cout << "Сыграем еще разок? y если ДА" << '\n';
	cin >> forQuit;
}

// Основная функция
int main () {
	int randomNumber;
	for ( ; cin >> userVar; ) {
		srand(time(NULL));
		aiVar = variants[rand() % 3];	
		cout << aiVar << '\n';
		switch (userVar) {
			case 'k': {
				switch (aiVar) {
					case 'k': {
						standoff(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
					case 'n': {
						win(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
					case 'b': {
						lose(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
				}
			}
			case 'n': {
				switch (aiVar) {
					case 'k': {
						lose(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
					case 'n': {
						standoff(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
					case 'b': {
						win(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
				}
			}
			case 'b': {
				switch (aiVar) {
					case 'k': {
						win(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
					case 'n': {
						lose(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
					case 'b': {
						standoff(userVar, aiVar);
						if (forQuit!='y') {
							return 0;
						} else continue;
						break;
					}
				}
			}
		}
	}
}
