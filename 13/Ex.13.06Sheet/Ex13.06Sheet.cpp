/**
 Дата создания: 22.06.18
 Автор: Руслан
 Назначение: Класс Arrow рисующий стрелки
 Глава 13, упр. 6, стр. 537, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.06 схема из раздела 12.6.");

		Box bWindow (Point{x_max()/2-150,100},80,35,20,"Window");
		win.attach(bWindow);

		Box bLineStyle (Point{x_max()/2,100},100,35,20,"Line_style");
		win.attach(bLineStyle);

		Box bColor (Point{x_max()/2+150,100},80,35,20,"Color");
		win.attach(bColor);

		Box bSimpleWindow (Point{x_max()/2-188,180},140,35,20,"Simple_Window");
		win.attach(bSimpleWindow);

		Arrow a1 (bSimpleWindow.n(),bWindow.s());
		win.attach(a1);
		
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
