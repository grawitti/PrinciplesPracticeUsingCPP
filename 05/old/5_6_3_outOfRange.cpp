#include<iostream>
#include<cmath>
#include<vector>
#include"std_lib_facilities.h"
using namespace std;

int main () {
  try {
    vector<int> v;
    std::cerr << "Ап" << '\n';
    for (int x; cin>>x; )
      v.push_back(x);
      for (int i = 0; i<=v.size(); i++)
        std::cout << "v[" << i << "] == " << v[i] << '\n';

  } catch (out_of_range) {
    std::cerr << "Ошибка диапазона!" << '\n';
    return 1;
  } catch (...) {
    std::cerr << "Исключение: что-то пошло не так" << '\n';
    return 2;
  }
}
