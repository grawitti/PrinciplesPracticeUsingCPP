/**
	Date: 25.10.18
	Author: Grawitti
	Chapter 15 – Principles and Practice Using C++	 
	Exerciese 6
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
		Simple_window win(t1,x_max()/2,y_max()/2,"Гл. 15, упр. 6 Gistogram.");

		// Scaling settings
		constexpr int xmax = 600;
		constexpr int ymax = 400;
		constexpr int xoffset = 100;
		constexpr int yoffset = 100;
		constexpr int xspace = 50;
		constexpr int yspace = 50;
		constexpr int xlength = xmax-xoffset-xspace;
		constexpr int ylength = ymax-yoffset-yspace;

		Gistogram gis(Point{xoffset,ymax-yoffset},xlength,ylength,"Gistogram label");
		win.attach(gis);
		gis.add_col(30,"label 1");
		gis.add_col(50,"label 2");
		gis.add_col(90,"label 3");
		gis.add_col(60,"label 4");
		gis.set_x_label("X label");
		gis.set_y_label("Y label");
		gis.set_color_labels(Color::green);

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
