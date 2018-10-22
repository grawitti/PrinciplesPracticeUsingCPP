/**
 Дата создания: 31.05.18
 Автор: Руслан
 Назначение: Класс Arc рисующий часть эллипса.
 Глава 13, упр. 1, стр. 537, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.01 класс Arc.");

		int r = 50;
		Arc a (Point{300,300},r,r,0,90);
		win.attach(a);

		Arc a90 (Point{500,300},r,r,90,180);
		win.attach(a90);

		Arc a9090 (Point{300,500},r,r,180,270);
		win.attach(a9090);

		Arc a180270 (Point{500,500},r,r,270,360);
		win.attach(a180270);

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
