/**
 Дата создания: 12.10.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 17, стр. 573, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Гл. 14, упр. 17 Иерархия класса exeption.");

		Rectangle r(Point(100,100),100,100);
		win.attach(r);

		//Image i(Point{(x_max()/2)-294,100},"ExceptionClasses.jpg");
		//win.attach(i);

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
