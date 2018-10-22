/**
 Дата создания: 24.07.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 7, стр. 571, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Гл. 14, упр. 5 Striped_closed_polyline.");

		Point center{500,400};

		vector<Point> pts;
		pts.push_back(Point(100, 100));
		pts.push_back(Point(70, 150));
		pts.push_back(Point(200, 300));
		pts.push_back(Point(400, 120));
		pts.push_back(Point(300, 90));
		pts.push_back(Point(200, 50));
		pts.push_back(Point(60, 30));

		Striped_closed_polyline scp(pts);
		scp.set_color(Color::green);
		scp.set_fill_color(Color::invisible);

		win.attach(scp);


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
