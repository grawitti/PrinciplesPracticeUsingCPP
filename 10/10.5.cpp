#include "../std_lib_facilities.h"
int main()
{
  string iname;
  cout << "Введите имя входного файла: " << endl;
  cin >> iname;
  ifstream ist {iname};
  if (!ist) error("Невозможно открыть выходной файл ", iname);
  string s;
  while (ist >> s) {
    cout << s << ' ';
  }
  cout << endl;
  
  string oname;
  cout << "Введите имя выходного файла: " << endl;
  cin >> oname;
  ofstream ost {oname};
  if (!ost) error("Невозможно открыть выходной файл ", oname);
  ost << "Hello World!";
  return 0;
}
