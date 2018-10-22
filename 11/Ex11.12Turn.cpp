/**
 Дата создания: 16.05.18
 Автор: Руслан
 Назначение: Переворачивает строку наоборот.
 Глава 11, упр. 12, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Перевод символов строки s в нижний регистр
void tolower (string& s) 
{
	for (char& c : s) c = tolower(c);
}

//
string turnString(string& s) 
{
	string result;
	vector<char> vs;
	for(char& c : s) vs.push_back(c);
	for (int i = vs.size()-1; i >= 0; --i) result += vs[i];
	return result;
}

int main() {
	try 
	{
		cout << "Переворачивает строку наоборот.\n"; 

		string iname = "Ex11.12_in.txt";
		ifstream ifs{iname};
		if (!ifs) error("Невозможно открыть файл для чтения ", iname);

		string inputString;
		char c;
		while (ifs) 
		{
			ifs >> c;
			inputString += c;
		}
	
		string turnedString = turnString(inputString);	

		string oname = "Ex12.11_out.txt";
		ofstream ofs{oname};
		if (!ofs) error("Невозможно открыть файл для чтения ", oname);
		
		for (char& c : turnedString) ofs << c;
		
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
