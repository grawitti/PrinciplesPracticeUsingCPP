#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите число для проверки на четность и нажниме Enter\n";
		int checkNum = 0;
		cin >> checkNum;
		if (checkNum % 2 == 0) cout << "Число " << checkNum << " четное\n";
			else cout << "Число " << checkNum << " не четное\n";
	}
