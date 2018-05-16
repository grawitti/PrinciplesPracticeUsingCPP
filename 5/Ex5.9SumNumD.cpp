/**
 Дата создания: 22.11.17
 Автор: Руслан
 Назначение: Вычисление суммы, заданной последовательности целых чисел.
 Пример: Введите количество суммируемых значений и нажмите 'Enter'
	3
	Введите несколько целых чисел (| - для окончания ввода)
	1 2 3 4 |
	Вы ввели больше 3 чисел, вычислить сумму всех введенных чисел? y - Да, n - Нет.
	y
	Сумма первых 4 чисел (1 2 3 4 ) равна 10
**/

#include "../std_lib_facilities.h"

// Выводи в консоль сумму заданного диапазона - r чисел в векторе - v
void printResult (vector<int> v, int r) {
	if (r > v.size()) error ("Вы не задали не одного !");
	int s = 0;
	for (int i = 0; i < r; ++i) s+=v[i];
	cout << "Сумма первых " << r << " чисел (";
	for (int x : v) cout << x << ' ';
	cout << ") равна " << s << '\n';
}

int main() {
	try {
		cout << "Назначение: Вычисление суммы, заданной последовательности целых чисел.\n"
				 << "Введите количество суммируемых значений и нажмите 'Enter'\n";
		int range = -1;
		while (!(cin >> range) || range <= 1) {
			cin.clear();
			while (cin.get() != '\n') break;
			cerr << "Ошибка: Введите целое число, больше 1!\n";
		}
		cout << "Введите несколько целых чисел, через пробел и | - для окончания ввода. Например: 1 2 |\n";
		vector<int> vectorNum;
		for (int tempNum = -1; cin >> tempNum || cin.get() != '|';) {
			cin.clear();
			char temp = cin.get();
			if (!(tempNum == 0 || temp == '.' || temp == ',')) vectorNum.push_back(tempNum);
				else if (temp == '|')	break;
					else error("Можно задавать только целые числа!\n");
		}
		if (vectorNum.size() > range) {
			cout << "Вы ввели больше " << range << " чисел, вычислить сумму всех введенных чисел? "
					 << "y - Да, n - Нет.\n";
		char switchAll;
		cin.clear();
		while (cin >> switchAll) {
			cin.clear();
			if (cin.get() != 'y' || cin.get() != 'n')	break;
			cerr << "Ответ может быть только y - Да или n - Нет!\n";
		}
		switch (switchAll) {
			case 'y': {
				printResult(vectorNum, vectorNum.size());
				break;
			}
			case 'n': {
				printResult(vectorNum, range);
				break;
			}
			default: {
				error("Ответ может быть только y - да или n - нет\n");
				break;
			}
		}
	} else printResult(vectorNum, range);
		return 0;
	}
	catch (exception& e) {
		cerr << "Ошибка: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Неизвестное исключение!\n";
		return 2;
	}
}
