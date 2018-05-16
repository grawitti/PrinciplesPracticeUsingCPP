/**
 Дата создания: 11.01.18
 Автор: Руслан
 Назначение: Вычисляет значение, равное сумме всех произведений двух векторов price и wieght. 
 Глава 8, упр. 8, стр. 349, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

//Приветствие
void welcomeMessage () {
	cout << "Вычисляет значение, равное сумме всех произведений двух векторов price и wieght. \n";
}

//Вычисление суммы произведений двух векторов double vd и vd2
double calcSumMult (const vector<double>& vd, const vector<double>& vd2) {
	if (vd.size() != vd2.size()) error("Разное количество элементов в векторах.");
	double result = 0;
	for(int i = 0; i < vd.size(); ++i) {
		result+=vd[i]*vd2[i];
	}
	return result;
}

int main() {
	try {
		welcomeMessage();
		vector<double> price {1.0,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
		vector<double> wieght {9.1,8.2,7.3,6.5,5.4,4.3,3.2,2.1,1.0};
		cout << "Произведение сумм двух векторов = " << calcSumMult(price,wieght) << endl;
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
