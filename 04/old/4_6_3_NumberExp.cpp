#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	// Ввод значений в вектор температур
	vector <double> temps;
	for (double temp; cin>>temp; ) { //  Пока введенное знаечние в переменную temp истино т.е. имеент числовое значение
		temps.push_back(temp);
	}

	// Вычисление среднего значения температур
	double sum = 0;
	for (int x : temps) {
		sum += x;
		//cout << x << '\t' << '\n';
	}
	cout << "Средняя температура: "
			 <<	sum/temps.size() << '\n';

	// Вычисление медианы температуры
	sort(temps.begin(), temps.end()); // в книге сортировка указано не верно
	for (double x : temps) {
		cout << x << '\t' << '\n';
	}
	cout << "Медианная температура: ";
	if (temps.size()%2 == 0) {
		cout << (temps[temps.size()/2]+temps[temps.size()/2-1])/2 << '\n';
	} else  cout << temps[temps.size()/2] << '\n';
}
