#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(0,0);
		Simple_window win(t1,x_max()+100,y_max()+200,"Ex. 12.5");

		Rectangle r{Point{100,100},(x_max()/3)*2,(y_max()/4)*3};
		//r.set_style(Line_style(Line_style::dash, 20));
		r.set_style(Line_style(Line_style::solid,20));
		r.set_color(Color::red);
		win.attach(r);	

		Rectangle r2 {Point{200,200},x_max()/2,y_max()*2};
		win.attach(r2);

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
