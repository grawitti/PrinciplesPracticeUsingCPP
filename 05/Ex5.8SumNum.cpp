/**
 Дата создания: 21.11.17
 Автор: Руслан
 Назначение: Вычисление суммы, заданной последовательности целых чисел.
 Ввод:
 Вывод:
**/

#include "../std_lib_facilities.h"

// Выводи в консоль сумму заданного диапазона - r чисел в векторе - v
void printResult (vector<int> v, int r) {
	if (r > v.size()) error ("Диапазон больше размера вектора!");
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
		cout << "Введите несколько целых чисел (| - для окончания ввода)\n";
		vector<int> vectorNum;
		int tempNum = -1;
		while (cin >> tempNum || cin.get() != '|') {
			cin.clear();
			if (tempNum != 0) vectorNum.push_back(tempNum);
			if (cin.get() == '|')	break;
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
	} else
		printResult(vectorNum, range);
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
