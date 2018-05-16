/**
 Дата создания: 03.04.18
 Автор: Руслан
 Назначение: Считывает показания температуры из файла, вычисляет среднюю и медиану температур.
 Глава 10, упр. 3, стр. 427, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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

// Чтение показаний температур из фала fileName
void readFileTemps (const string& fileName, vector<Reading>& vr)
{
	ifstream ifs {fileName};
	if (!ifs) error("Невозможно открыть файл ", fileName);
	int hour = -1;
	double temperature = 0.0;
	while (!ifs.eof()) 
	{
		char ch1, ch2, ch3;
		ifs >> ch1 >> hour >> ch2 >> temperature >> ch3;
		if (ch1 != '(' || ch2 != ',' || ch3 != ')') error("формата данных.");
		if (hour < 0 || hour > 23) error("Некорректное время.");
		if (ifs.fail()) 
		{
			ifs.clear();
			char c;
			ifs >> c;
			if (c != '\000') error("Ошибка формата данных, символ: '",c);
		}
		vr.push_back(Reading{hour,temperature});
	}
}

/*
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
*/

// Среднее значение температуры в векторе Reading
double averageTemps (const vector<Reading>& vr)
{
	double result = 0.0;
	for (Reading r : vr) result += r.temperature;
	return result / vr.size();
}

// Медиана температур вектора Reading
double medianTemps (const vector<Reading>& vr)
{
	vector<double> vd;
	for (Reading r : vr) vd.push_back(r.temperature); 
	sort(vd.begin(), vd.end());
	return vd[vd.size()/2];

}

// Вывод вектора int vi в поток cout
void prIntVec (const vector<Reading> vr)
{
	for (Reading r : vr) {
		cout << r.hour	<< ' ' << r.temperature << endl;
	}
}

int main() {
	try {
		cout << "Считывает показания температуры из файла, вычисляет среднюю и медиану температур.\n";
		
		string fileName = "raw_temps.txt";

		vector<Reading> temps;
		readFileTemps(fileName, temps);

		cout << "Показыния температур из файла " << fileName << ':' << endl;
		prIntVec(temps);

		cout << "Средняя температура: " << averageTemps(temps) << endl;
		cout << "Медиана температур: " << medianTemps(temps) << endl;
		
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
