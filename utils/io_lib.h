#include<iostream>
//#include<iomanip>
//#include<fstream>
#include<sstream>
//#include<cmath>
//#include<cstdlib>
#include<string>
//#include<list>
//#include <forward_list>
#include<vector>
//#include<unordered_map>
//#include<algorithm>
//#include <array>
//#include <regex>
//#include<random>
//#include<stdexcept>

using namespace std;

// Очистка потока cin, до символа: \n
void clearCin() {
  char с = 'c';
  while (с != '\n') с = cin.get();
}

// Очистка потока - ss по ссылке
void stringstreamClear(stringstream& ss) {
	ss.str("");
	ss.clear();
}

// Обаботка ввода из потока cin занчения - int
int getIntFromCin () {
  char c = '0';
  while (true) {
    cin >> c;
    switch (c) {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
        cin.putback(c);
        int i;
        cin >> i;
        clearCin();
        return i;       
      }
      default:
        cerr << "Введите целое положительное число:\n";
        clearCin();
        break;
    }  
  }
}

// Обаботка ввода из потока cin занчения - double
int getDoubleFromCin () {
  char c = '0';
  while (true) {
    cin >> c;
    switch (c) {
      case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
        cin.putback(c);
        double d;
        cin >> d;
        clearCin();
        return d;       
      }
      default:
        cerr << "Введите положительное число:\n";
        clearCin();
        break;
    }  
  }
}

// Обаботка ввода из потока cin занчения - string
string getStringFromCin () {
 char line[256];
  cin.getline(line, 256);
  return line;
}

// Если char c цифра возвращает true
bool isNumber (const char& c) {
	//tempInt = atoi(vs[i].c_str()); // Вариант с использованием функции atoi() преобразования строки в число + функции c_str() строки в массив символов
	switch(c) {
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
			return true;
			break;
		}
		default:
			return false;
		}
}

// Запрос нажать y или n в ответ на вопрос строки s
bool requestYorN (const string& s) {
	cout << s << " (y - ДА или n - НЕТ)" << endl;
 	char c = 'y';
 	cin.get(c);
 	switch (c) {
    	case 'y': {
      		clearCin();
      		return true;
    	}
    	case 'n': {
      		clearCin();
      		return false;
    	}
    	default: {
      		cerr << "Введите y или n.";
      		exit(1);
    	}
  	}
  return true;
}