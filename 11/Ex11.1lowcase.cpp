/**
 Дата создания: 20.04.18
 Автор: Руслан
 Назначение: Читает содержимое файла и записывает его в другой файл в нижнем регистре. 
 Глава 11, упр. 1, стр. 459, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Перевод символов строки s в нижний регистр
void tolower (string& s) 
{
	for (char& c : s) c = tolower(c);
}

int main() {
	try 
	{
		cout << "Читает содержимое файла и записывает его в другой файл в нижнем регистре.\n"; 

		ifstream ifs{"input1.txt"};
		if (!ifs) error("Невозможно открыть файл для чтения.");

		string inputString;
		char tmpChar;
		while (ifs) 
		{
			tmpChar = ifs.get();
			inputString += tmpChar;
		}

		ofstream ofs{"output1.txt"};
		if (!ofs) error("Невозможно открыть файл для записи.");
		
		tolower(inputString);
		for (char& c : inputString) ofs << c;
		
		keep_window_open();
	}
	catch (exception& e) 
	{
		cerr << "\nОшибка: " << e.what() << endl;
		return 1;
		keep_window_open();
	}
	catch (...) 
	{
		cerr << "\nНеизвестное исключение!\n";
		return 2;
		keep_window_open();
	}
}
