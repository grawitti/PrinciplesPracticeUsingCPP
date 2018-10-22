/**
 Дата создания: 20.04.18
 Автор: Руслан
 Назначение: Находит в файле все слова совпадающие с именем файла и выводит строки в которых они содержаться.
 Глава 11, упр. 2, стр. 459, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		cout << "Находит в файле все слова совпадающие с именем файла и выводит строки в которых они содержаться.\n"; 

		string oname = "input";
		ifstream ifs{oname};
		if (!ifs) error("Невозможно открыть файл для чтения.");

		string line;
		vector<string> vs;
		while (ifs) 
		{
			getline(ifs,line);
			vs.push_back(line);
		}

		for (string s : vs) tolower(s);

		for (int i = 0; i < vs.size(); ++i) 
		{
			stringstream ss{vs[i]};
			for (string tmp; ss >> tmp; )
			{
				if (!tmp.find(oname)) cout << "слово: " << oname << " найдено в " << i+1 << " строке.\n"; 	
			}
		}
		
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
