#include "Ex9.9.h"

// // Возвращает введеную дату
// Date inputDate() {
// 	cout << "Введите год:" << endl;
// 	int year = getIntFromCin();
// 	cout << "Введите месяц:" << endl;
// 	Month month = inToMonth(getIntFromCin());
// 	cout << "Введите день:" << endl;
// 	int day = getIntFromCin();
// 	return {Year{year},month,day};
// }

// Library
	vector<Book> const Library::getBooks() { return vb; }
	vector<Patron> const Library::getPatrons() { return vp; }
	vector<Transaction> const Library::getTransactions() { return vt; }
	int Library::getNextLibNumber() const { return countLibNumber+1; }

// Если книга выдана = true
void Library::switchHand (const Book& b) {
	for (int i = 0; i < vb.size(); ++i) {
		if (vb[i].getTitle() == b.getTitle()) {
			vb[i].switchOnHand();
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

	string tempISBN = getStringFromCin();
	if (isISBN(tempISBN)) {
		cout << "Введите название книги:" << endl;
		string tempTitle = getStringFromCin();

		cout << "Введите фамилию и имя автора книги:" << endl;
		string tempAuthor = getStringFromCin();

		cout << "Введите дату регистрации авторских прав книги." << endl;
		Date tempDate{inputDate()};

		Genre g = Genre::unknown; // Ввод жанра!!!

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
  string tempPatronName = getStringFromCin();

  int tempLibNumber = getNextLibNumber();
  cout << "Номер библиотелной катрочки: " << tempLibNumber << endl;

  cout << "Введите сумму членского взноса:" << endl;  
  double tempPatronFee = getDoubleFromCin();

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