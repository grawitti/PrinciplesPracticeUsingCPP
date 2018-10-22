/**
 Дата создания: 21.06.18
 Автор: Руслан
 Назначение: Класс Arrow рисующий стрелки
 Глава 13, упр. 4, стр. 537, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.04 функции определяющие точки подключения.");

		Rectangle r (Point{300,300},300,100);
		win.attach(r);

		Rectangle r2 (Point{300,600},300,100);
		win.attach(r2);

		Arrow ar (r2.n(),r.s());
		win.attach(ar);
		
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
