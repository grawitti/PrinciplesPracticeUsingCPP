/**
 Дата создания: 02.11.17
 Автор: Руслан
 Назначение: Простой калькулятор, выполняющий одну операцию с двумя числами.
 Поддерживаемые операции: + или plus, - или minus, * или mul, \ или div
 Например:
 Ввод: 4.5 + 5 
 Вывод: 4.5 + 5 = 9.5
**/

#include "../std_lib_facilities.h"

int main()
{
// Приветствие
  cout << "Простой калькулятор, выполняющий одну операцию с двумя числами. "
        << "Например: 4.5 + 5 = 9.5\n"
        << "Введите число, операцию и второе число, через пробел (Например 2 + 2 или 3 minus 3) и нажмите 'Enter':\n"
        << "Поддерживаемые операции: + сложение, - вычитание, * умножение, / деление.\n";
// Инициализация
  double firstNum = -1, secondNum = -1; // Операнды 
  char operation = ' '; // Операция
// Ввод операции в цикле Ctrl+D или Ctrl+Z для отмены
  while (cin >> firstNum >> operation >> secondNum || operation == 'q') { 
// Вычисление и вывод результатов
    switch (operation) {
    case '+':
      cout << firstNum << " + " << secondNum << " = " // Сложение
           << firstNum + secondNum << "\n";
      break;
    case '-':
      cout << firstNum << " - " << secondNum << " = " // Вычитание
           << firstNum - secondNum << "\n";
      break;
    case '*':
      cout << firstNum << " * " << secondNum << " = " // Умножение
           << firstNum * secondNum << "\n";
      break;
    case '/':
      if (secondNum == 0) cout << "На ноль делить нельзя!\n"; 
        cout << firstNum << " / " << secondNum << " = " // Деление
             << firstNum / secondNum << "\n";
      break;
    default:
      cout << "Ошибка! Вы ввели не корректный оператор: " << operation << "\n";
      break;
  }
    cout << "Введите следующее выражение или нажмите Ctrl+D (Ctrl+Z для Windows):\n";
  }
  return 0;
}
