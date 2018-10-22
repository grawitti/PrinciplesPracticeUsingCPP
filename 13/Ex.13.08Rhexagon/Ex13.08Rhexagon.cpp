/**
 Дата создания: 10.07.18
 Автор: Руслан
 Назначение: Класс box состоящий из 4х линий и 4х дуг
 Глава 13, упр. 8, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.08 Regular hexagon.");

		Regular_hexagon rh(Point{300,300},100);
		win.attach(rh);

		/* Manual
		Point hCenter{x_max()/2,y_max()/2};
		int R = 100;
		int r = R*(sqrt(3)/2);
		Point p1 = hCenter+Point{r,-R/2};
		Point p2 = p1+Point{0,R};
		Point p3 = hCenter+Point{0,R};
		Point p4 = hCenter+Point{-r,R/2};
		Point p5 = p4+Point{0,-R};
		Point p6 = hCenter+Point{0,-R};
		Closed_polyline test; 
		test.add(p1);
		test.add(p2);
		test.add(p3);
		test.add(p4);
		test.add(p5);
		test.add(p6);
		win.attach(test);*/

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
