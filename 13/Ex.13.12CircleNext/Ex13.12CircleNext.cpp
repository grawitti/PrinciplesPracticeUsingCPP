/**
 Дата создания: 11.07.18
 Автор: Руслан
 Назначение: 
 Глава 13, упр. 12, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.12 Сдвигающаяся по окружности метка.");

		Point center{x_max()/2,y_max()/2};

		int radius = 200;

		Circle c(center,radius);
		win.attach(c);

		Mark m(c.s(),'M');
		win.attach(m);

		int xc = c.center().x;
		int yc = c.center().y;
		float alpha = M_PI/4; // угол поворота для точки, 45 градусов в радианах
		float angle = 0; // 
		for (int i = 0; i < 8; ++i)
            {
				angle += alpha;
                float x, y;
				x = xc + radius * sin(angle);
				y = yc + radius * cos(angle);
				win.wait_for_button();		
				m.move(x-m.point(0).x,y-m.point(0).y);
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
