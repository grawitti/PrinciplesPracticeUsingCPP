/**
 Дата создания: 19.03.18
 Автор: Руслан
 Назначение: Реализация класса Date.
 Глава 9, упр. 10, стр. 389, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
	0.9.10 Добавление функция leapyear() - высокостный год.
**/

#include "../utils/Date_lib — копия.h"
#include "../std_lib_facilities.h"

int main() {
	try {

	cout << "Класс Date 0.9.10.\n";

	Date d{inputDate()};
	if (leapyear(d)) cout << "Высокостный год.\n";
	else cout << "Обычный год\n";
	cout << d << endl;

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
