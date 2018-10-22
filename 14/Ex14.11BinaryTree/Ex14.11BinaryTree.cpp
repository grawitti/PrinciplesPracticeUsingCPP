/**
 Дата создания: 13.09.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 11, стр. 571, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Гл. 14, упр. 11 BinaryTree.");

		Point center{x_max()/2,50};

		BinaryTree bt{x_max(),6};
		win.attach(bt);

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
