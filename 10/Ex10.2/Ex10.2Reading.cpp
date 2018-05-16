/**
 Дата создания: 03.04.18
 Автор: Руслан
 Назначение: Записывает показания температуры в файл.
 Глава 10, упр. 2, стр. 427, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
**/

#include "../std_lib_facilities.h"

// Показания температуры по часам
struct Reading 
{
	int hour;
	double temperature;
};

// Чтение показаний температур из потока cin запись в вектор Reading
void readTemperatures (vector<Reading>& vr)
{
	cout << "Введите время в часах (0-23) и температуру через пробел, для окончания ввода введите - q.\n";
	int hour = -1;
	double temperature = 0.0;
	while (true) 
	{
		cin >> hour >> temperature;
		if (hour < 0 || hour > 23) error("Некорректное время.");
		if (cin.fail()) 
		{
			cin.clear();
			char c;
			cin >> c;
			if (c == 'q')
			{
				cin.ignore();
				break;
			}
			else cerr << "Ошибка формата данных, символ: " << c << endl;
		}
		vr.push_back(Reading{hour,temperature});
	}
}

// Запись вектора температур Reading в файл fileName
void writeTemperatures (const vector<Reading>& vr, const string& fileName)
{
	ofstream ost {fileName};
	if (!ost) error("Невозможно открыть файл ", fileName);

	for (int i = 0; i < vr.size(); ++i) 
	{
		ost << '(' << vr[i].hour << ','
			<< vr[i].temperature << ")\n";
	}
}
int main() {
	try {
		cout << "Записывает показания температуры в файл: raw_temps.txt.\n";
		
		vector<Reading> temps;
		readTemperatures(temps);
		
		writeTemperatures(temps,"raw_temps.txt");

		keep_window_open();
	}
	catch (exception& e) {
		cerr << "\nОшибка: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (int& e) {
		cerr << "\nОшибка: Год, месяц или день введены некорректно." << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "\nНеизвестное исключение!\n";
		keep_window_open();
		return 2;
	}
}
