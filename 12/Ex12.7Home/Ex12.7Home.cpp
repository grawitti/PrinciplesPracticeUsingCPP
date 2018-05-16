#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Ex. 12.7");

		Rectangle box {Point{x_max()/2-200,y_max()/2},400,400};
		box.set_fill_color(Color::white);
		win.attach(box);

		Rectangle tube {Point{x_max()/2-125,y_max()/2-420},30,220};
		tube.set_fill_color(Color::black);
		win.attach(tube);

		Polygon roof;
		roof.add(Point{x_max()/2-250,y_max()/2});
		roof.add(Point{x_max()/2,y_max()/2-400});
		roof.add(Point{x_max()/2+250,y_max()/2});
		roof.set_fill_color(Color::dark_red);
		win.attach(roof);

		Rectangle door {Point{x_max()/2-50,y_max()/2+200},100,200};
		door.set_fill_color(Color::yellow);
		win.attach(door);

		Rectangle window1 {Point{x_max()/2-175,y_max()/2+200},100,150};
		window1.set_style(Line_style(Line_style::solid,5));
		win.attach(window1);

		Rectangle window2 {Point{x_max()/2+75,y_max()/2+200},100,150};
		window2.set_style(Line_style(Line_style::solid,5));
		win.attach(window2);

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
