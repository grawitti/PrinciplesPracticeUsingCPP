#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(100,100);
		Simple_window win(t1,600,400,"Ex. 12.3");

		Text SRR{Point{100,200},"С.Р.Р."};
		SRR.set_font_size(150);
		win.attach(SRR);

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
