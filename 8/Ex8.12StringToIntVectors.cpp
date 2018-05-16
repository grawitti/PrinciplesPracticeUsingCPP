/**
 Дата создания: 12.01.18
 Автор: Руслан
 Назначение: Выводит количество символов всех элементов вектора строк,
 находит самую длинную и короткую строки, а так же лексикографически первую и последнюю строки.
 Глава 8, упр. 12, стр. 350, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "\nВыводит количество символов всех элементов вектора строк,\n"
 			 << "находит самую длинную и короткую строки, а так же\n"
 			 <<	"лексикографически первую и последнюю строки.\n";
}

// Выводит в поток cout вектор целых чисел - vi и метку, string - s
void printVectorI (const string& s, const vector<int>& vi) {
	cout << '\n' << s << "\n";
	for (int x : vi) cout << x << '\t';

	cout << endl;
}

// Выводит в поток cout вектор строк - vs и метку, string - s
void printVectorS (const string& s, const vector<string>& vs) {
	cout << '\n' << s << "\n";
	for (string x : vs) cout << x << '\t';

	cout << endl;
}

//Возвращает вектор - int, содержаций количество символов в каждом элементе вектора строк - vs
vector<int> getNamberOfChars(const vector<string>& vs) {
	vector<int> vi;
	for (string s : vs) vi.push_back(s.size());
	return vi;
}

//Возвращает самую длинную строку вектора
string getLongString (const vector<string>& vs) {
	int max;
	string lString;
	for(string x : vs) {
		if (x.size() > max) {
			max = x.size();
			lString = x;
		}
	}
	return lString;
}

//Возвращает самую короткую строку вектора
string getShortString (const vector<string>& vs) {
	int min;
	string sString;
	for(int i = 0; i < vs.size(); ++i) {
		if (i == 0) min = vs[i].size();
		if (vs[i].size() < min) {
			min = vs[i].size();
			sString = vs[i];
		}
	}
	return sString;
}

int main() {
	try {
		welcomeMessage();
		vector<string> testWords {"What","you","qq","say","about","my","q","job","q","?"};
		printVectorS("Заданный вектор строк:",testWords);
		vector<int> testInt = getNamberOfChars(testWords);
		printVectorI("Количество символов:",testInt);
		cout << "Самое длинное слово:\t" << getLongString(testWords) << endl;
		cout << "Самое короткое слово:\t"  << getShortString(testWords) << endl;
		sort(testWords.begin(),testWords.end());
		printVectorS("Заданный отсортированный вектор",testWords);
		cout << "Лексикографически первая строка:\t" << testWords[0] << endl;
		cout << "Лексикографически последняя строка:\t" << testWords[testWords.size()-1] << endl;
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
