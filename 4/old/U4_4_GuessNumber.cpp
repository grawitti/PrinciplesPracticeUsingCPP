#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// Объявление глобальных переменных
char check;
int beginPoint = 1;
int endPoint = 100;
vector<int> numbers;
int counter = 1;

// Функция заполняющая вектор типа int цифрами от bPoint до ePoint
vector<int> vectorFuller(vector<int> vec, int bPoint, int ePoint) {
	for (int i = bPoint; i <= ePoint; i++) { vec.push_back(i); }
	return vec;
}

// Функция выводит элементы вектора на консоль - распечатывает
void printVector (vector<int> vec) {
	cout << "Ваше число одно из: " << '\n' << '\n';
	for (int x : vec) cout << x << '\t';
	cout << '\n' << '\n';
}

// Функция вывода сообщения пользователю
void sendMessage (vector<int> vec) {
	cout << "Ваше число: " << vec[vec.size()/2] << "? Введите символ: y - если ДА. " << '\n'
			 << "Если нет, то подскажите оно больше: " << vec[vec.size()/2] << "?" << '\n'
			 << "Введите символ: > если больше, или символ: < если меньше." << '\n';
}
//Функция завершения игры при победе
void ifYes() {
	cout << '\n' << '\n' << "!!!УРА!!!" << '\n' << '\n' << "Я угадал загаданное Вами число с "
			 << counter <<" Попытки!!!" << '\n' << '\n';
}

//Функция сокращения вектора при ответе n - НЕТ
void ifLess() {
	endPoint = numbers[numbers.size()/2];
	numbers.clear();
	numbers = vectorFuller(numbers, beginPoint, endPoint);
	printVector(numbers);
	counter++;
	cout << '\t' << counter <<" Попытка" << '\n' << '\n';
	sendMessage(numbers);
	cin >> check;
}

//Функция сокращения вектора при ответе y - ДА
void ifMore() {
beginPoint = numbers[numbers.size()/2];
numbers.clear();
numbers = vectorFuller(numbers, beginPoint, endPoint);
printVector(numbers);
counter++;
cout << '\t' << counter <<" Попытка" << '\n' << '\n';
sendMessage(numbers);
cin >> check;
}

// Основная функция
int main () {
	cout  << '\n' << '\n' << "Спорим я угадаю любое загаданное Вами число от 1 до 100, максимум с 7 попытки?" << '\n'
			 << "Загадайте число от 1 до 100, введите что угодно и нажмите Enter для продолжения."  << '\n' << '\n';
	cin >> check;
	numbers = vectorFuller(numbers, beginPoint, endPoint);
	cout << '\n' << '\n' << '\t' << counter <<" Попытка" << '\n' << '\n';
	sendMessage(numbers);
	cin >> check;
	for (int i = 0; i < 7; i++) {
		if (i == 6 || numbers.size() == 3) {
			if (check == 'y') {
				ifYes();
				return 0;
			} else if (check == '>') {
				cout << "Ваше загаданное число равно: " << numbers[numbers.size()/2+1] << '\n';
				return 0;
			} else if (check == '<') {
				cout << "Ваше загаданное число равно: " << numbers[numbers.size()/2-1] << '\n';
				return 0;
			} else {
				cout << "Ошибка!!! Вы ввели не корректное значение: " << check << '\n';
				return 0;
				}
		}
		if (check == 'y') {
			ifYes();
			return 0;
		} else if (check == '>') {
			ifMore();
		} else if (check == '<') {
			ifLess();
		} else {
			cout << "Ошибка!!! Вы ввели не корректное значение: " << check << '\n';
			return 0;
			}
	}
}
