#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  string checkString;
  int modaNumber;
  vector<string> strings;
  vector<int> moda;
  for ( ;cin >> checkString; ) {
    if (strings.size() == 0) {
      strings.push_back(checkString);
      moda.push_back(1);
      modaNumber = 0;
    }
    int countEqval = 0;
    for (int i = 0; i <= strings.size(); i++) {
      if (checkString == strings[i]) {
        moda[i]=moda[i]+1;
        countEqval++;
      } else if (countEqval == 0) {
        strings.push_back(checkString);
        moda.push_back(1);
      }
    }
    for (int i = 0; i <= moda.size(); i++) {
      if (moda[i] > moda[modaNumber]) {
        modaNumber = i;
        cout << "Мода:" << strings[modaNumber] << '\n';
      }
    }
  }
}
