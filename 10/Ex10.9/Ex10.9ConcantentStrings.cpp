/**
 Дата создания: 23.04.18
 Автор: Руслан
 Назначение: Конкатенация содержимого двух файлов в 3й новый файл, убирает пробелы.
 Глава 10, упр. 9, стр. 428, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
**/

#include "../../std_lib_facilities.h"

// Чтение файла, построчно в вектор string
void readFile (string& ifname, vector<string>& vs) 
{
	ifstream ifs {ifname};
	if (!ifs) error("Невозможно открыть файл ", ifname);
	for (string tmp; !ifs.eof(); )  
	{
		getline(ifs,tmp);
		if (tmp != "\n") vs.push_back(tmp);
	}
}

int main() {
	try {
		cout << "Конкатенация содержимого двух файлов в 3й новый файл.\n";
	
		string iname1 = "1.txt";
		vector<string> vs1;
		readFile(iname1,vs1);

		string iname2 = "2.txt";
		vector<string> vs2;
		readFile(iname2,vs2);

		string oname = "3.txt";
		ofstream ofs {oname};
		if (!ofs) error("Невозможно создать файл ", oname);

		for (string s : vs1) for (char& c : s) if (!isspace(c)) ofs << c;
		for (string s : vs2) for (char& c : s) if (!isspace(c)) ofs << c;

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
