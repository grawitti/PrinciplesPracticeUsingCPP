/*
 * Многоугольник
*/

#include "FLTK/Simple_window.h"
#include "FLTK/Graph.h"

int main(int argc, char *argv[])
{
	using namespace Graph_lib;

	Point t1{100,100};

	Simple_window win{t1,600,400,"Canvas"};

	Polygon poly;

	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);

	win.attach (poly);

	win.wait_for_button();
}
