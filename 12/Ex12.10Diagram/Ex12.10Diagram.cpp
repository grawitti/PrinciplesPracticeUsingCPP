/**
 Дата создания: 22.05.18
 Автор: Руслан
 Назначение: Диаграмма файлов из раздела 12.8 стр. 489.
 Глава 12, упр. 10, стр. 492, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
{
	try 
	{
		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Ex. 12.10 - Диаграмма файлов р. 12.8");

		Rectangle FLTKH{Point{390,40},150,50};
		FLTKH.set_fill_color(0x00000016);
		win.attach(FLTKH);

		Rectangle FLTKH1{Point{395,45},150,50};
		FLTKH1.set_fill_color(0x00000016);
		win.attach(FLTKH1);

		Rectangle FLTKH2{Point{400,50},150,50};
		FLTKH2.set_fill_color(0x00000016);
		win.attach(FLTKH2);

		Text text1{Point{420,70},"Заголовочные"};
		win.attach(text1);

		Text text2{Point{420,90},"файлы FLTK"};
		win.attach(text2);

		Line line1{Point{640,135},Point{555,75}};
		win.attach(line1);

		Polygon poly1;
		poly1.add(Point{550,75});
		poly1.add(Point{555,80});
		poly1.add(Point{555,70});
		poly1.set_fill_color(Color::black);
		win.attach(poly1);

		Rectangle FLTKC{Point{640,110},100,50};
		FLTKC.set_fill_color(0x00000016);
		win.attach(FLTKC);

		Rectangle FLTKC1{Point{645,115},100,50};
		FLTKC1.set_fill_color(0x00000016);
		win.attach(FLTKC1);

		Rectangle FLTKC2{Point{650,120},100,50};
		FLTKC2.set_fill_color(0x00000016);
		win.attach(FLTKC2);

		Text text3{Point{670,140},"Код FLTK"};
		win.attach(text3);

		Rectangle interface{Point{375,180},200,80};
		interface.set_fill_color(0x00000016);
		win.attach(interface);

		Line line2{Point{475,180},Point{475,100}};
		win.attach(line2);

		Polygon poly2;
		poly2.add(Point{475,100});
		poly2.add(Point{480,105});
		poly2.add(Point{470,105});
		poly2.set_fill_color(Color::black);
		win.attach(poly2);

		Text text4{Point{375,175},"Window.h:"};
		text4.set_font(Font::times_bold);
		win.attach(text4);

		Text text5{Point{385,200},"// Оконный интерфейс:"};
		win.attach(text5);

		Text text6{Point{385,220},"class Window {...};"};
		text6.set_font(Font::times_bold);
		win.attach(text6);

		Text text7{Point{385,240},"..."};
		win.attach(text7);

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
