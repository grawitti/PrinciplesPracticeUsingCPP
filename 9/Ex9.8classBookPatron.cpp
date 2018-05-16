/**
 Дата создания: 05.03.18
 Автор: Руслан
 Назначение: Реализация класса Book.
 Глава 9, упр. 9, стр. 389, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
 0.9.9 
 0.9.8 Добавлен класс Patron для ведения учетных записей.
 0.9.7 Перечисление Genre (фантастикаб проза, журнал, биография, детская).
 0.9.6 Перегрузка операторов ==, !=, <<.
**/

#include "../std_lib_facilities.h"
#include <sstream>
#include "T9.5Date9.7.4.cpp"

//Приветствие
void welcomeMessage () {
	cout << "Реализация класса Book 0.9.7.\n";
}

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
bool isISBN (const string& s) {
	const char SEPARATOR = '-'; // разделитель для ISBN, например: 0-1-20-33-S
	if (s.find("-")) {
		stringstream ss(s);
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

//
enum class Genre {
	unknown, fantastic, prose, journal, biography, kids
};

//
class Book {
public:
	string getIsbn() const { return isbn; }
	string getTitle() const { return bookTitle; }
	string getAuthor() const { return author; };
	Date getCopyright() const { return copyright; }
	Genre getGenre() const { return gen; }
	bool getOnHand() { return onHand; }
	friend bool operator== (const Book& b1, const Book& b2);
	friend bool operator!= (const Book& b1, const Book& b2);
	friend ostream& operator<< (ostream& os, const Book& b);

	//Book();
	Book(string is, string bt, string at, Date cp) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp} { 
		if (!isISBN(isbn)) error("ISBN введен не верно!"); };
	Book(string is, string bt, string at, Date cp ,bool on) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp}, onHand{} { 
		if (!isISBN(isbn)) error("ISBN введен не верно!"); };
	Book(string is, string bt, string at, Date cp, Genre ge ,bool on) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp}, gen{ge},
	  onHand{} { if (!isISBN(isbn)) error("ISBN введен не верно!"); };

private:
	string isbn{"0-0-0-a"}; // ISBN  n-n-n-x, где n - целое число, x - цифра или буква.
	string bookTitle{""}; // Название книги
	string author{""}; // Фамилия автора
	Date copyright{}; // Дата регистрации авторских прав
	Genre gen{Genre::unknown}; // Жанр литературы
	bool onHand{false}; // Выдана (на руках) или в библиотеке, true - если на руках (выдана)
};

// Перегрузка оператора ==
bool operator== (const Book& b1, const Book& b2) {
	return b1.getIsbn() == b2.getIsbn()
	&&		 b1.getTitle() == b2.getTitle()
	&& 		 b1.getAuthor() == b2.getAuthor()
	&&		 b1.getCopyright().year() == b2.getCopyright().year()
	&&		 b1.getCopyright().month() == b2.getCopyright().month()
	&&		 b1.getCopyright().day() == b2.getCopyright().day();
}

// Перегрузка оператора !=
bool operator!= (const Book& b1, const Book& b2) {
	return ! (b1 == b2);
}

// Перегрузка оператора <<
ostream& operator<< (ostream& os, const Book& b) {
	return os << b.getTitle() << endl
						<< b.getAuthor() << endl
						<< b.getIsbn() << endl;
}

//Размер членского взноса
const double& defaultFee () {
	static double amount = 100.0;
	return amount;
}

// Пользователи библиотеки
class Patron {
public:
string getUsername() const {return username;}
int getLibNumber() const {return libNumber;}
double getMemberFee() const {return memberFee;}
bool getFeeStatus ();

Patron(string u, int n, double f) :username{u}, libNumber{n}, memberFee{f} { }

private:
string username{""};
int libNumber{};
double memberFee{0.0};
};

// Оплачен ли членский взнос?
bool Patron::getFeeStatus() {
	if (getMemberFee() < defaultFee()) return 0;
	else return 1;
}

int main() {
	try {
		welcomeMessage();
		Book b{"0-1-2-S","Таинственный остров","Жюль Верн",{Year{1901},Month::may,15}, true};
		Book b1{"0-1-2-S","Таинственный остров","Жюль Верн",{Year{1901},Month::may,15}, false};
		cout << b << b1;
		if (b==b1) cout << "Одинаковые книги.\n";
		else cout << "Разные книги.\n";

		Patron u{"acinonyx85",1,100.0};
		cout << u.getFeeStatus() << endl;
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
