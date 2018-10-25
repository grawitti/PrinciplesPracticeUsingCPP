//#include<iostream>
//#include<cmath>
//#include<vector>
#include"std_lib_facilities.h"
using namespace std;

double ctok(double c) // Преобразует температуру
  {                   // в градусах Цельсия
                      // в температуру в градусах Кельвина
    if (c < -273.15) 
    {
      cerr << "Температура не может быть менее абсолютного нуля: -273.15 С\n";
      return -1;
    }
    double k = c + 273.15;
    return k;
  }

int main () {
  try {
    double c;         // Объявляем входную переменную
    cin >> c;         // Вводим температуру

    double k = ctok(c);   // Преобразовываем температуту
    cout << k << '\n';    // Выводим температуру
  }
  catch (exception& e) {
    cerr << "Ошибка" << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Неизвестное исключение!" << '\n';
    return 2;
  }
}
