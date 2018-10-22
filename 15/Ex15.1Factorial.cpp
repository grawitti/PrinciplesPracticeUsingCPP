/**
 Дата создания: 15.10.18
 Автор: Руслан
 Назначение: 
 Глава 15, Упр., стр. 605, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

using namespace std;

// Возвращает факториал целого числа - n
int fac(int n)
{
	return n>1 ? n*fac(n-1) : 1;
}

int main()
{
	try 
	{
		cout << "Введите число для вычисления его факториала:\n";
		for(int temp; cin >> temp; )
		{
			int result = fac(temp);
			cout << temp << "! = " << result << endl;
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
	return 0;
}
