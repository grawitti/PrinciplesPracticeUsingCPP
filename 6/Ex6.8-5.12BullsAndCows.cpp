/**
 Дата создания: 01.12.17
 Автор: Руслан
 Назначение: Игра  "Быки и коровы". Программа хранит вектор из 4х  различных букв от a-j (например: abcd, но не aabb).
 Пользователь должен угадать это число. Допустим программа загадала abcd, а пользователь назвал acij,
 программа должна ответить "1 бык и 1 корова", поскольку пользователь угадал одну букву(1) в правильной позиции (бык)
 и одну правильную букву (3) в неправильной позиции (корова). Угадывание продолжается пока пользователь не получит 4 быков,
 т.е. не угадает все 4 буквы в правильных позициях.
 Пример:
**/

#include "../std_lib_facilities.h"
#include <cstdlib>
#include <ctime>

// Глобальные переменные
const vector<char> letters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}; // список букв

// Генерирует и возвращает псевдослучайное число int от 0 - 9
int getRandomNum (int x) {
	srand(time(NULL)/x);
	return rand() % 9;	// 0 - 9
}

// Вывод вектора char в консоль через пробел
void printVector(vector<char> v) {
	for (char x : v) {
		cout << x << ' ';
	}
	cout << endl;
}

// Заполнение вектора - v(4) случайными и не повторяющихся буквами, используя функцию getRandomNum().
// Использует сравнения, БЫСТРО, но поддеоживает только 4 разряда
vector<char> getRandomVec2 () {
	vector<char> v;
	for (int i = 0; i < 4; ++i) v.push_back(letters[getRandomNum(i+1)]);
	if (v.size() != 4) error("Вектор имеет не 4 разряда.");
	for (int i = 1; v[0] == v[1] || v[0] == v[2] || v[0] == v[3]; ++i) {
		printVector(v);
		v[0] = letters[getRandomNum(i)];
	}
	for (int i = 1; v[1] == v[0] || v[1] == v[2] || v[1] == v[3]; ++i) {
		printVector(v);
		v[1] = letters[getRandomNum(i)];
	}
	for (int i = 1; v[2] == v[0] || v[2] == v[1] || v[2] == v[3]; ++i) {
		printVector(v);
		v[2] = letters[getRandomNum(i)];
	}
	return v;
}

// Поиск полных совпадений чисел в двух векторах char v и v2
int getFullConsilience(vector<char> v, vector<char> v2) {
	int n = 0;
	if (v.size() != v2.size() || !(v.size())) error("Векторы v и v2 разного размера или пустой вектор");
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == v2[i]) ++n;
	}
	return n;
}

// Поиск совпадений чисел в двух векторах char v и v2
int getConsilience(vector<char> v, vector<char> v2) {
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

// Ввод последовательности символов с клавиатуры в вектор char v
vector<char> inputCharsVec() {
	char t;
	vector<char> v;
	cin.clear();
	for (int k = 0 ; k < 4; ++k) {
		t = cin.get();
		if (cin.fail()) error("Вы ввели что то не то.");
		if (t != '\n' && t < 'a' || t > 'j') error("Введеное буква меньше a или больше j");
		if (t != '\n') v.push_back(t);
	}
	cin.ignore();
	printVector(v);
	return v;
}


int main() {
	try {
		bool again = true;
		for (;again || cin.fail();) {
			if (cin.fail()) error("Ошибка ввода");
			vector<char> secretVec(4);
			secretVec = getRandomVec2();
			printVector(secretVec); // Вывод загаданного числа
			int bulls = 0, cows = 0;
			cout << "Игра 'Быки и коровы'\n"
					 << "Я загадал последовательность из 4 символов от a-j (например: abcd, но не aabb), попробуй отгадать:\n"
					 << "Введи 4 символа от a-j и нажми 'Enter'\n";
			vector<char> tempVec;
			while (true) {
				again = false;
				tempVec = inputCharsVec();
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
