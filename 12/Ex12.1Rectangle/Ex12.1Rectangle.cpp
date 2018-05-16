#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(100,100);
		Simple_window win(t1,600,400,"Canvas");

		Polygon poly;
		poly.add(Point{100,100});
		poly.add(Point{100,150});
		poly.add(Point{200,150});
		poly.add(Point{200,100});
		poly.set_color(Color::red);
		win.attach(poly);

		Rectangle r{Point{300,100}, 100, 50};
		r.set_color(Color::blue);;
		win.attach(r);

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
