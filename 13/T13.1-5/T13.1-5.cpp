/**
 Дата создания: 23.05.18
 Автор: Руслан
 Назначение: Окно Simple_window 800x1000,
 Глава 13, зад. 1-5, стр. 535-536, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,800,1000,"Задания 1-5, гл. 13");

		Vector_ref<Rectangle> vr;

		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j) 
			{
				vr.push_back(new Rectangle{Point{i*100,j*100},100,100});
				if (i == j) vr[vr.size()-1].set_fill_color(Color::red);
				win.attach(vr[vr.size()-1]);
			}

		Image img201{Point{200,0},"200.gif"};
		win.attach(img201);

		Image img202{Point{400,0},"200.gif"};
		win.attach(img202);

		Image img203{Point{0,200},"200.gif"};
		win.attach(img203);

		Image img100{Point{0,0},"100.gif"};
		win.attach(img100);
		

		for (int i = 0; i < 8; ++i) 
		{
			for (int j = 0; j < 8; ++j) 
			{
				win.wait_for_button();		
				img100.move(100,0);
			}
			img100.move(-800,100);
		}
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
