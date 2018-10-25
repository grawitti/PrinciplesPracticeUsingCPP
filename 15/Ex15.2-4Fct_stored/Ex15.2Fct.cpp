/**
 Дата создания: 24.10.18
 Автор: Руслан
 Назначение: 
 Глава 15, упр. 2, стр. 605, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <iostream>

using namespace Graph_lib;

double sinxcosx(double x) { return sin(x)+cos(x); }

double function_2(double x) { return sin(x)*sin(x)+cos(x)*cos(x); }

int main()
{
	try
	{
		Point t1(0,0);
		Simple_window win(t1,x_max()/2,y_max()/2,"Гл. 15, упр. 2 Fct_stored.");

		constexpr int xmax = 600;
		constexpr int ymax = 400;
		constexpr int xoffset = 100;
		constexpr int yoffset = 100;
		constexpr int xspace = 50;
		constexpr int yspace = 50;
		constexpr int xlength = xmax-xoffset-xspace;
		constexpr int ylength = ymax-yoffset-yspace;

		Axis ax(Axis::x,Point{xoffset,ymax-yoffset},xlength,20,"X");
		ax.set_color(Color::black);
		win.attach(ax);

		Axis ay(Axis::y,Point{xoffset,ymax-yoffset},ylength,20,"Y");
		ay.set_color(Color::black);
		win.attach(ay);

		Fct_stored f_cos(cos,0,20,Point{xoffset,ymax-yoffset});
		f_cos.set_color(Color::green);
		win.attach(f_cos);

		Fct_stored f_sin(sin,0,20,Point{xoffset,ymax-yoffset});
		f_sin.set_color(Color::blue);
		win.attach(f_sin);

		Fct_stored f_sinxcosx(sinxcosx,0,20,Point{xoffset,ymax-yoffset});
		f_sinxcosx.set_color(Color::red);
		win.attach(f_sinxcosx);

		Fct_stored f_func_2(function_2,0,20,Point{xoffset,ymax-yoffset});
		f_func_2.set_color(Color::yellow);
		win.attach(f_func_2);

		cout << "Last arguments for Fct_stored f_cos:\n" 
			<< "last r1:\t" << f_cos.last_r1() << endl
		   	<< "last r2:\t" << f_cos.last_r2() << endl
			<< "last Point:\t" << f_cos.last_xy() << endl
			<< "last count:\t" << f_cos.last_count() << endl
			<< "last xscale:\t" << f_cos.last_xscale() << endl
			<< "last yscale:\t" << f_cos.last_yscale() << endl;

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
