/**
 Дата создания: 14.05.18
 Автор: Руслан
 Назначение: Считывает строку и выводит категории каждого символа в соответсвии с Гл 11.6.
 Глава 11, упр. 5, стр. 459, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"
int main() {
	try 
	{
		cout << "Считывает строку и выводит категории каждого символа в соответсвии с Гл 11.6.\n"; 
		
		cout << "Введите строку символов: ";
		string inputString;
		getline(cin,inputString);

		for (char& c : inputString) 
		{
			cout << c << ":\t";
			if (isspace(c)) cout << "|пробельный символ\t";
			if (isalpha(c)) cout << "|буква\t";
			if (isdigit(c)) cout << "|десятичная цифра\t";
			if (isxdigit(c)) cout << "|16 цифра\t";
			if (isupper(c)) cout << "|буква в верхнем регистре\t";
			if (islower(c)) cout << "|буква в нижнем регистре\t";
			if (isalnum(c)) cout << "|буква или 10я цифра\t";
			if (iscntrl(c)) cout << "|символ ASCII\t";
			if (ispunct(c)) cout << "|ни буква, ни цифра ни разделитель, ни невидимый упр. символ\t";
			if (isprint(c)) cout << "|выводится на печать\t";
			if (isgraph(c)) cout << "|isalpha() || isdigit() || isipunct()\t";
			cout << endl;
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
