/**
 Дата создания: 22.05.18
 Автор: Руслан
 Назначение: Считывает числва из файла и выводит их в порядке возрастания, подсчитывая дубликаты и выводя их количество.
 Глава 11, упр. 16, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

struct RepeatNumber 
{
double number;
int rCount{1};

RepeatNumber() {}
RepeatNumber(double d) : number{d} {}
};

int main() {
	try 
	{
		cout << "Считывает числва из файла и выводит их в порядке возрастания, подсчитывая дубликаты и выводя их количество.\n"; 
		
		string iname = "Ex11.16_in.txt";
		ifstream ifs{iname};
		if(!ifs) error("Невозможно открыть файл ", iname);

		vector<double> vNumbers;
		double d = 0.0;
		while(ifs)
	   	{
			ifs >> d;
			if (ifs) vNumbers.push_back(d);	
			if(ifs.fail()) 
			{	
				ifs.clear();
				char c;
				ifs >> c;
				if (isspace(c) || c == '\000') break;
				else error("Ошибка формата данных в файле ", iname);
			}
		}

		sort(vNumbers.begin(),vNumbers.end());

		vector<RepeatNumber> vRepeatNumbers;
		double last;
		for(double x : vNumbers) 
		{
			double temp = x;
			if (temp != last)
			{
				vRepeatNumbers.push_back(temp);
				last = temp;
			} else ++vRepeatNumbers.back().rCount;
		}
		
		for(RepeatNumber rn : vRepeatNumbers) cout << rn.number << ' ' << rn.rCount << endl;

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
