//Дата создания: 25.10.17
//Автор: Руслан
//Назначение: Программа преобразования миль введенных пользователем в километры.

#include "../std_lib_facilities.h"
int main() {
  cout << "Введите количество миль и нажмите 'Enter' для перевода в километры:\n";
  double inputMiles = -1;
  cin >> inputMiles;
  double outputKilometers = inputMiles * 1.609; // В одной миле 1,609 км.
  cout << "Вы ввели: " << inputMiles << " (миль(и)), что  равно: " << outputKilometers << " (км)\n";
}
