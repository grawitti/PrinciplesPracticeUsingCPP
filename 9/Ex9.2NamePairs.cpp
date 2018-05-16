/**
 Дата создания: 19.01.18
 Автор: Руслан
 Назначение: Выводит в консоль введеные (имя, возраст) в порядке возрастания. 
 Глава 9, упр. 2, стр. 388, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

const string STOP = "."; // строка для прекращения ввода имен

//Приветствие
void welcomeMessage () {
	cout << "Выводит в консоль введеные пары (имя, возраст) в порядке возрастания.\n";
}

class NameAges {
	vector<string> name;
	vector<int> age;
	vector<int> ageS;
public:
	bool readName(vector<string>& name);
	void readAge(const vector<string>& name, vector<int>& age);
	void sorting (vector<string>& name, vector<int>& age);
	void print(const vector<string>& name, const vector<int>& age);
	friend ostream& operator<<(ostream& os, const vector<string>& name, const vector<int>& age);

	NameAges(vector<string> vs) : name{vs} { }
	NameAges(vector<string> vs, vector<int> vi) : name{vs}, age{vi} { }
	NameAges(vector<string> vs, vector<int> vi, vector<int> vis) : name{vs}, age{vi}, ageS{vis} { }
};

//Сортировка вектора name, а так же вектора age в соответствии с name
void NameAges::sorting (vector<string>& name, vector<int>& age) {
	vector<string> vs = name;
	vector<int> vi{};
	sort(name.begin(),name.end());
	for (int i = 0; i < name.size(); ++i) {
		for (int j = 0; j < vs.size(); ++j) {
			if (name[i] == vs[j]) vi.push_back(age[j]);
		}
	}
	age = vi;
}

//
ostream& operator<<(ostream& os, const vector<string>& name, const vector<int>& age) {
	os << endl;
	for (int i = 0; i < name.size(); ++i) {
		os << name[i] << " - " << age[i];
		if (i != name.size()-1) cout << ", ";
		os << endl;
	}
}

//Вывод вектора в консоль
void NameAges::print(const vector<string>& name, const vector<int>& age) {
	cout << endl;
	for (int i = 0; i < name.size(); ++i) {
		cout << name[i] << " - " << age[i];
		if (i != name.size()-1) cout << ", ";
		cout << endl;
	}
}

//Ввод имен из потока cin в вектор string vs, изменяет вектор передаваемый по ссылке
bool NameAges::readName(vector<string>& vs) {
	string temp = "";
	cin >> temp;
	if (temp == STOP) return true;
	vs.push_back(temp);
	return false;
}

//Ввод возраста из потока cin, для имен из вектора string vs, в вектор int age vi, изменяет вектор vi передаваемый по ссылке
void NameAges::readAge(const vector<string>& vs, vector<int>& vi) {
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
		NameAges na{names};

    keep_window_open();
		bool end = false;
		for (int i = 0; !end; ++i) {
			cout << "\nВведите " << i+1 << " имя (. для завершения ввода): ";
			end = na.readName(names);
		}

		vector<int> ages;
		for (string x : names) {
			cout << "\nСколько лет " << x << "? ";
			na.readAge(names,ages);
		}
		na.print(names,ages);

		na.sorting(names,ages);
		na.print(names,ages);
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
