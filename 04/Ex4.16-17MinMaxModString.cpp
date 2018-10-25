/**
 Дата создания: 04.11.17
 Автор: Руслан
 Описание: Программа нахождения определяющая наибольшее и наименьшее, а так же моду из последовательности слов.
 Ввод: 
 Вывод: 
**/

#include "../std_lib_facilities.h"

// Функция нахождения минимального значения отсортированного вектора string
string findMin(vector<string> v) {
	return v[0];
}

// Функция нахождения максимального значения отсортированного вектора string
string findMax(vector<string> v) {
	return v[v.size()-1];
}

// Функция нахождения моды (самого часто повторяющегося) значения отсортированного вектора string
string findMod (vector<string> v) {
	int modCount = 0;
	int tempCount = 0;
	string mod = " ";
	for (int i = 0; i < v.size(); ++i) {
		if (i+1 != v.size() && v[i] == v[i+1]) ++tempCount;
		else if (tempCount) {
			if (tempCount > modCount) {
				mod = v[i-1];
				modCount = tempCount;
				tempCount = 0;
			}
		}
	}
	return mod;
}

int main() {
// Приветствие
	cout << "Программа нахождения определяющая наибольшее и наименьшее, а так же моду из последовательности слов.\n"
			 << "Введите слово и нажмите 'Enter':\n";
// Инициализация переменных
	vector<string> stringVector;
	string inputString = " ";
// Ввод слов
	for (;cin>>inputString;) {
		if (stringVector.size()) {
			stringVector.push_back(inputString);
			sort(stringVector);
// Вывод результатов
			cout << "Min: " << findMin(stringVector) << "\n";
			cout << "Max: " << findMax(stringVector) << "\n";
			if (stringVector.size() > 2) cout << "Mod: " << findMod(stringVector) << "\n";
		} else stringVector.push_back(inputString);
	}
  return 0;
}
