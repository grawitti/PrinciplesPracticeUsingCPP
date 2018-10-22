/**
 Дата создания: 10.07.18
 Автор: Руслан
 Назначение: Класс Arrow рисующий стрелки
 Глава 13, упр. 7, стр. 538, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <FL/Fl_Chart.H>
#include <FL/Fl_Window.H>
#include <stdexcept>
#include <iostream>

using namespace Graph_lib;

int main()
{
	try
	{
		//Point t1(0,0);
		//Simple_window win(t1,x_max(),y_max(),"Ex. 13.07 Диаграмма цветов RGB.");


		//win.wait_for_button();		

		Fl_Window *window = new Fl_Window(x_max(),y_max());

		Fl_Chart chart (100,400,900,300,"Диаграмма RGB");
		chart.add(25,"25",1);
		chart.add(50,"50",2);
		chart.add(75,"75",3);
		chart.add(100,"100",4);
		chart.add(125,"125",5);
		chart.add(150,"150",6);
		chart.add(175,"175",7);
		chart.add(200,"200",8);
		chart.add(225,"225",9);
		chart.add(250,"250",10);
		
		window->end();
		window->show();
		return Fl::run();
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
