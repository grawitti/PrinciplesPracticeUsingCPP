/**
 Дата создания: 19.04.18
 Автор: Руслан
 Назначение: Вывод переменной birthyear
 Глава 11, зад. 1-8, стр. 457, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"
int main() {
	try 
	{
		cout << "Вывод переменной birthYear\n";
		
		int birthYear = 1985;

		cout << "dec:\t" << birthYear << endl
			<< hex << "hex:\t"<< birthYear << endl 
			<< oct << "oct:\t" << birthYear << endl;
		cout << 'a' << '\t' << hex << "string" << endl;

		int a,b,c,d;
		cin >> a >> oct >> b >> hex >> c >> d;
		cout << a << '\t' << b << '\t' << c << '\t' << d << endl;


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
