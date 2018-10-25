#include<iostream>
#include<cmath>
#include<vector>
#include"std_lib_facilities.h"
#include<algorithm>
using namespace std;
int area (int lenght, int width) {
  if (lenght <= 0 || width <= 0) {
    error("Отрицательное число!");
  }
  return lenght/=width;
}
double area (double lenght, double width) {
  if (lenght <= 0 || width <= 0) {
    error("Отрицательное число!");
  }
  return lenght*=width;
}
int main () {
  int a;
  int b;
  double c = 7.3;
  double d = 2.8;

  cin >> a >> b;

  int s4 = area(a, b);
  double s5 = area(c, d);

  cout << s4 << '\n';
  cout << s5 << '\n';
}
