/**
 Дата создания: 26.01.18
 Автор: Руслан
 Назначение: Реализация класса Book.
 Глава 9, упр. 5, стр. 388, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"
#include <sstream>
#include "T9.5Date9.7.4.cpp"

//Приветствие
void welcomeMessage () {
	cout << "Реализация класса Book.\n";
}

//
class Book {
public:
	string getIsbn() { return isbn; }
	string getTitle() { return bookTitle; }
	string getAuthor() { return author; };
	Date getCopyright() { return copyright; }
	bool getOnHand() { return onHand; }
	bool isISBN ();

	//Book();
	Book(string is, string bt, string at, Date cp) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp} { };
	Book(string is, string bt, string at, Date cp ,bool on) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp}, onHand{} { };

private:
	string isbn; // ISBN  n-n-n-x, где n - целое число, x - цифра или буква.
	string bookTitle; // Название книги
	string author; // Фамилия автора
	Date copyright; // Дата регистрации авторских прав
	bool onHand; // Выдана (на руках) или в библиотеке, true - если на руках (выдана)
};

// Очистка потока - ss по ссылке
void stringstreamClear(stringstream& ss) {
	ss.str("");
	ss.clear();
}

// Проверка символа - c, является ли он числом
bool isNumber (char c) {
	//tempInt = atoi(vs[i].c_str()); // Вариант с использованием функции atoi() преобразования строки в число + функции c_str() строки в массив символов	
	switch(c) {
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
			return true;
			break;
		}
		default:
			return false;
		}
}

// Проверка на соответсвие с стандартом использования ISBN, например: 0-1-20-33-S
bool Book::isISBN () {
	const char SEPARATOR = '-'; // разделитель для ISBN, например: 0-1-20-33-S
	if (isbn.find("-")) {
		stringstream ss(isbn);
		vector<string> vs;
		string tempS = "";
		while (getline(ss, tempS, SEPARATOR)) vs.push_back(tempS); // разделяем строки из потока ss
		if (vs.size() != 4) return 0;
		stringstreamClear(ss);
		char tempC;
		for (int i = 0; i < vs.size(); ++i) {
			stringstream buf(vs[i]);	
			buf >> tempC;
			if (isspace(tempC)) return 0;	
			 if (!(i == vs.size()-1)) {
			 	if (!isNumber(tempC)) return 0;
			 	buf.putback(tempC);
			 	int tempI;
				buf >> tempI;
			}	else {
					if (vs[i].length() > 1 || vs[i].length() <= 0) return 0;
					if (!(isalpha(tempC) || isdigit(tempC)) || isspace(tempC)) return 0;
				}
			tempC = ' ';
			tempS = "";
			buf >> tempS;
			if (tempS != "") return 0;
			stringstreamClear(buf);
		}	
	} else return 0;
	return 1;
}

int main() {
	try {
		welcomeMessage();
		Book b{" 20- 12-23 -S","Таинственный остров","Жюль Верн",{Year{1900},Month::may,15}, false};
		cout << b.isISBN() << endl;
		cout << b.getIsbn() << " " << b.getTitle() << " " << b.getAuthor() << " " << b.getCopyright() << " " << b.getOnHand() << endl;
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
