/**
 Дата создания: 12.01.18
 Автор: Руслан
 Назначение: Выводит в поток cout элементы вектора пока не встретит строку "quit" 2 раза.
 Глава 8, упр. 11, стр. 350, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "Выводит в поток cout элементы вектора пока не встретит строку 'quit' 2 раза.\n";
}

//Выводит в поток cout элементы вектора пока не встретит строку 'quit'.
void print_until_s(vector<string> v, string quit) {
	for (string s : v) {
		if (s == quit) return;
		cout << s << '\n';
	}
}

//Выводит в поток cout элементы вектора пока не встретит строку 'quit'.
void print_until_ss(const vector<string>& v, const string& quit) {
	int countQuit = 0;
	for (string s : v) {
		if (s == quit) ++countQuit;
		if (countQuit == 2) return;
		cout << s << '\n';
	}
}

int main() {
	try {
		welcomeMessage();
		vector<string> testWords {"What","you","qq","say","about","my","q","job","q","?"};
		print_until_s(testWords ,"q");
		print_until_ss(testWords ,"q");

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
