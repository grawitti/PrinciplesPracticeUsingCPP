/**
 Дата создания: 10.01.18
 Автор: Руслан
 Назначение: Вычисление заданного отрезка последовательности чисел Фибоначи и вывод его в консоль.
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "Демонстрация функций перевода последовательноти значений от большего к меньшему.\n\n";
}

// Выводит в поток cout вектор - v и метку, string - s
void print (const string& s, const vector<string>& v) {
	cout << s << ": ";
	for (string x : v) cout << x << ' ';

	cout << endl << endl;
}

// Инверсия последовательности вектора v, возвращает новый вектор
vector<string> swapV (vector<string> v) {
	string temp = "";
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > v[(v.size()-1)-i]) {
			temp = v[i];
			v[i] = v[(v.size()-1)-i];
			v[(v.size()-1)-i] = temp;
		}
	}
	return v;
}

// Инверсия последовательности вектора v, изменяет вектор переданный по ссылке
void swapR (vector<string>& v) {
	string temp = "";
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > v[(v.size()-1)-i]) {
			temp = v[i];
			v[i] = v[(v.size()-1)-i];
			v[(v.size()-1)-i] = temp;
		}
	}
}

int main() {
	try {
		welcomeMessage();
		vector<string> vs {"a","b","c"};
		print("Начальный вектор",vs);
		print("Вектор (swapV)",swapV(vs));
		swapR(vs);
		print("Вектор (swapR)",vs);
	}
		catch (exception& e) {
			cerr << "\nОшибка: " << e.what() << endl;
			return 1;
		}
		catch (...) {
			cerr << "\nНеизвестное исключение!\n";
			return 2;
		}
}
