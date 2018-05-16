#include "../std_lib_facilities.h"

// IO
// Очистка потока - ss по ссылке
void stringstreamClear(stringstream& ss);

// Если char c цифра возвращает true
bool isNumber(const char& c);

// Очистка потока cin, до сивола: \n
void clearCin();

// Обаботка ввода из потока cin занчения - int
int getIntFromCin();

// Обаботка ввода из потока cin занчения - double
int getDoubleFromCin();

// Обаботка ввода из потока cin занчения - string
string getStringFromCin();

// Запрос нажать y или n в ответ на вопрос строки s
bool requestYorN (const string& s);
// IO END