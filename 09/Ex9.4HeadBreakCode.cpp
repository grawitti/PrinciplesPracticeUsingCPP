/**
 Дата создания: 22.01.18
 Автор: Руслан
 Назначение: Головоломный код из раздела 8.4. 
 Глава 9, упр. 4, стр. 388, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

const string STOP = "."; // строка для прекращения ввода имен

//Приветствие
void welcomeMessage () {
	cout << "Головоломный код из раздела 8.4.\n";
}

struct X {
	int m;

	void f (int x) {
		struct Y
			{
				int m;
				int f() { return 1; }
			};
		int m;
		m = x;
		Y m2;
		return f(m2.f());
	}

	void g(int m) {
		if (m) f(m+2);
		else {
			g(m+2);
		}
	}

	void main() {
		X a;
		a.f(2);
	}

	void m3() {}

	X() { }
};


int main() {
	try {
		welcomeMessage();

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
