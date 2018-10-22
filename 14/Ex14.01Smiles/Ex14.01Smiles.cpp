/**
 Дата создания: 16.07.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 1, стр. 570, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Гл. 14 Смайлы из класса Circle.");

		Point center{500,400};

		Smiley smile(center,100);
		win.attach(smile);

		Frowny smile2(center+Point{300,0},100);
		win.attach(smile2);

		Smiley_hat smileh(center-Point{300,0},100);
		win.attach(smileh);

		Frowny_hat fh(center+Point{0,300},100);
		win.attach(fh);

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
