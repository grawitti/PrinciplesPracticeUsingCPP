/**
 Дата создания: 30.11.17
 Автор: Руслан
 Назначение: Проверяет предложение на граматику английского языка описанную в Гл. 6.4.1,
 книги Б. Страуструпа "Программирование принципы и пактика с использованием С++". Выводит ответ: "Да" или "Нет"
 Пример: 

**/

#include "../std_lib_facilities.h"

// глобальные переменные
const vector<string> nouns {"birds", "fish", "C++"};
const vector<string> verbs {"rules", "fly", "swim"};
const vector<string> unions {"and", "or", "but"};

// Выводит в консоль приветствие
void wellcomeMassege() {
	cout << "Граматика Английского языка в. 0.6.7.0" << endl
			 << "Введите предложение на английском языке, используя поддерживаемые слова." << endl
			 << "Программа поддерживает следующие слова:" << endl
			 << "- существительные: the birds, the fish, the C++" << endl
			 << "- глаголы: rules, fly, swim" << endl
			 << "- союзы: and, or, but" << endl
			 << "вконце предложения вводите ." << endl
			 << "Например: the birds fly but the fish swim ." << endl;
}

// получение слова
string getNextWord () {
	string word;
	cin >> word; 
	return word;
}

// Поиск слова s в векторе string v
bool findWord(vector<string> v, string s) {
	for (string x : v) {
		if (x == s) return true;
	}
	return false;
}

void article();

// Союз или .
void unione() {
	string word = getNextWord();
	if (word == ".") {
		cout << "Да\n";
		exit(0);
	}
	if (!findWord(unions, word)) {
		cout << "Нет\n";
		exit(0);}
	article();
}

// Глагол
void verb() {
	string word = getNextWord();
	if (!findWord(verbs, word))  {
		cout << "Нет\n";
		exit(0);}
	unione();
}

// Существительное
void noun() {
	string word = getNextWord();
	if (!findWord(nouns, word))  {		
		cout << "Нет\n";
		exit(0);
	}
	verb();
}

// Артикль the
void article() {
	string word = getNextWord();
	if (word != "the") {
		cout << "Нет\n";
		exit(0);
	}
	noun();
}

int main() {
	try {
		wellcomeMassege();
		article();
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
