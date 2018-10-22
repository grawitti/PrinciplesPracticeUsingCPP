/**
 Дата создания: 11.07.18
 Автор: Руслан
 Назначение: Класс box состоящий из 4х линий и 4х дуг
 Глава 13, упр. 10, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.10 Класс Regular_polygon.");

		Regular_polygon rp(Point{x_max()/2,y_max()/2},100,3);
		rp.set_fill_color(Color::red);
		win.attach(rp);

		Regular_polygon rp2(Point{x_max()/2-200,y_max()/2},100,4);
		rp2.set_fill_color(Color::blue);
		win.attach(rp2);

		Regular_polygon rp3(Point{x_max()/2+200,y_max()/2},100,5);
		rp3.set_fill_color(Color::yellow);
		win.attach(rp3);

		Regular_polygon rp4(Point{x_max()/2+400,y_max()/2},100,6);
		rp4.set_fill_color(Color::green);
		win.attach(rp4);

		Regular_hexagon rh(Point{300,300},100);
		rh.set_fill_color(Color::black);
		win.attach(rh);

		win.wait_for_button();		
	}
	catch (std::exception& e) 
	{
		return 1;
	}
	catch (...)
	{
		return 2;
	}
	return 0;
}
