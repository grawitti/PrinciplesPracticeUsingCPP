/**
 Дата создания: 15.05.18
 Автор: Руслан
 Назначение: Разделение строки на подстроки используя пробел в качестве разделителя.
 Глава 11, упр. 9, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Разбивает строку s на вектор подстрок
vector<string> split(string& s)
{
	vector<string> vs;
	stringstream ss{s};
	for(string temp; ss >> temp; ) vs.push_back(temp);
	return vs;
}

void printVector(const vector<string>& vs)
{
	for(string s : vs) cout << s << endl;
}

int main() {
	try 
	{
		cout << "Разделение строки на подстроки используя пробел в качестве разделителя.\n"; 
		cout << "Введите строку: ";
			
		string input;
		getline(cin,input);

		vector<string> vs;
		vs = split(input);

		cout << "Подстроки введенной строки:\n";
		printVector(vs);

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
