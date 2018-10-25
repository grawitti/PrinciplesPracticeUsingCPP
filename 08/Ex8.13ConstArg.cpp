/**
 Дата создания: 12.01.18
 Автор: Руслан
 Назначение: Проврека костантного агрумента функции не по ссылке.
 Глава 8, упр. 13, стр. 350, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "\nПроврека костантного агрумента функции не по ссылке.\n";
}

//
void testConstArg(const int i, const char c, const string s, const vector<int> vi) {
	cout << i << " " << c << " " << s << " " << endl;
	for (int x : vi) cout << x << " ";
	cout << endl;
	++i; 
	c = '0';
	s = "true";
	vi.push_back(4);
}

int main() {
	try {
		welcomeMessage();
		int ii = 1;
		char cc = 't';
		string ss = "test";
		vector<int> vi {1,2,3};
		testConstArg(ii,cc,ss,vi);
		testConstArg(2,'a',"test2",vi);
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
