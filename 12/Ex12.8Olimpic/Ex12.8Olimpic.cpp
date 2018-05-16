#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Ex. 12.8");

		Circle blue {Point{300,300},150};
		blue.set_color(Color::blue);
		blue.set_style(Line_style(Line_style::solid,10));
		win.attach(blue);

		Circle black {Point{600,300},150};
		black.set_color(Color::black);
		black.set_style(Line_style(Line_style::solid,10));
		win.attach(black);

		Circle red {Point{900,300},150};
		red.set_color(Color::red);
		red.set_style(Line_style(Line_style::solid,10));
		win.attach(red);

		Circle yellow {Point{450,550},150};
		yellow.set_color(Color::yellow);
		yellow.set_style(Line_style(Line_style::solid,10));
		win.attach(yellow);

		Circle green {Point{750,550},150};
		green.set_color(Color::green);
		green.set_style(Line_style(Line_style::solid,10));
		win.attach(green);


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
