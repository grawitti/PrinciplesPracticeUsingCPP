/**
 Дата создания: 22.01.18
 Автор: Руслан
 Назначение: Выводит в консоль введеные (имя, возраст) в порядке возрастания. 
 Глава 9, упр. 3, стр. 388, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
	bool readName();
	void readAge();
	void sorting ();
	vector<string> getName() const { return name; }
	vector<int> getAge() const  { return age; }
	friend ostream& operator<<(ostream& os, const vector<string>& name);
};

//Сортировка вектора name, а так же вектора age в соответствии с name
void NameAges::sorting () {
	vector<string> vs = getName();
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
ostream& operator<<(ostream& os, const NameAges& na) {
	vector<string> name = na.getName();
	vector<int> age = na.getAge();
	for (int i = 0; i < name.size(); ++i) {
		os << name[i] << " - " << age[i];
		if (i != name.size()-1) os << ", ";
	}
	return os;
}

//Ввод имен из потока cin в вектор string vs, изменяет вектор передаваемый по ссылке
bool NameAges::readName() {
	string temp = "";
	cin >> temp;
	if (temp == STOP) return true;
	name.push_back(temp);
	return false;
}

//Ввод возраста из потока cin, для имен из вектора string vs, в вектор int age vi, изменяет вектор vi передаваемый по ссылке
void NameAges::readAge() {
	char ch = '0';
	while (true) {
		cin >> ch;
		switch(ch) {
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
				cin.putback(ch);
				int temp;
				cin >> temp;
				age.push_back(temp);
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

		NameAges na{};

		bool end = false;
		for (int i = 0; !end; ++i) {
			cout << "\nВведите " << i+1 << " имя (. для завершения ввода): ";
			end = na.readName();
		}

		for (string x : na.getName()) {
			cout << "\nСколько лет " << x << "? ";
			na.readAge();
		}

		cout << "Не отсортированный вектор: " << na << endl;

		na.sorting();
		cout << "Отсортированный вектор: "  << na << endl;
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
