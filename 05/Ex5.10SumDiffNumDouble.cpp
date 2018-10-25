/**
 Дата создания: 22.11.17
 Автор: Руслан
 Назначение: Вычисление суммы, заданной последовательности чисел и печать верктора разностей заданнных чисел.
 Пример: Введите количество суммируемых значений и нажмите 'Enter'
	3
	Введите несколько целых чисел (| - для окончания ввода)
	1.1 2.2 3 4 |
	Вы ввели больше 3 чисел, вычислить сумму всех введенных чисел? y - Да, n - Нет.
	y
	Сумма первых 4 чисел (1.1 2.2 3 4 ) равна 10.3
	Вектор разностей (N-1): 1.1 0.8 1
**/

#include "../std_lib_facilities.h"

// Выводи в консоль сумму заданного диапазона - r чисел в векторе - v
void printSum (vector<double> v, double r) {
	if (r > v.size()) error ("Вы не задали не одного числа!");
	double s = 0;
	for (int i = 0; i < r; ++i) s+=v[i];
	cout << "Сумма первых " << r << " чисел (";
	for (double x : v) cout << x << ' ';
	cout << ") равна " << s << '\n';
}

// Вывод вектора разностей N-1 заданного вектора v
void printDiff (vector<double> v) {
	if (v.size() < 2) error ("Нет чисел для подсчета разности!");
	vector<double> d;
	for (int i = 1; i < v.size(); ++i) {
		d.push_back(v[i]-v[i-1]);
	}
	cout << "Вектор разностей (N-1): ";
	for (double x : d) cout << x << " ";
	cout << endl;
}

int main() {
	try {
		cout << "Назначение: Вычисление суммы, заданной последовательности чисел и печать верктора разностей заданнных чисел.\n"
				 << "Введите количество суммируемых значений и нажмите 'Enter'\n";
		int range = -1;
// Запрос и обработка количества чисел которых надо будет сложить
		while (!(cin >> range) || range <= 1) { // Количество должно быть больше 1 иначе нет смысла
			cin.clear();
			while (cin.get() != '\n') break;
			cerr << "Ошибка: Введите целое число, больше 1!\n";
		}
// Запрос и обратотка чисел
		cout << "Введите несколько чисел, через пробел и | - для окончания ввода. Например: 1.2 3.4 |\n";
		vector<double> vectorNum;
		for (double tempNum = -1; cin >> tempNum || cin.get() != '|';) {
			cin.clear();
			char temp = cin.get(); // считываем символы по одному за раз
			if (!(tempNum == 0)) vectorNum.push_back(tempNum);
				else if (temp == '|')	break;
					else error("Можно задавать только числа!\n");
		}
// Если ввели больше чисел чем указали в первом запросе, то запрос о подсчете суммы всех чисел
		if (vectorNum.size() > range) {
			cout << "Вы ввели больше " << range << " чисел, вычислить сумму всех введенных чисел? "
					 << "y - Да, n - Нет.\n";
			char sumAll;
			for (;cin >> sumAll;) {
				cin.clear();
				char temp = cin.get();
				if (!(temp == 'y' || temp == 'n')) break;
				cerr << "Ответ может быть только y - Да или n - Нет!\n";
			}
			switch (sumAll) {
				case 'y': {
					printSum(vectorNum, vectorNum.size());
					break;
				}
				case 'n': {
					printSum(vectorNum, range);
					break;
				}
				default: {
					error("Ответ может быть только y - да или n - нет\n");
					break;
				}
			}
		} else printSum(vectorNum, range);
			printDiff(vectorNum);
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
