/**
 Дата создания: 14.05.18
 Автор: Руслан
 Назначение: Заменяет знаки пунктуации (.,;?-') на пробелы, не заменяет знак " в файле.
 Глава 11, упр. 6, стр. 459, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Заменяет символы .,;?-' пробелом
void deletePuncts(string& s) 
{
	for (char& c : s) 
	{
		switch(c) 
		{
			case '.': case ',':  case ';': case '?': case '-': case '\'':
				c = ' ';
			break;
			default:
			break;
		}
	}
}

int main() {
	try 
	{
		cout << "Заменяет знаки пунктуации (.,;?-') на пробелы, не заменяет знак ковычек.\n"; 
		
		cout << "Введите строку символов: ";
		string inputString;
		getline(cin,inputString);
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
