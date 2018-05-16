/**
 Дата создания: 03.04.18
 Автор: Руслан
 Назначение: Вычисляет сумму всех чисел записанных в файле, через пробел.
 Глава 10, упр. 4, стр. 427, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
 Changelog:
**/

#include "../std_lib_facilities.h"

// Чтение из потока ifs значений int
void readNumbers (ifstream& ifs, vector<int>& vi)
{
	for (int number = 0; !ifs.eof(); )
		{
			ifs >> number;
			if (ifs.fail())
			{
				ifs.clear();
				char c;
				ifs >> c;
				cerr << "В файле не поддерживаемый символ: " << c << endl;	
			}	
			if (number != 0) vi.push_back(number);
		}
}

// Возвращает сумму чисел вектора int v
int sumNumbers (const vector<int>& v)
{
	int result = 0;
	for (int i : v) result += i;
	return result;
}

// Вывод вектора int vi в поток cout
void prIntVec (const vector<int> vi)
{
	for (int i : vi) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	try {
		cout << "Вычисляет сумму всех чисел записанных в файле, через пробел.\n";
		
		cout << "Введите имя файла: ";    
		string iname;
		cin >> iname;
		
		ifstream ifs {iname};
		if(!ifs) error("Невозможно открыть файл ", iname);
		
		vector<int> numbers;
	   	readNumbers(ifs, numbers);
		
		prIntVec(numbers);

		cout << "Сумма считанных чисел из файла " << iname << " = " << sumNumbers(numbers) << endl;

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
