#include<iostream>
#include<cmath>
//#include<vector>
//#include<algorithm>
using namespace std;

double square(double x) {
  return x*x;
}

int main () {
  double a, b, c, x, x1, x2, d;
  cout << "Введите, через пробел, значения a, b и c квадратного уравнения вида: ах2+b+c=0" << '\n';
  cin >> a >> b >> c;
  d = square(b) - 4*a*c;
  cout << "d = " << d << '\n';
  if (d > 0) {
    x1=(-b+sqrt(d))/2*a;
    cout << "x1 = " << x1 << '\n';
    x2=(-b-sqrt(d))/2*a;
    cout << "x2 = " << x2 << '\n';
  } else if (d == 0) {
    x1 = -(b/2*a);
    cout << "x1 = x2 = " << x1 << '\n';
  } else cout << "Корней на множестве действительных чисел нет." << '\n';
}
