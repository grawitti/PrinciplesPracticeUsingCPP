#include "Ex9.9.h"

// Book
string Book::getIsbn() const { return isbn; }
string Book::getTitle() const { return bookTitle; }
string Book::getAuthor() const { return author; };
Date Book::getCopyright() const { return copyright; }
Genre Book::getGenre() const { return gen; }
bool Book::getOnHand() const { return onHand; }

Book::Book(string is, string bt, string at, Date cp) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp} {
	if (!isISBN(isbn)) error("ISBN введен не верно!"); };
Book::Book(string is, string bt, string at, Date cp ,bool on) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp}, onHand{} {
	if (!isISBN(isbn)) error("ISBN введен не верно!"); };
Book::Book(string is, string bt, string at, Date cp, Genre ge ,bool on) : isbn{is}, bookTitle{bt}, author{at}, copyright{cp}, gen{ge},
	onHand{} { if (!isISBN(isbn)) error("ISBN введен не верно!"); };

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