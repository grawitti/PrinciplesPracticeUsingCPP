/**
 Дата создания: 30.11.17
 Автор: Руслан
 Описание: Программа ввода и вывода имени и баллов. Например: Иван 100.
 Ввод: 
 Вывод:
**/

#include "../std_lib_facilities.h"

// Класс string - name, int score 
class NameScore {
	public:
		string name;
		int score;
};

// Функция поиска строки s string в векторе string v
int findName(NameScore s, vector<NameScore> v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].name == s.name) return i;
	}
	return -1;
}

int main() {
// Приветствие
	cout << "Программа ввода и вывода имени и очков. Например: Иван 100.\n";			
// Инициализация переменных
	NameScore ns;
	vector<NameScore> vns;
// Ввод имени
	for (;ns.name != "q";) {
		cout << "Введите имя и нажмите 'Enter':\n";
		cin >> ns.name;
		if (ns.name == "q") return 0;
			if (findName(ns, vns) >= 0) {
				cout << "Такое имя уже есть.\n" 
						 << vns[findName(ns, vns)].name << " оценка: " << vns[findName(ns, vns)].score << "\n";
			} else { // Добавление нового имени и оценки
					cout << "Имя не найдено.\n";
					cout << "Введите оценку и нажмите 'Enter':\n";
					cin >> ns.score; // Ввод оценки
					if (!cin) return 0;
					vns.push_back(ns);
				}
	// Вывод результатов с такими же оценками
	for (int i = 0; i < vns.size(); ++i) {
		if (ns.score == vns[i].score) cout << vns[i].name  << ": " << vns[i].score << " ";
	}
	cout << "\n";
	}
  return 0;
}