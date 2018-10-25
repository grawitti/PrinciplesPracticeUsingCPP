/**
 Дата создания: 31.10.17
 Автор: Руслан
 Назначение: Программа угадывает число от 1 до 100, максимум с 7 попыток, задавая вопросы.
 Пример:
**/

#include "../std_lib_facilities.h"

// Инициализация глобальных переменных и констант
int constexpr maxRange = 100; // размер диапазона отгадываемых чисел
int tryCount = 0;
vector<int> num;

// Функция заполнения вектора int целыми числами от 1 - range
vector<int> fillingVector (vector<int> v, int range) {
  for (int i = 1; i <= range; i++) v.push_back(i);
  return v;
}

// Печать элементов вектора int в поток вывода (принимает вектор int v)
void printVector (vector<int> v) {
	for (int x : v) cout << x << ",";
	cout << "\n";
}

// Функция печати текстовых сообщений в поток вывода (char c - метка сообщения)
void printMessage (char c) {
	switch (c) {
		case 's': // Start - запуск
			cout << "Программа угадывает число от 1 до 100, максимум с 7 попыток, задавая вопросы.\n"
       		 << "Загадайте число, введите s и нажмите 'Enter' для старта\n";      
			break;
		case '?': // ? - Отгадал?
		 	cout << "Загаданное число: " << num[num.size()/2] << "? (y - да, n - нет)\n"; 
			break;
		case 'n': // No - Нет, не отгадал, вопрос: Загаданное число меньше: х
			cout << "Загаданное число меньше: " << num[num.size()/2] << "? (y - да, n - нет)\n"; 
			break;
		case 'y': // Yes - Да, вывод результатов
			cout << "Ура! Я отгадал загаданное число: " << num[num.size()/2] << " с " << tryCount << " попытки." << "\n";
			break;
		case 't': // Try - Попытка
			cout << "Попытка: " << tryCount << "\n";
			break;
		default:
			cout << "Ошибка: Вы ввели не корректный ответ: " << c << "\n";
			break;
	}
}

// Функция удаления половины вектора (принимает вектор int и метку end bool - удаления с конца вектора)
vector<int> eraseHalfVector (vector<int> v, bool end) {
	if (end) v.erase(v.end() - v.size() / 2, v.end());
		else v.erase(v.begin(), v.begin() + v.size() / 2);
	return v;
}

int main() {
	// Инициализация переменных
	char answer = ' ';
  num = fillingVector(num, maxRange); // Заполнение вектора
  printMessage('s'); // Приветствие
  // Запуск начала отгадывания
  for ( ; answer != 's' ; ) {
  		cin >> answer;
	  	if (answer != 's') printMessage(answer);
  	}
// Отгадывание загаданного числа
 	for (;;) {
 		++tryCount;
 		printVector(num);
 		printMessage('t'); // Попытка
 		for (;;) {
 			printMessage('?'); // Отгадал?
  		cin >> answer; 
			switch (answer) {
		  case 'y':
		  	printMessage('y'); // Да, вывод результатов
		  	return 0;
		  case 'n':
		  	printMessage('n'); // Нет, не отгадал, вопрос: Загаданное число меньше: х
		  	for (;;) {
		  	cin >> answer;
		  	if (answer == 'y') {num = eraseHalfVector(num, true); break;} // Если меньше то сокращаем вектор с середины до конца
		  		else if (answer == 'n') {num = eraseHalfVector(num, false); break;} // Если больше то сокращаем с начала до середины
		  			else printMessage(answer); // Вывод сообщения об ошибке
		  	}
		  	break;
		  default:
		  	printMessage(answer); // Вывод сообщения об ошибке
		  	break;  		
			}	
  	}
 	}			
  return 0;
}
