#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Ex. 12.9 Крымский мост");

		Image img {Point{200,200},"../img.jpg"};
		win.attach(img);

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
