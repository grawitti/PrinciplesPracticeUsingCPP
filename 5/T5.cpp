/**
 Дата создания: 20.11.17
 Автор: Руслан
 Назначение: Проверка кода на ошибки
 Ввод:
 Вывод:
**/

#include "../std_lib_facilities.h"

int main() {
	try {
		int x = 2000; int c = x; if (c==2000) cout << "S\n";
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "Ошибка: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Неизвестное исключение!\n";
		keep_window_open();
		return 2;
	}
}
