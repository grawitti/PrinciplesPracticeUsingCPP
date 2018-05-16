/**
 Дата создания: 02.11.17
 Автор: Руслан
 Назначение: Программа преобразует введеные целые числа в слова и наоборот.
 Пример: 
 Ввод: 7
 Вывод: Семь
**/

#include "../std_lib_facilities.h"

// Инициализация констант и глобальных переменных
const vector<string> words {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};

// Функция вывода элементов массива по индексу
void printElemByIndex (int i) {
	cout << words[i] << "\n";
}

// Функция вывода индексов элемента массива по значению
bool printIndexByElem (string s) {
	for (int i = 0; i < words.size(); ++i) {
		if (s == words[i]) {
			cout << i << "\n";
			return true;
		}
	}
	return false;
}

int main() {
// Приветствие
	cout << "Программа преобразует введеные целые числа в слова и наоборот.\n"
			 << "Вы хотите преобразовать числа в слова? Например: 1 - один. y - да, n - Нет\n";
	char switcher = 'y';
	cin >> switcher;
	switch (switcher) {
		case 'y': {
			cout << "Введите целое число от 0 - 9 и нажмите 'Enter':\n";
			int num = -1;
			for (; cin >> num; ) {
				if (num > words.size()-1 || num < 0) {
					cout << "Я умею стичтать только от 0 - 9\n";
					continue;
				}
			printElemByIndex(num);			
			}
		break;
		}
		case 'n': {
			cout << "Введите слово от ноль - девять и нажмите 'Enter':\n";
			string word = " ";
			for (; cin >> word; ) {
				bool findWord = printIndexByElem(word);
				if (findWord == false) cout << "Я умею стичтать только от ноля - девяти\n";			
			}
		break;
		}
		default:
		cout << "Ошибка! Не корректный ответ: " << switcher << "\n";
		break;
	}
  return 0;
}
