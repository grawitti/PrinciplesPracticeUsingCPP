/**
 Дата создания: 03.11.17
 Автор: Руслан
 Описание: Программа нахождения простых чисел в заданном диапазоне
 Ввод: 0 100
 Вывод: 2 3 5 ...
**/

#include "../std_lib_facilities.h"

// Функция заполнения вектора простыми числами в диапазоне от x до y.
vector<int> fullerPrimesNum (vector<int> v, int x, int y) {
	for (int i = x; i <= y; i++) {
		for (int j = x; j < i; j++) {
			if (!(i%j)) break;
			if (i == j+1) v.push_back(i);
		}	
	}
	return v;
}

int main() {
// Приветствие
	cout << "Программа нахождения простых чисел в заданном диапазоне.\n"
			 << "Введите диапазон значений в котором необходимо найти простые числа, через пробел и нажмите 'Enter':\n";
// Инициализация переменных
	int endRange = -1, beginRange = -1;
// Ввод значений
	for (;cin >> beginRange >> endRange;) {
		if (beginRange < 2) beginRange = 2;
		vector<int> primesNum {beginRange};
		primesNum = fullerPrimesNum(primesNum, beginRange ,endRange);
		for (int x : primesNum) cout << x << "\t";
		cout << "\nВведите следующий диапазон значений и нажмите 'Enter':\n";
	}
  return 0;
}
