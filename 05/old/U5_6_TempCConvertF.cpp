//#include<iostream>
//#include<cmath>
//#include<vector>
#include"std_lib_facilities.h"
using namespace std;

double ctok(double c) // Преобразует температуру
  {                   // в градусах Цельсия
                      // в температуру в градусах Фарингейта
    if (c < 0) 
    {
      error(": Температура не может быть менее абсолютного нуля: 0 K или -273.15 С");
    }
    double f = 1.8*c+32; // Формула перевода в градусы Фаренгейта: F = 9/5*C+32, где С градусы по Цельсию
    return f;
  }

int main () {
  try {
    double c;         // Объявляем входную переменную
    cin >> c;         // Вводим температуру
    double f = ctok(c);   // Преобразовываем температуту
    cout << f << '\n';    // Выводим температуру
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
