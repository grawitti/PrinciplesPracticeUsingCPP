#include "../../std_lib_facilities.h"
// #include "../../utils/io_lib.h"
// #include "../../utils/Date_lib.h"
#include "../../utils/Date.h"
#include "../../utils/io.h"

// ISBN
bool isISBN (const string& s);
// ISBN END

// BOOK
enum class Genre {
	unknown, fantastic, prose, journal, biography, kids
};

//
class Book {
public:
	string getIsbn() const;
	string getTitle() const;
	string getAuthor() const;
	Date getCopyright() const;
	Genre getGenre() const;
	bool getOnHand() const;
	void switchOnHand ();
	friend bool operator== (const Book& b1, const Book& b2);
	friend bool operator!= (const Book& b1, const Book& b2);
	friend ostream& operator<< (ostream& os, const Book& b);

	Book(string is, string bt, string at, Date cp);
	Book(string is, string bt, string at, Date cp ,bool on);
	Book(string is, string bt, string at, Date cp, Genre ge ,bool on);


private:
	string isbn{"0-0-0-a"}; // ISBN  n-n-n-x, где n - целое число, x - цифра или буква.
	string bookTitle{""}; // Название книги
	string author{""}; // Фамилия автора
	Date copyright{}; // Дата регистрации авторских прав
	Genre gen{Genre::unknown}; // Жанр литературы
	bool onHand{false}; // Выдана (на руках) или в библиотеке, true - если на руках (выдана)
};
// BOOK END

// PATRON
// Размер членского взноса
const double& defaultFee ();

// Класс Patron (клиенты библиотеки)
class Patron {
public:
string getPatronName() const;
int getLibNumber() const;
double getPatronFee() const;
bool getFeeStatus (); // Есть ли задолжность членского взноса
friend ostream& operator<< (ostream& os, const Patron& p);

Patron(string u, int n, double f) :patroname{u}, libNumber{n}, patronFee{f} { }

private:
string patroname{""}; // имя пользователя библиотеки
int libNumber{0}; // номер карточки пользователя библиотеки
double patronFee{0.0};// челенский взнос пользователя библиотеки
};
// PATRON END

// TRANSACTION
struct Transaction {
	Book b;
	Patron p;
	Date d;

	Transaction(Book bb, Patron pp, Date dd) :b{bb}, p{pp}, d{dd} {  }
};
// TRANSACTION END

// LIBRARY
// Date inputDate();

class Library {
public:
	vector<Book> const getBooks();
	vector<Patron> const getPatrons();
	vector<Transaction> const getTransactions();
	void addBook();
	void addPatron();
	void printBooks();
	void printPatrons(); 
	int getNextLibNumber() const;
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
// LIBRARY END
