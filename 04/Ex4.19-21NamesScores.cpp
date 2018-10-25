/**
 Дата создания: 05.11.17
 Автор: Руслан
 Описание: Программа ввода и вывода имени и баллов. Например: Иван 100.
 Ввод: 
 Вывод:
**/

#include "../std_lib_facilities.h"

// Функция поиска строки s string в векторе string v
int findName(string s, vector<string> v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == s) return i;
	}
	return -1;
}

int main() {
// Приветствие
	cout << "Программа ввода и вывода имени и очков. Например: Иван 100.\n";			
// Инициализация переменных
	vector<int> scores;
	vector<string> names;
	int tempScore;
	string tempName;
// Ввод имени
	for (;tempName != "exit";) {
		cout << "Введите имя и нажмите 'Enter':\n";
		cin >> tempName;
		if (tempName == "exit") return 0;
			if (findName(tempName, names) >= 0) {
				cout << "Такое имя уже есть.\n" 
						 << names[findName(tempName, names)] << " оценка: " << scores[findName(tempName, names)] << "\n";
			} else { // Добавление нового имени и оценки
					cout << "Имя не найдено.\n";
					cout << "Введите оценку и нажмите 'Enter':\n";
					cin >> tempScore; // Ввод оценки
					scores.push_back(tempScore);
					names.push_back(tempName);
				}
	// Вывод результатов с такими же оценками
	for (int i = 0; i < scores.size(); ++i) {
		if (tempScore == scores[i]) cout << names[i]  << ": " << scores[i] << " ";
	}
	cout << "\n";
	}
  return 0;
}