/**
 Дата создания: 25.10.18
 Автор: Руслан
 Назначение: 
 Глава 15, упр. 5, стр. 605, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <iostream>

using namespace Graph_lib;

double leibniz(double n)
{
	double result = 1;
	double m = 3;
	double k = -1;
	for (int i = 0; i < n; ++i) {
		result+=k/m;
		k*=-1;
		m+=2;
	}
	return result;
}

int main()
{
	try
	{
		Point t1(0,0);
		Simple_window win(t1,x_max()/2,y_max()/2,"Гл. 15, упр. 5 Leibniz.");

		constexpr int xmax = 600;
		constexpr int ymax = 400;
		constexpr int xoffset = 100;
		constexpr int yoffset = 100;
		constexpr int xspace = 50;
		constexpr int yspace = 50;
		constexpr int xlength = xmax-xoffset-xspace;
		constexpr int ylength = ymax-yoffset-yspace;
		constexpr int r_min = 0;
		constexpr int r_max = 15;
		constexpr int x_scale = 30;
		constexpr int y_scale = 30;

		Axis ax(Axis::x,Point{xoffset,ymax-yoffset},xlength,20,"X");
		ax.set_color(Color::black);
		win.attach(ax);

		Axis ay(Axis::y,Point{xoffset,ymax-yoffset},ylength,20,"Y");
		ay.set_color(Color::black);
		win.attach(ay);

		for (int n = 1; n <= 20; ++n)
	   	{
			ostringstream oss;
			oss << "Leibniz approximation n == " << n;
			win.set_label(oss.str());
			Function f_leibniz(leibniz,r_min,r_max,Point{xoffset,ymax-yoffset},n,x_scale,y_scale);
			f_leibniz.set_color(Color::red);
			win.attach(f_leibniz);
			win.wait_for_button();
			win.detach(f_leibniz);
		}

		Text t_end(Point{xoffset*2,ymax-yoffset*2},"END APPROXIMATION");
		t_end.set_color(Color::red);
		win.attach(t_end);

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
