#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(100,100);
		Simple_window win(t1,600,400,"Ex. 12.2");

		Rectangle r{Point{300,100}, 100, 30};
		r.set_color(Color::blue);;
		win.attach(r);

		Text howdy{Point{320,120},"Howdy!"};
		win.attach(howdy);

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
