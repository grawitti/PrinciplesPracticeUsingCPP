/**
 Дата создания: 11.07.18
 Автор: Руслан
 Назначение: 
 Глава 13, упр. 14, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.14 Прямоугольный треугольник.");

		Point center{500,400};
		
		Right_triangle rt(center,300,100);
		rt.set_fill_color(Color::black);
		win.attach(rt);
	
		Right_triangle rt2(center+Point{100,-300},-300,-100);
		rt2.set_fill_color(Color::red);
		win.attach(rt2);
	
		Right_triangle rt3(center+Point{100,-200},100,100);
		rt3.set_fill_color(Color::yellow);
		win.attach(rt3);
	
		Right_triangle rt4(center+Point{200,-200},-100,-100);
		rt4.set_fill_color(Color::green);
		win.attach(rt4);
	
		Right_triangle rt5(center+Point{200,-100},-141,-141,45);
		rt5.set_fill_color(Color::white);
		win.attach(rt5);
	
		Right_triangle rt6(center+Point{0,-200},100,-100);
		rt6.set_fill_color(Color::blue);
		win.attach(rt6);
	
		Right_triangle rt7(center+Point{-100,-200},-100,100);
		rt7.set_fill_color(16);
		win.attach(rt7);
	
		Right_triangle rt8(center+Point{-100,-100},141,-141,-45);
		rt8.set_fill_color(5);
		win.attach(rt8);

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
