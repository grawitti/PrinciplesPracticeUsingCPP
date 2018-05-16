/**
 Дата создания: 14.05.18
 Автор: Руслан
 Назначение: Заменяет знаки пунктуации (.,;?') на пробелы, расшифровывает сокращения don't и  can't, переводит символы в нижний регистр.
 Глава 11, упр. 7, стр. 459, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Перевод символов строки s в нижний регистр
void tolower (string& s) 
{
	for (char& c : s) c = tolower(c);
}

// Заменяет символы .,;?' пробелом
void deletePuncts(string& s) 
{
	for (char& c : s) 
	{
		switch(c) 
		{
			case '.': case ',':  case ';': case '?': case '\'':
				c = ' ';
			break;
			default:
			break;
		}
	}
}

// Расшифровывает сокращения don't и can't в строке s
string decode (const string& s)
{
	stringstream ss{s};
	string result;
	for(string temp; ss >> temp; )
	{
		if (temp == "don't") temp = "do not";
		if (temp == "can't") temp = "cannot";
		result += ' ' + temp;
	}
	return result;
}

int main() {
	try 
	{
		cout << "Заменяет знаки пунктуации (.,;?') на пробелы, расшифровывает сокращения don't и  can't, переводит символы в нижний регистр.\n"; 
		
		cout << "Введите строку символов: ";
		string inputString;
		getline(cin,inputString);
		tolower(inputString);
		inputString = decode(inputString);
		deletePuncts(inputString);
		cout << inputString << endl;

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
