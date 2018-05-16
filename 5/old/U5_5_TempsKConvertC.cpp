//#include<iostream>
//#include<cmath>
//#include<vector>
#include"std_lib_facilities.h"
using namespace std;

double ctok(double k) // Преобразует температуру
  {                   // в градусах Кельвина
                      // в температуру в градусах Цельсия
    if (k < 0) 
    {
      error(": Температура не может быть менее абсолютного нуля: 0 K или -273.15 С");
    }
    double c = k - 273.15;
    return c;
  }

int main () {
  try {
    double k;         // Объявляем входную переменную
    cin >> k;         // Вводим температуру
    double c = ctok(k);   // Преобразовываем температуту
    cout << c << '\n';    // Выводим температуру
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
