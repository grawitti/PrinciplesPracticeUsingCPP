/**
 Дата создания: 21.05.18
 Автор: Руслан
 Назначение: Переворачивает слова в строке обратным порядком..
 Глава 11, упр. 12, стр. 460, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример: One two three = three two One
**/

#include "../std_lib_facilities.h"

// Меняет порядок следования слов в строках на обратный
string turnWords(string& s) 
{
	stringstream ss{s};
	vector<string> vs;
	for (string temp; ss ; )
	{
		temp = "";
		ss >> temp;
		if(temp != "") vs.push_back(temp);
	}
	string result;
	if (vs.size() > 1) 
	{
		for (int i = vs.size()-1; i >= 0; --i) result += vs[i] + " ";
		return result + '\n';
	}
	else return result = s + '\n';
}

int main() {
	try 
	{
		cout << "Переворачивает слова в строке обратным порядком..\n"; 

		string iname = "Ex11.13_in.txt";
		ifstream ifs{iname};
		if (!ifs) error("Невозможно открыть файл для чтения ", iname);

		string inputString;
		vector<string> vs;
		string last;
		while (ifs) 
		{
			getline(ifs,inputString);
			if (inputString != last) vs.push_back(inputString);
			last = inputString;
		}
	
		vector<string> turnedVs;
		for(string s : vs) 
		{
			string turnedString = turnWords(s);
			turnedVs.push_back(turnedString);
		}

		string oname = "Ex11.13_out.txt";
		ofstream ofs{oname};
		if (!ofs) error("Невозможно открыть файл для чтения ", oname);

		for (string s : turnedVs) ofs << s;
		
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
