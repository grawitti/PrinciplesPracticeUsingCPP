/**
 Дата создания: 11.01.18
 Автор: Руслан
 Назначение: Выводит в консоль введеные 5 пар (имя, возраст) в порядке возрастания. 
 Глава 8, упр. 7, стр. 349, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

const string STOP = "."; // строка для прекращения ввода имен

//Приветствие
void welcomeMessage () {
	cout << "Выводит в консоль введеные пары (имя, возраст) в порядке возрастания.\n";
}

//Выводит возраст  из вектора - vi, по имени - s, из вектора - vs
int getAgeByName (const vector<string>& vs, const vector<int>& vi, const string& s) {
	for (int i = 0; i < vs.size(); ++i) {
		if (vs[i] == s) return vi[i];
	}
}

//Вывод вектора в консоль
void printVectors(const vector<string>& vss, const vector<string>& vs, const vector<int>& vi) {
	cout << endl;
	for (int i = 0; i < vss.size(); ++i) {
		cout << vss[i] << " - " << getAgeByName(vs,vi,vss[i]);
		if (i != vss.size()-1) cout << ", ";
		cout << endl;
	}
}

//Ввод имен из потока cin в вектор string vs, изменяет вектор передаваемый по ссылке
bool getName(vector<string>& vs) {
	string temp = "";
	cin >> temp;
	if (temp == STOP) return true;
	vs.push_back(temp);
	return false;
}

//Ввод возраста из потока cin, для имен из вектора string vs, в вектор int age vi, изменяет вектор vi передаваемый по ссылке
void getAge(const vector<string>& vs, vector<int>& vi) {
	char ch = '0';
	while (true) {
		cin >> ch;
		switch(ch) {
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
				cin.putback(ch);
				int temp;
				cin >> temp;
				vi.push_back(temp);
				return;
			}
			default: 
				cerr << "Ошибка! Возраст должен быть положительным числом: ";
				char ignore = 'c';
				while (ignore != '\n') {
					ignore = cin.get();
				}
				break;
		}
	}
}

int main() {
	try {
		welcomeMessage();
		vector<string> names;
		bool end = false;
		for (int i = 0; !end; ++i) {
			cout << "\nВведите " << i+1 << " имя (. для завершения ввода): ";
			end = getName(names);
		}
		vector<int> ages;
		for (string x : names) {
			cout << "\nСколько лет " << x << "? ";
			getAge(names,ages);
		}
		vector<string> sortNames = names;
		sort(sortNames.begin(),sortNames.end());
		printVectors(sortNames,names,ages);
	}
		catch (exception& e) {
			cerr << "\nОшибка: " << e.what() << endl;
			return 1;
		}
		catch (...) {
			cerr << "\nНеизвестное исключение!\n";
			return 2;
		}
}
