/**
 Дата создания: 22.11.17
 Автор: Руслан
 Назначение: Игра  "Быки и коровы". Программа хранит вектор из 4х  различных чисел от 1-9 (например: 1234, но не 2233).
 Пользователь должен угадать это число. Допустим программа загадала 1234, а пользователь назвал 1359,
 программа должна ответить "1 бык и 1 корова", поскольку пользователь угадал одну цифру(1) в правильной позиции (бык)
 и одну правильную цифру (3) в неправильной позиции (корова). Угадывание продолжается пока пользователь не получит 4 быков,
 т.е. не угадает все 4 цифры в правильных позициях.
 Пример:
**/

#include "../std_lib_facilities.h"
#include <cstdlib>
#include <ctime>

// Генерирует и возвращает псевдослучайное число int от 1 - 9
int getRandomNum (int x) {
	srand(time(NULL)/x);
	return 1 + rand() % 9;	// 1 - 9
}

// Заполнение вектора - v, n - случайными и не повторяющихся числами, используя функцию getRandomNum().
// Использует переборы МЕДЛЕННО!
/*
vector<int> getRandomVec (vector<int> v, int n) {
	for (int i = 0; i < n; ++i) {
		int checkRepeat = getRandomNum();
		if (v.size()) {
			for (int i = 0; i < v.size(); ++i) {
				if (v[i] != checkRepeat) {
					if (i == v.size()-1) {
						break;
					} else continue;
				}
				checkRepeat = getRandomNum();
				i = -1;
				continue;
			}
			v.push_back(checkRepeat);
		} else v.push_back(checkRepeat);
	}
	return v;
}
*/

// Вывод вектора целых чисел в консоль через пробел
void printVector(vector<int> v) {
	for (int x : v) {
		cout << x << ' ';
	}
	cout << endl;
}

// Заполнение вектора - v(4) случайными и не повторяющихся числами, используя функцию getRandomNum().
// Использует сравнения, БЫСТРО, но поддеоживает только 4 разряда
vector<int> getRandomVec2 () {
	vector<int> v;
	for (int i = 0; i < 4; ++i) v.push_back(getRandomNum(i+1));
	if (v.size() != 4) error("Вектор имеет не 4 разряда.");
	for (int i = 1; v[0] == v[1] || v[0] == v[2] || v[0] == v[3]; ++i) {
		printVector(v);
		v[0] = getRandomNum(i);
	}
	for (int i = 1; v[1] == v[0] || v[1] == v[2] || v[1] == v[3]; ++i) {
		printVector(v);
		v[1] = getRandomNum(i);
	}
	for (int i = 1; v[2] == v[0] || v[2] == v[1] || v[2] == v[3]; ++i) {
		printVector(v);
		v[2] = getRandomNum(i);
	}
	return v;
}

// Проверка 4х разрядного числа на повторяющиеся числа в разрядах
void checkRepeat (vector<int> v) {
	if (v.size() != 4) error("Вектор имеет не 4 разряда.");
	if (v[0] == v[1] || v[0] == v[2] || v[0] == v[3]) error("Числа не должны повторяться!");
	if (v[1] == v[2] || v[1] == v[3]) error("Числа не должны повторяться!");
	if (v[2] == v[3]) error("Числа не должны повторяться!");
}

// Разделяет число по десяткам и записывает в вектор размера s:  int n = 1234 => vector<int> = {1, 2, 3, 4}
vector<int> getVector (int n, int s) {
	vector<int> v(s);
	for (int i = v.size()-1; i >= 0; --i) {
		v[i] = n%10;
		n/=10;
	}
	checkRepeat(v);
	return v;
}

// Поиск полных совпадений чисел в двух векторах int v и v2
int getFullConsilience(vector<int> v, vector<int> v2) {
	int n = 0;
	if (v.size() != v2.size() || !(v.size())) error("Векторы v и v2 разного размера или пустой вектор");
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == v2[i]) ++n;
	}
	return n;
}

// Поиск совпадений чисел в двух векторах int v и v2
int getConsilience(vector<int> v, vector<int> v2) {
	int n = 0;
	if (v.size() != v2.size() || !(v.size())) error("Векторы v и v2 разного размераили пустой вектор");
	for (int x : v2) {
		for (int x2 : v) {
			if (x == x2) {
				++n;
				break;
			}
		}
	}
	return n;
}

// Возвращыет переданую строку string s, добавляя окончания а, ов в соответствии с значением - int x и родом - bool m
string printBullsCows (string s, int x, bool m) {
	if (x < 0) error("printBullsCows()");
	if (m) { // Мужской род
		if (x == 0) return s+"ов";
		if (x == 1) return s;
		if (x > 1) return s+"a";
	} else { // Женский род
		if (x == 0) return s;
		if (x == 1) return s+"а";
		if (x > 1) return s+"ы";
	} return s;
}

int main() {
	try {
		bool again = true;
		for (;again || cin.fail();) {
			if (cin.fail()) error("Ошибка ввода");
			vector<int> secretVec(4);
			secretVec = getRandomVec2();
			printVector(secretVec); // Вывод загаданного числа
			int bulls = 0, cows = 0;
			cout << "Игра 'Быки и коровы'\n"
					 << "Я загадал 4х значное число (например: 1234, но не 1122), попробуй его отгадать:\n"
					 << "Введи 4х значное число и нажми 'Enter'\n";
			int tempNum;
			vector<int> tempVec;
			for (;cin >> tempNum;) {
				if (cin.fail()) error("Вы ввели не целое число.");
				again = false;
				// Минимальное 4х число, из не повторяющихся чисел от 1-9 = 1234, а максимольное = 9876
				if (tempNum < 1234 || tempNum > 9876) error("Введеное значение меньше 1234 или больше 9876");
				tempVec = getVector(tempNum, 4);
				bulls = getFullConsilience(secretVec, tempVec);
				cows = getConsilience(secretVec, tempVec) - bulls;
				cout << bulls << " " << printBullsCows("бык", bulls, true) << ", " << cows << " "
						 << printBullsCows("коров", cows, false) << " \n";
				if (bulls == 4) {
					cout << "Поздравляю! Ты угадал(а).\n"
					 		 << "Сыграем ещё? y - Да, n - Нет.\n";
					char sumAll;
					for (;cin >> sumAll;) {
						if (cin.fail()) error("Ошибка ввода");
						cin.clear();
						char temp = cin.get();
						if (!(temp == 'y' || temp == 'n')) break;
						cerr << "Ответ может быть только y - Да или n - Нет!\n";
					}
					switch (sumAll) {
						case 'y': {
							again = true;
							break;
						}
						case 'n': {
							return 0;
						}
						default: {
							error("Ответ может быть только y - да или n - нет\n");
							return 0;
						}
					}
					break;
				}
			}
			cout << endl;
		}
		return 0;
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
