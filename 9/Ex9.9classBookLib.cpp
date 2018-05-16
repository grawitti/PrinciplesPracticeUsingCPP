/**
 Дата создания: 05.03.18
 Автор: Руслан
 Назначение: Реализация класса Book.
 Глава 9, упр. 9, стр. 389, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
 0.9.9 Добавлен класс Library, структура Transaction...
 0.9.8 Добавлен класс Patron для ведения учетных записей.
 0.9.7 Перечисление Genre (фантастикаб проза, журнал, биография, детская).
 0.9.6 Перегрузка операторов ==, !=, <<.
**/

#include "../std_lib_facilities.h"
#include "Ex9.9.h"

//Приветствие
void welcomeMessage () {
	cout << "Реализация класса Book 0.9.9.\n";
}

// Очистка потока - ss по ссылке
void stringstreamClear(stringstream& ss) {
	ss.str("");
	ss.clear();
}

// Если char c цифра возвращает true
bool isNumber (const char& c) {
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
	void switchOnHand ();
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

// Переключатель OnHand
void Book::switchOnHand () {
	if (onHand == false) onHand = true;
	else onHand = false;
}

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
	return os << b.getTitle() << ", "
						<< b.getAuthor() << ", " 
						<< b.getIsbn() << ", "
            << b.getCopyright() << endl;
}

//Размер членского взноса
const double& defaultFee () {
	static double amount = 100.0;
	return amount;
}

// Клиенты библиотеки
class Patron {
public:
string getPatronName() const {return patroname;}
int getLibNumber() const {return libNumber;}
double getPatronFee() const {return patronFee;}
bool getFeeStatus (); // Есть ли задолжность членского взноса
friend ostream& operator<< (ostream& os, const Patron& p);

Patron(string u, int n, double f) :patroname{u}, libNumber{n}, patronFee{f} { }

private:
string patroname{""}; // имя пользователя библиотеки
int libNumber{0}; // номер карточки пользователя библиотеки
double patronFee{0.0};// челенский взнос пользователя библиотеки
};

// Оплачен ли членский взнос?
bool Patron::getFeeStatus() {
	if (getPatronFee() < defaultFee()) return true;
	else return false;
}

// Перегрузка оператора << для класса Patron
ostream& operator<< (ostream& os, const Patron& p) {
	return os << p.getLibNumber() << " - "
						<< p.getPatronName() << " - " 
            << p.getPatronFee() << endl;//" - "
            //<< p.getFeeStatus() << endl;
}

//
struct Transaction {
	Book b;
	Patron p;
	Date d;

	Transaction(Book bb, Patron pp, Date dd) :b{bb}, p{pp}, d{dd} {  }
};

//
class Library {
public:
	vector<Book> const getBooks() { return vb; }
	vector<Patron> const getPatrons() { return vp; }
	vector<Transaction> const getTransactions() { return vt; }
	void addBook();
	void addPatron();
	void printBooks();
	void printPatrons(); 
	int getNextLibNumber() const { return countLibNumber+1; }
	bool checkRepeatTitleBook(const Book& b, const string& s);
	bool checkRepeatBook(const Book& b);
	bool checkRepetPatron(const Patron& p); // Проверка на совпадение имен клиентов
	Patron findByName (const string& s); // Поиск по имени в векторе vp
	Book findBookByName (const string& s); 
	void switchHand (const Book& b);
	void printBadPatrons(); // Выводит список задолжников по членским взносам
	
private:
	vector<Book> vb;
	vector<Patron> vp;
	vector<Transaction> vt;
	int countLibNumber{0};
};

// int to Month
Month inToMonth(const int& i) {
	switch(i) {
		case 1:
			return Month::jan;
		case 2:
			return Month::feb;
		case 3:
			return Month::mar;
		case 4:
			return Month::apr;
		case 5:
			return Month::may;
		case 6:
			return Month::jun;
		case 7:
			return Month::jul;
		case 8:
			return Month::aug;
		case 9:
			return Month::sep;
		case 10:
			return Month::oct;
		case 11:
			return Month::nov;
		case 12:
			return Month::dec;
		default:
		error("Неверно ввели месяц.");
		break;
	}
	error("Неверно ввели месяц.");
}

