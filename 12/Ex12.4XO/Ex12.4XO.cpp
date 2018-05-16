#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(100,100);
		Simple_window win(t1,600,400,"Ex. 12.4");

		Rectangle r_white11{Point{200,100},50,50};
		r_white11.set_fill_color(Color::white);
		win.attach(r_white11);
		
		Rectangle r_black12{Point{250,100},50,50};
		r_black12.set_fill_color(Color::black);
		win.attach(r_black12);

		Rectangle r_white13{Point{300,100},50,50};
		r_white13.set_fill_color(Color::white);
		win.attach(r_white13);
		
		Rectangle r_black21{Point{200,150},50,50};
		r_black21.set_fill_color(Color::black);
		win.attach(r_black21);

		Rectangle r_white22{Point{250,150},50,50};
		r_white22.set_fill_color(Color::white);
		win.attach(r_white22);
		
		Rectangle r_black23{Point{300,150},50,50};
		r_black23.set_fill_color(Color::black);
		win.attach(r_black23);

		Rectangle r_white31{Point{200,200},50,50};
		r_white31.set_fill_color(Color::white);
		win.attach(r_white31);
		
		Rectangle r_black32{Point{250,200},50,50};
		r_black32.set_fill_color(Color::black);
		win.attach(r_black32);

		Rectangle r_white33{Point{300,200},50,50};
		r_white33.set_fill_color(Color::white);
		win.attach(r_white33);

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
