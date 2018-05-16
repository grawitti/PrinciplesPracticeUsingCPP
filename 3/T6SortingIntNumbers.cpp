/**
Дата создания: 25.10.17
Автор: Руслан
Назначение: Программа сортировки трех, введеных, целых чисел, в порядке возрастания и вывода релультатов,
например: 1, 1, 2.
**/

#include "../std_lib_facilities.h"

int main() {

  //Приветствие
  cout << "Программа сортировки трех, введеных, целых чисел, в порядке возрастания и вывода релультатов,"
        << "например: 1, 1, 2.\n"
        << "Введите три целых числа, через пробел и нажмите 'Enter':\n";

  // Инициализация и ввод чисел
  int firstNum = -1, secondNum = -1, thirdNum = -1;
  cin >> firstNum >> secondNum >> thirdNum;
  cout << "Вы ввели: " << firstNum << ", " << secondNum << ", " << thirdNum << "\n"
        << "Отсортированные числа по возрастанию: ";

  // Сортировка чисел по возрастанию и их вывод
  if (firstNum <= secondNum && firstNum <= thirdNum) {
    cout << firstNum << ", ";
    if (secondNum <= thirdNum) cout << secondNum << ", " << thirdNum << "\n";
    else cout << thirdNum << ", " << secondNum << "\n";
  } else if (secondNum <= firstNum && secondNum <= thirdNum)
    {
      cout << secondNum << ", ";
      if (firstNum <= thirdNum) cout << firstNum << ", " << thirdNum << "\n";
      else cout << thirdNum << ", " << firstNum << "\n";
    } else if (thirdNum <= firstNum && thirdNum <= secondNum)
      {
        cout << thirdNum << ", ";
        if (firstNum <= secondNum) cout << firstNum << ", " << secondNum << "\n";
        else cout << secondNum << ", " << firstNum << "\n";
      }
  return 0;
}
