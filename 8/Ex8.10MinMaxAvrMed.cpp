/**
 Дата создания: 11.01.18
 Автор: Руслан
 Назначение: Выводит максимальный, минимальный элемент вектора, среднее значение и медиану. 
 Глава 8, упр. 10, стр. 349, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "Выводит максимальный, минимальный элемент вектора, среднее значение и медиану.\n";
}

//Возвращает максимальный элемент вектора
double maxV (const vector<double>& v) {
	double max;
	for(double x : v) if(x > max) max = x;
	return max;
}

//Возвращает минмальный элемент вектора
double minV (const vector<double>& v) {
	double min;
	for(int i = 0; i < v.size() ; ++i) {
		if (i == 0) min = v[i];
		if (v[i] < min) min = v[i];
	}
	return min;
}

//Возвращает среднее значение элементов вектора
double avrV (const vector<double>& v) {
	double averange = -1;
	double sum = 0;
	for(double x : v) sum+=x;
	averange = sum/v.size();
	return averange;
}

//Возвращает медиану вектора
double medV(vector<double> v) {
	sort(v.begin(), v.end());
	return v[v.size()/2];
}

//Печать вектора в констоль
void printVector(const vector<double>& v) {
	for (double x : v) cout << x << " ";
	cout << endl;
}

int main() {
	try {
		welcomeMessage();
		vector<double> price {1.0,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10};
		printVector(price);
		cout << "Максимальный элемент вектора = " << maxV(price) << endl;
		cout << "Минимальный элемент вектора = " << minV(price) << endl;
		cout << "Среднее значение вектора = " << avrV(price) << endl;
		cout << "Медиана вектора = " << medV(price) << endl;
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
