/**
 Дата создания: 25.07.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 8, стр. 571, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <iostream>

using namespace Graph_lib;


int main()
{
	try
	{

		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Гл. 14, упр. 8 Octagon.");

		Point center{500,400};
		Mark m(center,'C');
		win.attach(m);

		Octagon o(center,100);
		win.attach(o);

		//Test function menbers of class Octagon

		
		cout << "getNextPoint(0): " << o.getNextPoint(0) << endl;
		o.add(center);
		o.move(200,100);
		o.set_color(Color::red);
		o.color();
		o.set_style(Line_style{Line_style::dash,9});
		o.set_fill_color(Color::blue);
		o.fill_color();
		cout << "o.point(2): " << o.point(2) << endl;
		cout << "o.number_of_points(): " << o.number_of_points() << endl;

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