// Очистка потока cin, до сивола: \n
void clearCin() {
  char ignore = 'c';
  while (ignore != '\n') ignore = cin.get();
}

// Обаботка ввода из потока cin занчения - string
string getStringFromCin () {
 char line[256];
  cin.getline(line, 256);
  return line;
}

// 
void Library::switchHand (const Book& b) {
	for (int i = 0; i < vb.size(); ++i) {
		if (vb[i].getTitle() == b.getTitle()) {
			vb[i].switchOnHand();
		}
	}
}

// Обаботка ввода из потока cin занчения - int
int getIntFromCin () {
  char c = '0';
  while (true) {
    cin >> c;
    switch (c) {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
        cin.putback(c);
        int i;
        cin >> i;
        clearCin();
        return i;       
      }
      default:
        cerr << "Введите целое положительное число:\n";
        clearCin();
        break;
    }  
  }
}

// Обаботка ввода из потока cin занчения - double
int getDoubleFromCin () {
  char c = '0';
  while (true) {
    cin >> c;
    switch (c) {
      case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
        cin.putback(c);
        double d;
        cin >> d;
        clearCin();
        return d;       
      }
      default:
        cerr << "Введите положительное число:\n";
        clearCin();
        break;
    }  
  }
}

// Сравнение названия книг
bool Library::checkRepeatTitleBook(const Book& b, const string& s) {
  for (Book b : vb) if (b.getTitle() == s) return true;
  return false;
}

// Сравнение книг
bool Library::checkRepeatBook(const Book& b) {
  for (Book x : vb) if (b == x) return true;
  return false;
}

//
bool Library::checkRepetPatron(const Patron& p) {
  for (Patron x : vp) if (x.getPatronName() == p.getPatronName()) return true;
  return false; 
}

// Добавление книги
void Library::addBook() {
	cout << "Добавление новой книги." << endl
			 << "Введите ISBN в формате - 00-11-22-A:" << endl;
	string tempISBN;
	tempISBN = getStringFromCin();
	if (isISBN(tempISBN)) {
		cout << "Введите название книги:" << endl;
		string tempTitle;
		tempTitle = getStringFromCin();
		cout << "Введите фамилию и имя автора книги:" << endl;
		string tempAuthor;
		tempAuthor = getStringFromCin();
		cout << "Введите дату регистрации авторских прав книги." << endl;
		cout << "Введите год:" << endl;
		int tempYear;
		tempYear = getIntFromCin();
		cout << "Введите месяц:" << endl;
		int tempMonth;
		tempMonth = getIntFromCin();
		Month m = inToMonth(tempMonth);
		cout << "Введите день:" << endl;
		int tempDay;
		tempDay = getIntFromCin();
		Date tempDate{Year{tempYear},m,tempDay};
//		cout << tempISBN << ", " << tempDate << ", " << tempTitle << ", " <<  tempAuthor <<  endl;
		Genre g = Genre::unknown;
		Book tempBook{tempISBN,tempTitle,tempAuthor,tempDate,g,false};
		if (checkRepeatTitleBook(tempBook, tempTitle)) error("Книга с таким названием уже есть в библиотеке."); // проверка на совпадение названия книг
		if (checkRepeatBook(tempBook)) error("Такая книга уже есть в библиотеке."); // проверка на совпадение книг
		vb.push_back(tempBook);
	}
}

//Вывод книг в консоль
void Library::printBooks() {
  for (Book b : vb) { 
    cout << b << endl;
  }
}

// Добаление клиентов
void Library::addPatron() {
  cout << "Введите имя клиента:" << endl;
  string tempPatronName = "";
  tempPatronName = getStringFromCin();
  int tempLibNumber = getNextLibNumber();
  cout << "Номер библиотелной катрочки: " << tempLibNumber << endl;
  cout << "Введите сумму членского взноса:" << endl;  
  double tempPatronFee = 0;
  tempPatronFee = getDoubleFromCin();
  if (tempPatronFee < 0) error("Взнос не может быть меньше 0.");
  Patron p{tempPatronName,tempLibNumber,tempPatronFee};
  if (checkRepetPatron(p)) error("Клиент с таким именем уже был зарегистрирован.");
  vp.push_back(p);
}

// Печать списка клиентов в консоль
void Library::printPatrons() {
  for (Patron p : vp) cout << p << endl;
}  

