/**
 Дата создания: 01.12.17
 Автор: Руслан
 Назначение: Считывает цифры как символы char и преобразует их в числа int 2-4х разрядные.
 Выводит результат в виде: "123 - это 1 сотня, 2 десятки и 3 единицы."
 Пример: 1234.
	1234 - это 1 тысяча, 2 сотни, 3 десятки и 4 единицы

**/

#include "../std_lib_facilities.h"

// глобальные переменные
const vector<string> words {"тысяч", "сот", "десят", "единиц"};

// Выводит в консоль приветствие
void wellcomeMessage() {
	cout << "Цифро - численный преобразователь в. 0.6.9.0" << endl
			 << "Введите целое число и вконце поставьте знак - '.'" << endl
			 << "Например: 123." << endl;
}

// Возвращыет переданую строку string s, добавляя окончания а, ов в соответствии с значением - int x и r правилом
string addStrings (string s, int x) {
	int r;
	if (s == "единиц") r = 1;
	if (s == "десят") r = 2;
	if (s == "сот") r = 3;
	if (s == "тысяч") r = 4;
	if (x < 0) error("addStrings()");
	switch (r) { // единиц
		case 1: {
			if (x == 1) return s+"а";
			if (x > 1 && x < 5) return s+"ы";
			if (x > 4) return s;
			break;
		}
		case 2: { // десят
			if (x == 1) return s+"ка";
			if (x > 1 && x < 5) return s+"ки";
			if (x > 4 || x == 0) return s+"ок";
			break;
		}
		case 3: { // сот
			if (x == 1) return s+"ня";
			if (x > 1 && x < 5) return s+"ни";
			if (x > 4 || x == 0) return s+"ен";
			break;
		}
		case 4: { // тысяч
			if (x == 1) return s+"а";
			if (x > 1 && x < 5) return s+"ы";
			if (x > 4) return s;
			break;
		}
		default: {
			break;
		}
	} return s;
}

// Конветрация вектора char vc в вектор int vi
vector<int> convertCharToInt(vector<char> vc) {
	if (!vc.size()) error("Пустой вектор vc");
	vector<int> vi;
	for (char x : vc) vi.push_back(x-'0');
	return vi;
}

// Вывод вектора целых чисел в консоль через пробел
void printVector(vector<int> v) {
	if (!v.size()) error("Пустой вектор v");
	for (int x : v) {
		cout << x;
	}
	cout << " - это ";
}

// Вывод рузультата
void printResult(vector<int> v) {
	if (!v.size()) error("Пустой вектор v");
	int j = 0;
	if (v.size() < 2 || v.size() > 4) error("Поддерживаются только числа от 2-4х разрядов (12, 123, 1234)");
	if (v.size() == 2) j = 2;
	if (v.size() == 3) j = 1;
	string s = ", ";
	printVector(v);
		for (int i = 0; i < v.size(); ++i) {
		if (i == v.size()-2) s = " и ";
		cout << v[i] << ' ' << addStrings(words[i+j], v[i]);
		if (i != v.size()-1) cout << s;
	}
	cout << endl;
}

// Считываем цифры в вектор char
vector<char> getInputDigits() {
	char d;
	vector<char> v;
	cin.clear();
	while(true) {
		d = cin.get();
		if (d == '.') break;
		if (d != '\n' && d < '0' || d > '9') error("Вы ввели не цифру 0-9");
		if (d != '\n' || d != '.') v.push_back(d);
	}
	cin.ignore();
	printResult(convertCharToInt(v));
	return v;
}

int main() {
	try {
	wellcomeMessage();
	getInputDigits();
		return 0;
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
