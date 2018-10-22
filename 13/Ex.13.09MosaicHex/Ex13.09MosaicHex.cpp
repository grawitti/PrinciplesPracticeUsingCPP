/**
 Дата создания: 10.07.18
 Автор: Руслан
 Назначение: Класс box состоящий из 4х линий и 4х дуг
 Глава 13, упр. 9, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.09 Мазайка из Regular_hexagon.");

		int r = 100;
		int rr = r*(sqrt(3)/2);
		Point start{300,300};

		Point p = start;

		Regular_hexagon rh(start,r);
		rh.set_fill_color(Color::red);
		win.attach(rh);

		Regular_hexagon rh1(start+Point{rr,r*2-r/2},r);
		win.attach(rh1);

		Regular_hexagon rh2(start+Point{rr*2,0},r);
		win.attach(rh2);

		Regular_hexagon rh3(start+Point{rr*4,0},r);
		win.attach(rh3);

		Regular_hexagon rh4(start+Point{rr*6,0},r);
		win.attach(rh4);

		Regular_hexagon rh5(start+Point{rr*3,r*2-r/2},r);
		win.attach(rh5);

		Regular_hexagon rh6(start+Point{rr*5,r*2-r/2},r);
		win.attach(rh6);

		Regular_hexagon rh7(start+Point{rr*7,r*2-r/2},r);
		win.attach(rh7);
/*
		Regular_hexagon rh(start,r);
		win.attach(rh);

		Regular_hexagon rh(start,r);
		win.attach(rh);

		Regular_hexagon rh(start,r);
		win.attach(rh);

		Regular_hexagon rh(start,r);
		win.attach(rh);

		Regular_hexagon rh(start,r);
		win.attach(rh);*/


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
