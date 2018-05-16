/**
 Дата создания: 28.01.18
 Автор: Руслан
 Назначение: Открытие файла для записи точек координат.
 Глава 10, зад. 2, стр. 426, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

class Point 
{
public:
	int x () const { return xx; };
	int y () const { return yy; };
friend istream& operator>>(const istream&, const Point& p);

	Point() {};
	Point(int xxx, int yyy) : xx{xxx}, yy{yyy} {}
private:
	int xx{0};
	int yy{0};
};

istream& operator>>(istream& is, Point& p) 
{
	int x,y;
	char ch1, ch2, ch3;
	is >> ch1 >> x >> ch2 >> y >> ch3;
	if (!is) return is;
	if (ch1 != '(' || ch2 != '.' || ch3 != ')') 
	{
		is.clear(ios_base::failbit);
		return is;
	}
	p = {x,y};
	return is;
}

int main() {
	try 
	{
		cout << "Открытие файла для записи точек координат.\n";

// Ввод	
		cout << "Введите имя файла: ";
		string iname;
		cin >> iname;
		ifstream ist {iname};
		if (!ist) error("Невозможно открыть входной файл ", iname);

// Чтение		
		vector<Point> points;
		for (Point p; ist>>p; ) points.push_back(p);

// Вывод вектора points в поток ostrem
		cout << "Считанные координаты из файла " << iname << ":\n";
		for (Point p : points) 
		{
			cout << p.x() << '.' << p.y() << endl;	
		}

// Ввод координат из потока cin
		vector<Point> originalPoints;
		cout << "Введите 7 пар точек координат, в фомате x.y: \n";
		char ch;
		int x,y;
		for (int i = 0; i < 2; ++i) 
		{
			cin >> x >> ch >> y;
			if (!cin || ch != '.') error("Ошибка формата данных.");
			originalPoints.push_back({x,y});
		}

// Вывод вектора originalPoints в поток ostrem
		for (Point p : originalPoints) 
		{
			cout << p.x() << '.' << p.y() << endl;	
		}

// Вывод
		cout << "Введите имя файла для вывода: ";
		string oname;
		cin >> oname;
		ofstream ost {oname};
		if (!ost) error("Невозможно открыть выходной файл ", oname);

// Запись		
		for (Point p : points) ost << '(' << p.x() << '.' << p.y() << ")\n";
		for (Point p : originalPoints) ost << '(' << p.x() << '.' << p.y() << ")\n";

		keep_window_open();
	}
	catch (exception& e) 
	{
		cerr << "\nОшибка: " << e.what() << endl;
		return 1;
		keep_window_open();
	}
	catch (...) 
	{
		cerr << "\nНеизвестное исключение!\n";
		return 2;
		keep_window_open();
	}
}
