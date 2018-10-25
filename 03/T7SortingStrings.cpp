/**
Дата создания: 25.10.17
Автор: Руслан
Назначение: Программа сортировки трех, введеных, слов, в алфавитном порядке и вывода релультатов,
например: Fitzgerald, Hemingway, Steinbeck.
**/

#include "../std_lib_facilities.h"

int main() {

  //Приветствие
  cout << "Программа сортировки трех, введеных, слов, в алфавитном порядке и вывода релультатов,"
        << "например: Fitzgerald, Hemingway, Steinbeck.\n"
        << "Введите три слова, через пробел и нажмите 'Enter':\n";

  // Инициализация и ввод слов
  string firstWord = " ", secondWord = " ", thirdWord = " ";
  cin >> firstWord >> secondWord >> thirdWord;
  cout << "Вы ввели: " << firstWord << ", " << secondWord << ", " << thirdWord << "\n"
        << "Отсортированные по алфавиту слова (A > a): ";

  // Сортировка слов по возрастанию и их вывод
  if (firstWord <= secondWord && firstWord <= thirdWord) {
    cout << firstWord << ", ";
    if (secondWord <= thirdWord) cout << secondWord << ", " << thirdWord << "\n";
    else cout << thirdWord << ", " << secondWord << "\n";
  } else if (secondWord <= firstWord && secondWord <= thirdWord)
    {
      cout << secondWord << ", ";
      if (firstWord <= thirdWord) cout << firstWord << ", " << thirdWord << "\n";
      else cout << thirdWord << ", " << firstWord << "\n";
    } else if (thirdWord <= firstWord && thirdWord <= secondWord)
      {
        cout << thirdWord << ", ";
        if (firstWord <= secondWord) cout << firstWord << ", " << secondWord << "\n";
        else cout << secondWord << ", " << firstWord << "\n";
      }
  return 0;
}
