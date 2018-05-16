/**
 Дата создания: 11.01.18
 Автор: Руслан
 Назначение: Выводит максимальный элемент вектора. 
 Глава 8, упр. 9, стр. 349, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "Выводит максимальный элемент вектора.\n";
}

//Возвращает максимальный элемент вектора
double maxV (const vector<double>& v) {
	double max;
	for(double x : v) if(x > max) max = x;
	return max;
}

//Печать вектора в констоль
void printVector(const vector<double>& v) {
	for (double x : v) cout << x << " ";
	cout << endl;
}

int main() {
	try {
		welcomeMessage();
		vector<double> price {1.0,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
		printVector(price);
		cout << "Максимальный элемент вектора = " << maxV(price) << endl;
	}
		catch (exception& e) {
			cerr << "\nОшибка: " << e.what() << endl;
			return 1;
		}
		catch (...) {
			cerr << "\nНеизвестное исключение!\n";
			return 2;
		}
}
