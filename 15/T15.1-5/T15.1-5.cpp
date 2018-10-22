/**
 Дата создания: 12.09.18
 Автор: Руслан
 Назначение: 
 Глава 14, Зад. 1-5, стр. 602-604, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <iostream>

using namespace Graph_lib;

double one(double x) {return 1;}

double slope(double x) {return x/2;}

double square(double x) {return x*x;}

double sloping_cos(double x) {return cos(x)+slope(x);}

int main()
{
	try
	{
		Point t1(0,0);
		Simple_window win(t1,600,600,"Графики функций");

		Point x0(100,300);
		Axis x(Axis::Orientation::x,x0,400,20,"1 == 20 пикселей");
		win.attach(x);

		Point y0(300,500);
		Axis y(Axis::Orientation::y,y0,400,20,"1 == 20 пикселей");
		win.attach(y);

		x.set_color(Color::red);
		y.set_color(Color::red);

		Function f_one(one,-10,11,Point{300,300},400,20,20);
		win.attach(f_one);
		
		Function f_slope(slope,-10,11,Point{300,300},400,20,20);
		win.attach(f_slope);

		Text t_slope(Point{100,400},"x/2");
		win.attach(t_slope);
		
		Function f_square(square,-10,11,Point{300,300},400,20,20);
		win.attach(f_square);
		
		Function f_cos(cos,-10,11,Point{300,300},400,20,20);
		win.attach(f_cos);
		f_cos.set_color(Color::blue);
		
		Function f_sloping_cos(sloping_cos,-10,11,Point{300,300},400,20,20);
		f_sloping_cos.set_color(Color::green);
		win.attach(f_sloping_cos);
		
		win.wait_for_button();		
	}
	catch (exception& e) 
	{
		cerr << "\nError: " << e.what() << endl;
		return 1;
	}
	catch (...) 
	{
		cerr << "\nUnknown exception!\n";
		return 2;
	}
	return 0;
}
