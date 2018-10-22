/**
 Дата создания: 11.07.18
 Автор: Руслан
 Назначение: 
 Глава 13, упр. 13, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.13 Матрица цветов из раздела 13.10.");
		
		Vector_ref<Rectangle> vr;

		for(int i = 0; i < 16; ++i)
			for(int j = 0; j < 16; ++j)
			{
				vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
				vr[vr.size()-1].set_fill_color(Color{i*16+j});
				//vr[vr.size()-1].set_color(Color{i*16+j});
				vr[vr.size()-1].set_color(Color::invisible);
				win.attach(vr[vr.size()-1]);
			}

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
