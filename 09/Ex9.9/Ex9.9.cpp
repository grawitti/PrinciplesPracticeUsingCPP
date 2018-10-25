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

#include "Ex9.9.h"

int main() {
	try {
	cout << "Реализация класса Book 0.9.9.\n";

	Library test;
	
    cout << "Введите текущую дату." << endl;

	Date currentDate{inputDate()};

    while (true) {
      if (requestYorN("Добавить книгу в библиотеку?")) test.addBook();
      else break;
    }

    while (true) {
      if (requestYorN("Добавить клиента библиотеки?")) test.addPatron();
      else break;
    }
 
    if (requestYorN("Вывести список книг в библиотеке?")) test.printBooks();

    if (requestYorN("Вывести список клиентов библиотеки?")) test.printPatrons();

	vector<Transaction> vt;
	Patron tempPatron{"",0,0.0};
	Book tempBook{"00-00-00-0","","",{Year{2000},Month::jan,1}};
	if (requestYorN("Хотите взять книгу в библиотеке?")) {
		while (true) {
			cout << "Введите имя клента: ";
			tempPatron = test.findByName(getStringFromCin());
			if (tempPatron.getPatronName() == "") {
				cerr << "Клиент с именем " << tempPatron.getPatronName() << " не зарегистрирован в библиотеке.\n";
				if (requestYorN("Хотите ввесли другое имя клиента?")) continue;
				else break;
			} break;
		}
		if (tempPatron.getFeeStatus()) error ("Вы имеете задолжность по членским взносам.");
		while (true) {
			cout << "Введите название книги которую хотите взять?" << endl;
			tempBook = test.findBookByName(getStringFromCin());
			if (tempBook.getTitle() == "") {
				cerr << "Книги " << tempBook.getTitle() << " нет в библиотеке.\n";
				if (requestYorN("Хотите ввесли другое название книги?")) continue;
				else break;
			}
			if (tempBook.getOnHand()) error("Эта книга на руках.");	
			cout << "Хотите взять книгу: " << tempBook;
			if (requestYorN("")) {
				Transaction t{tempBook,tempPatron,currentDate};
				test.switchHand(tempBook);
				vt.push_back(t);
				if (requestYorN("Хотите взять еще книгу?")) continue;
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
