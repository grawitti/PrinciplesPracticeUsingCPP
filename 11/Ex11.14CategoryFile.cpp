/**
 Дата создания: 21.05.18
 Автор: Руслан
 Назначение: Считывает текстовый файл и записывает количество символов каждой категории в другой файл.
 Глава 11, упр. 14, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//
vector<int> calcCategory(string& s) 
{
	vector<int> vCategories(11);
	for (char& c : s) 
	{
		if (isspace(c)) ++vCategories[0]; //"|пробельный символ\t";
		if (isalpha(c)) ++vCategories[1]; //"|буква\t";
		if (isdigit(c)) ++vCategories[2]; //cout << "|десятичная цифра\t";
		if (isxdigit(c)) ++vCategories[3]; //cout << "|16 цифра\t";
		if (isupper(c)) ++vCategories[4]; //cout << "|буква в верхнем регистре\t";
		if (islower(c)) ++vCategories[5]; //cout << "|буква в нижнем регистре\t";
		if (isalnum(c)) ++vCategories[6]; //cout << "|буква или 10я цифра\t";
		if (iscntrl(c)) ++vCategories[7]; //cout << "|символ ASCII\t";
		if (ispunct(c)) ++vCategories[8]; //cout << "|ни буква, ни цифра ни разделитель, ни невидимый упр. символ\t";
		if (isprint(c)) ++vCategories[9]; //cout << "|выводится на печать\t";
		if (isgraph(c)) ++vCategories[10]; //cout << "|isalpha() || isdigit() || isipunct()\t";
	}
	return vCategories;
}

int main() {
	try 
	{
		cout << "Считывает текстовый файл и записывает количество символов каждой категории в другой файл.\n"; 
		
		string iname = "Ex11.14_in.txt";
		ifstream ifs{iname};
		if(!ifs) error("Невозможно открыть файл ", iname);

		string inputString;
		char c;
		while(ifs)
	   	{
			c = ifs.get();
			inputString += c;		
		}
		
		vector<int> vCategory = calcCategory(inputString);

		string oname = "Ex11.14_out.txt";
		ofstream ofs{oname};
		if(!ofs) error("Невозможно открыть файл ", oname);

		ofs << "Пробельных символов: " << vCategory[0] << endl
			<< "Букв: " << vCategory[1] << endl 
			<< "Десятичных цифр: " << vCategory[2] << endl 
			<< "Шестнадцатеричных цифр: " << vCategory[3] << endl 
			<< "Букв в верхнем регистре: " << vCategory[4] << endl 
			<< "Букв в нижнем регистре: " << vCategory[5] << endl 
			<< "Букв или 10я цифра: " << vCategory[6] << endl 
			<< "Символов ASCII: " << vCategory[7] << endl 
			<< "Спец. символов: " << vCategory[8] << endl 
			<< "Выводится на печать: " << vCategory[9] << endl 
			<< "isalpha() || isdigit() || isipunct(): " << vCategory[10] << endl; 

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
