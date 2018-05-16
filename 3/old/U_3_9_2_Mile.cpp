#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
#include<cmath>
using namespace std;
//inline void keep_window_open() { char ch; cin>>ch; }

int main ()
	{
		cout << "Введите воличество миль и нажмите Enter:\n";
		double mileValue;
		cin >> mileValue;
		double kmValue = mileValue*1.609;
		cout << mileValue << " миль равно " << kmValue << " километров\n";
	}
