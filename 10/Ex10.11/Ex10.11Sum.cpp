/**
 Дата создания: 23.04.18
 Автор: Руслан
 Назначение: Вычисление суммы чисел из файла.
 Глава 10, упр. 11, стр. 428, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример: Ввод: Улоывг OUBu 32 dks; *(^%) 4. Вывод: 36
 Changelog:
**/

#include "../../std_lib_facilities.h"

// Чтение файла, посимвольно в string
void readFile (string& ifname, string& s) 
{
	ifstream ifs {ifname};
	if (!ifs) error("Невозможно открыть файл ", ifname);
	char ch;
	for (string tmp; !ifs.eof(); )  
	{
		ch = ifs.get();
		s += ch;
	}
}

int main() {
	try {
		cout << "Вычисление суммы чисел из файла.\n";
	
		string iname = "1.txt";
		string s;
		readFile(iname,s);
		int sum = 0;
		stringstream ss{s};
		for (; !ss.eof(); ) 
		{
			int i = 0;
			ss >> i;
			if (!ss) 
			{
				ss.clear();
				char ch;
				ss >> ch;
				continue;
			}
			sum += i;
		}
		cout << "Сумма чисел из файла " << iname << " = " << sum << endl;
		

		keep_window_open();
	}
	catch (exception& e) {
		cerr << "\nОшибка: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (int& e) {
		cerr << "\nОшибка: Год, месяц или день введены некорректно." << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "\nНеизвестное исключение!\n";
		keep_window_open();
		return 2;
	}
}
