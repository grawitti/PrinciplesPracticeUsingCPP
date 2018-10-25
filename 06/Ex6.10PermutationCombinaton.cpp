/**
 Дата создания: 04.12.17
 Автор: Руслан
 Назначение: Вычисляет количество перестановок или сочетаний по входным данным, выводит результат.
 Пример: 32 8
	Вычислить количество перестановок P(32, 8)? y - Да или n - Нет.
	y
	Количество перестановок: P(32, 8) = 4.24098e+11
	Вычислить количество сочетаний: С(32, 8)? y - Да или n - Нет.
	y
	Количество сочетаний С(32, 8) = 1.05183e+07
**/

#include "../std_lib_facilities.h"

// Выводит в консоль приветствие
void printSalute() {
	cout << "Перестановки и сочетания в. 0.6.10.0" << endl
			 << "Введите количество возможных элементов (a) и количество элементов в комбинации (b)" << endl
			 << "Например: 32 8" << endl;
}

// Ввод количества элементов и коибинаций
vector<int> getElements() {
	vector<int> v;
	char temp;
	for(int i = 0; i < 2; ++i) {
		cin >> temp;
		switch(temp) {
			case '0': case '1': case '2': case '3':case '4': case '5': case '6': case '7': case '8': case '9': {
				cin.putback(temp);
				int e;
				cin >> e;
				v.push_back(e);
				break;
			}
			default:
			error("Вводите только целые числа.");
			break;
		}
	}
	cin.ignore();
	return v;
}

// Запрос ответа y - Да или n - Нет
bool getYes() {
	char temp;
	for(int i = 0; i < 1; ++i) {
		cin >> temp;
		switch(temp) {
			case 'y': {
				cin.ignore();
				return true;
			}
			case 'n': {
				cin.ignore();
				return false;
			}
			default:
			error("Ответ может быть только y или n.");
			break;
		}
	}
	cin.ignore();
	return true;
}

// Вычисление факториала числа
double calcFactorial(double n) {    
  if (n == 0) { // В соответствии с принятыми математикой правилами факториал 0! равен 1.
    n = 1;
    return n;
  }
  double temp = n;
  for (int i = 1; i<n ; ++i) temp*=i; // Вычисление факториала числа
  n = temp;
  return n;
}

// Вычисление количества перестановок P(a,b), a = v[0], b = v[1]
double calcPermutation (vector<int> v) {
	double p = calcFactorial(v[0]) / calcFactorial(v[0] - v[1]); // Формула: P(a,b)= a!/(a-b)!
	return p;
}

// Вычисление количества сочетаний С(a,b), a = v[0], b = v[1]
double calcCombination (vector<int> v) {
	double c = calcPermutation(v) / calcFactorial(v[1]); //  Формула: С(a,b)= С(a,b)/b!
	return c;
}

int main() {
	try {
		printSalute();
		vector<int> vElements;
		vElements = getElements();
		cout << "Вычислить количество перестановок P(" << vElements[0] << ", " << vElements[1] << ")? y - Да или n - Нет.\n";
		if(getYes()) {
				cout << "Количество перестановок: P(" << vElements[0] << ", " << vElements[1] << ") = " 
				     << calcPermutation(vElements) << endl << endl;
		}
		cout << "Вычислить количество сочетаний: С(" << vElements[0] << ", " << vElements[1] << ")? y - Да или n - Нет.\n";
		if(getYes()) {
				cout << "Количество сочетаний С(" << vElements[0] << ", " << vElements[1] << ") = " 
				     << calcCombination(vElements) << endl << endl;
		}
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
