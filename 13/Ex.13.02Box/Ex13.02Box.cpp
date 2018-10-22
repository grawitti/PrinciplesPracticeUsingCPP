/**
 Дата создания: 31.05.18
 Автор: Руслан
 Назначение: Класс box состоящий из 4х линий и 4х дуг
 Глава 13, упр. 2, стр. 537, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Ex. 13.02 класс Box.");

		int r = 20;
		int h = 100;
		int w = 300;
		Point pTopLeft{300,300};

		Box b (Point{300,300},300,100,40);
		win.attach(b);
/*
		// Manual box
		Arc arcTopLeft (pTopLeft,r,r,90,180);
		win.attach(arcTopLeft);

		Point pTopRight{pTopLeft+Point{w,0}};
		Arc arcTopRigth (pTopRight,r,r,0,90);
		win.attach(arcTopRigth);

		Point pBottomLeft{pTopLeft+Point{0,h}};
		Arc arcBottomLeft (pBottomLeft,r,r,180,270);
		win.attach(arcBottomLeft);

		Point pBottomRight{pTopLeft+Point{w,h}};
		Arc arcBottomRight (pBottomRight,r,r,270,360);
		win.attach(arcBottomRight);

		Lines boxLines {};
		boxLines.add(pTopLeft-Point{0,r},pTopRight-Point{0,r});
		boxLines.add(pBottomLeft+Point{0,r},pBottomRight+Point{0,r});
		boxLines.add(pTopLeft-Point{r,0},pBottomLeft-Point{r,0});
		boxLines.add(pTopRight+Point{r,0},pBottomRight+Point{r,0});
		win.attach(boxLines);
*/
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
