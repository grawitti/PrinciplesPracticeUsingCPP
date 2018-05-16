/**
 Дата создания: 19.04.18
 Автор: Руслан
 Назначение: Точность чисел с плавающей точкой: defaultfloat, fixed, scintific.
 Глава 11, зад. 9, стр. 458, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"
int main() {
	try 
	{
		cout << "Точность чисел с плавающей точкой: defaultfloat, fixed, scintific.\n";
		
		double i = 1234567.89;

		cout << i << endl
			<< fixed << i << endl
			<< scientific << i << endl;

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
