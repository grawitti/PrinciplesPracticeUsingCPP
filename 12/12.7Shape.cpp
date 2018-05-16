// #include <FL/Fl.H>
// #include <FL/Fl_Window.H>

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include <stdexcept>
//#include "../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(100,100);
		Simple_window win(t1,600,400,"Canvas");

		Image img{Point{0,0}, "blue_texture.jpg"};
		img.set_mask(Point{0,0},x_max(),y_max());
		win.attach(img);

		Axis xa{Axis::x, Point(20,300), 280, 10, "x axis"};
		win.attach(xa);
		win.set_label("Canvas #2");

		Axis ya{Axis::y, Point(20,300), 280, 10, "y axis"};
		ya.set_color(Color::cyan);
		ya.label.set_color(Color::dark_red);
		win.attach(ya);
		win.set_label("Canvas #3");

		Function sinus(sin,0,100,Point{20,150},1000,50,50);
		win.attach(sinus);
		win.set_label("Canvas #4");
		sinus.set_color(Color::blue);

		Polygon poly;
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::red);
		poly.set_style(Line_style(Line_style::dash,4));
		win.attach(poly);

		Rectangle r{Point{200,200}, 100, 50};
		win.attach(r);
		win.set_label("Canvas #5");
		r.set_fill_color(Color::yellow);

		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		poly_rect.add(Point{50,75});
		poly_rect.set_style(Line_style(Line_style::dash,2));
		poly_rect.set_fill_color(Color::green);
		win.set_label("Canvas #6");
		win.attach(poly_rect);

		Text t(Point{150,150}, "Hello, graphical world!");
		win.attach(t);
		t.set_font(Font::times_bold);
		t.set_font_size(20);
		win.set_label("Canves #7");


		Circle c{Point{100,200}, 50};
		Ellipse e{Point{100,200}, 75, 25};
		e.set_color(Color::dark_red);
		Mark m{Point{100,200}, 'x'};

		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
			<< "; window size:" << win.x_max() << "*" << win.y_max();
		Text sizes{Point{100,20},oss.str()};

		Image cal{Point{225,255},"img.jpg"};
		cal.set_mask(Point{40,40},200,150);

		win.attach(c);
		win.attach(m);
		win.attach(e);

		win.attach(sizes);
		win.attach(cal);


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
