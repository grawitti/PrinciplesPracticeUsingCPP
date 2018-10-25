#include<iostream>
#include<cmath>
#include<vector>
//#include<algorithm>
using namespace std;

int main () {
  string nextString;
  int nextScore;
  vector<string> names;
  vector<int> scores;
  cout << "Введите Имя и баллы, через пробел." << '\n';
  for ( ;cin >> nextString >> nextScore; ) {
    if (names.size() != 0 and scores.size() != 0) {
      cout << "Ученики получившие такую же оценку:" << '\n';
      for (int i = 0; i <= scores.size(); i++) {
        if (scores[i] == nextScore) {
          cout << names[i] << '\t' << scores[i] << '\n';
        }
      }
    }

    int countEqval = 0;
    for (int i = 0; i <= names.size(); i++) {
      if (nextString == "NoName" and nextScore == 0) {
        for (int i = 0; i < names.size(); i++) {
          cout << names[i] << '\t' << scores[i] << '\n';
        }
        return 0;
      } else if (names.size() == 0) {
        names.push_back(nextString);
        scores.push_back(nextScore);
        cout << "Имя не найдено" << '\n';
        break;
      } else if (nextString == names[i]) {
        cout << "Ошибка! Это имя уже существует!" << '\n'
             << names[i] << '\t' << scores[i] << '\n';
        countEqval++;
        break;
      } else if (names.size() == i and countEqval == 0) {
          names.push_back(nextString);
          scores.push_back(nextScore);
          cout << "Имя не найдено" << '\n';
          break;
        }
    }
  }
}
