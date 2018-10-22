/**
 Дата создания: 21.05.18
 Автор: Руслан
 Назначение: Считывает числа из одного файла и записывает их с научной точностью в другой файл.
 Глава 11, упр. 15, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

int main() {
	try 
	{
		cout << "Считывает числа из одного файла и записывает их с научной точностью в другой файл.\n"; 
		
		string iname = "Ex11.15_in.txt";
		ifstream ifs{iname};
		if(!ifs) error("Невозможно открыть файл ", iname);

		vector<double> vDigits;
		double d = 0.0;
		while(ifs)
	   	{
				ifs >> d;
				vDigits.push_back(d);	
				//if(ifs.fail()) error("Ошибка формата данных в файле ", iname);
		}

		string oname = "Ex11.15_out.txt";
		ofstream ofs{oname};
		if(!ofs) error("Невозможно открыть файл ", oname);

		for (double d : vDigits) ofs << setw(5) << setprecision(8) << scientific << d << ' '; 


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
