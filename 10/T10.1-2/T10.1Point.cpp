/**
 Дата создания: 28.01.18
 Автор: Руслан
 Назначение: Открытие файла для записи точек координат.
 Глава 10, зад. 1, стр. 426, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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

// Вывод
		cout << "Введите имя файла для вывода: ";
		string oname;
		cin >> oname;
		ofstream ost {oname};
		if (!ost) error("Невозможно открыть выходной файл ", oname);

// Запись		
		for (Point p : points) ost << '(' << p.x() << '.' << p.y() << ")\n";
	}
	catch (exception& e) 
	{
		cerr << "\nОшибка: " << e.what() << endl;
		return 1;
	}
	catch (...) 
	{
		cerr << "\nНеизвестное исключение!\n";
		return 2;
	}
}
