/**
 Дата создания: 25.10.17
 Автор: Руслан
 Назначение: Простой калькулятор, выполняющий одну операцию с двумя числами.
 Поддерживаемые операции: + или plus, - или minus, * или mul, \ или div
 Например: 4,5 + 5 = 9,5 или 4 div 2 = 2.
**/

#include "../std_lib_facilities.h"

int main()
{
// Приветствие
  cout << "Простой калькулятор, выполняющий одну операцию с двумя числами. "
        << "Например: 4,5 + 5 = 9,5 или 4 div 2 = 2.\n"
        << "Введите число, операцию и второе число (Например 2 + 2 или 3 minus 3) и нажмите 'Enter':\n"
        << "Поддерживаемые операции: + или plus, - или minus, * или mul, / или div\n";
// Инициализация
  double firstNum = -1, secondNum = -1;
  string operand = " ";
// Ввод операции в цикле Ctrl+D или Ctrl+Z для отмены
  while (cin >> firstNum >> operand >> secondNum)
  { // Вычисление и вывод результатов
    if (operand == "+" or operand == "plus")
    {
      cout << firstNum << " + " << secondNum << " = "
           << firstNum + secondNum << "\n";
    } else if (operand == "-" or operand == "minus")
      {
        cout << firstNum << " - " << secondNum << " = "
             << firstNum - secondNum << "\n";
      } else if (operand == "*" or operand == "mul")
        {
          cout << firstNum << " * " << secondNum << " = "
               << firstNum * secondNum << "\n";
        } else if (operand == "/" or operand == "div")
          {
            if (secondNum == 0) cout << "На ноль делить нельзя!\n";
            cout << firstNum << " / " << secondNum << " = "
                 << firstNum / secondNum << "\n";
          }
    cout << "Введите следующее выражение или нажмите Ctrl+D (Ctrl+Z для Windows):\n";
  }
  return 0;
}
