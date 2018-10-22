/**
 Дата создания: 11.07.18
 Автор: Руслан
 Назначение: Класс box состоящий из 4х линий и 4х дуг
 Глава 13, упр. 11, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <iostream>

using namespace Graph_lib;


int main()
{
	try
	{
		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.11 Elipse Axis.");

		Point center{400,400};

		Ellipse el(center,150,100);
		win.attach(el);

		Axis x(Axis::Orientation::x,center-Point{200,0},400,0,"X");
		win.attach(x);

		Axis y(Axis::Orientation::y,center+Point{0,150},300,0,"Y");
		win.attach(y);

		Mark m1(el.n()+Point{10,-10},'N');
		win.attach(m1);

		Mark m2(el.e()+Point{10,-10},'E');
		win.attach(m2);

		Mark m3(center+Point{123,73},'P');
		win.attach(m3);

		Line l(center+Point{113,63},el.n());
		win.attach(l);

		Line l2(center+Point{113,63},el.e());
		win.attach(l2);

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