// Выводит список задолжников по членским взносам
void Library::printBadPatrons() {
	for (Patron x : vp) {
		if (x.getFeeStatus()) cout << x << endl;	
	}
}

// Поиск по имени клиента
Patron Library::findByName (const string& s) {
	for (Patron x : vp) {
		if (x.getPatronName() == s) {
			return x;
		}
	}
	return {"",0,0.0};
}

// Поиск книги по имени 
Book Library::findBookByName (const string& s) {
	for (Book x : vb) {
		if (x.getTitle() == s) {
			return x;
		}
	}
	return {"00-00-00-0","","",{Year{2000},Month::jan,1}};
}

// y ли n выбор
bool yorN () {
  char c = 'y';
  cin.get(c);
  switch (c) {
    case 'y': {
      clearCin();
      return true;
    }
    case 'n': {
      clearCin();
      return false;
    }
    default: {
      error("Введите y или n."); 
    }
  }
  return true;
}

int main() {
	try {
	welcomeMessage();

	Library test;
	
    cout << "Введите текущую дату." << endl;
	cout << "Введите год:" << endl;
	int tempYear;
	tempYear = getIntFromCin();
	cout << "Введите месяц:" << endl;
	int tempMonth;
	tempMonth = getIntFromCin();
	Month m = inToMonth(tempMonth);
	cout << "Введите день:" << endl;
	int tempDay;
	tempDay = getIntFromCin();
	Date currentDate{Year{tempYear},m,tempDay};

    while (true) {
      cout << "Добавить книгу в библиотеку? (y - ДА или n - НЕТ)" << endl;
      if (yorN()) test.addBook();
      else break;
    }

    while (true) {
      cout << "Добавить клиента библиотеки? (y - ДА или n - НЕТ)" << endl;
      if (yorN()) test.addPatron();
      else break;
    }
    
    cout << "Вывести список книг в библиотеке? (y - ДА или n - НЕТ)" << endl;
    if (yorN()) test.printBooks();

    cout << "Вывести список клиентов библиотеки? (y - ДА или n - НЕТ)" << endl;
    if (yorN()) test.printPatrons();
	vector<Transaction> vt;
	Patron tempPatron{"",0,0.0};
	Book tempBook{"00-00-00-0","","",{Year{2000},Month::jan,1}};
    cout << "Хотите взять книгу в библиотеке? (y - ДА или n - НЕТ)" << endl;
	if (yorN()) {
		while (true) {
			cout << "Введите имя клента: ";
			tempPatron = test.findByName(getStringFromCin());
			if (tempPatron.getPatronName() == "") {
				cerr << "Клиент с именем " << tempPatron.getPatronName() << " не зарегистрирован в библиотеке.\n";
				cout << "Хотите ввесли другое имя клиента? (y - ДА или n - НЕТ)" << endl;
				if (yorN()) continue;
				else break;
			} break;
		}
		if (tempPatron.getFeeStatus()) error ("Вы имеете задолжность по членским взносам.");
		while (true) {
			cout << "Введите название книги которую хотите взять?" << endl;
			tempBook = test.findBookByName(getStringFromCin());
			if (tempBook.getTitle() == "") {
				cerr << "Книги " << tempBook.getTitle() << " нет в библиотеке.\n";
				cout << "Хотите ввесли другое название книги? (y - ДА или n - НЕТ)" << endl;
				if (yorN()) continue;
				else break;
			}
			if (tempBook.getOnHand()) error("Эта книга на руках.");	
			cout << "Хотите взять книгу: " << tempBook << "? (y - ДА или n - НЕТ)" << endl;
			if (yorN()) {
				Transaction t{tempBook,tempPatron,currentDate};
				test.switchHand(tempBook);
				vt.push_back(t);
				cout << "Хотите взять еще книгу? (y - ДА или n - НЕТ)" << endl;
				if (yorN()) continue;
				else break;
			} break;
		}	
	}
		cout << "Список задолжников по членским взносам:\n";
		test.printBadPatrons();

    keep_window_open();
	}
		catch (exception& e) {
			cerr << "\nОшибка: " << e.what() << endl;
    keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "\nНеизвестное исключение!\n";
    keep_window_open();
			return 2;
		}
}
