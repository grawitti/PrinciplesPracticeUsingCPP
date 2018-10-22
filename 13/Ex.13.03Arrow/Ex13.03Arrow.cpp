/**
 Дата создания: 20.06.18
 Автор: Руслан
 Назначение: Класс Arrow рисующий стрелки
 Глава 13, упр. 3, стр. 537, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.03 Класс Arrow.");
		
		Arrow a(Point{200,300},Point{200,400});
		win.attach(a);

		Arrow b(Point{100,300},Point{100,200});
		win.attach(b);

		Arrow c(Point{200,300},Point{100,300});
		win.attach(c);

		Arrow d(Point{100,300},Point{200,300});
		win.attach(d);


		Arrow e(Point{400,400},Point{500,500});
		win.attach(e);

		Arrow f(Point{400,500},Point{500,400});
		win.attach(f);


		Arrow i(Point{700,500},Point{600,400});
		win.attach(i);

		Arrow h(Point{700,400},Point{600,500});
		win.attach(h);

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
