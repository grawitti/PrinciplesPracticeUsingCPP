/**
 Дата создания: 15.05.18
 Автор: Руслан
 Назначение: Разделение строки на подстроки используя пробел и указанный символ в качестве разделителя.
 Глава 11, упр. 11, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

// Разбивает строку s на вектор подстрок
vector<string> split(string& s, const char& delim)
{
	vector<string> vs;
	string temp;
	s += ' ';
	for(char& c : s)
	{
		if(isspace(c) || c == delim) {
			vs.push_back(temp);
			temp = "";
		} else temp += c;
	}
	return vs;
}

void printVector(const vector<string>& vs)
{
	for(string s : vs) cout << s << endl;
}

int main() {
	try 
	{
		cout << "Разделение строки на подстроки используя пробел и указанный символ в качестве разделителя.\n"; 
		cout << "Введите строку: ";
			
		string input;
		getline(cin,input);

		vector<string> vs;
		vs = split(input,';');

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
