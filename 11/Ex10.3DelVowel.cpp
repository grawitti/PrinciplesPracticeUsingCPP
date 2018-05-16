/**
 Дата создания: 14.05.18
 Автор: Руслан
 Назначение: Удаляет все главные буквы из тектового файла.
 Глава 11, упр. 1, стр. 459, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Перевод символов строки s в нижний регистр
void tolower (string& s) 
{
	for (char& c : s) c = tolower(c);
}

// 
string deleteVowels (string& s) 
{
	string result;
	for (char& c : s)
	{
		switch (c) 
		{
			case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': 
				continue;
			default:
				result += c;
				break;
		}
	}
	return result;
}

int main() {
	try 
	{
		cout << "Удаляет все главные буквы из тектового файла.\n"; 

		ifstream ifs{"input1.txt"};
		if (!ifs) error("Невозможно открыть файл для чтения.");

		string inputString;
		char tmpChar;
		while (ifs) 
		{
			tmpChar = ifs.get();
			inputString += tmpChar;
		}

		ofstream ofs{"output_10_3.txt"};
		if (!ofs) error("Невозможно открыть файл для записи.");
		
		tolower(inputString);
		
		inputString = deleteVowels(inputString);

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
