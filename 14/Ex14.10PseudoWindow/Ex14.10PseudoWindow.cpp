/**
 Дата создания: 10.09.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 10, стр. 571, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Гл. 14, упр. 10 PseudoWindow.");

		Point center{x_max()/2,y_max()/2};

		PseudoWindow pwin{center,300,500,"PseudoWindow"};
		win.attach(pwin);

		Image i{pwin.center()-Point{400/2,(266/2)-10},"1.jpg"};
		win.attach(i);
		
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
