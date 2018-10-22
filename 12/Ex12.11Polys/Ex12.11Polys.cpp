/**
 Дата создания: 23.05.18
 Автор: Руслан
 Назначение: Ряд правильных многоугольников вложенных друг в друга.
 Глава 12, упр. 11, стр. 492, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <cmath>

using namespace Graph_lib;

// Находит координату для правильного многоугольника. n - количество сторон, radius - радиус, p - начальная точка.
vector<Point> calcPoints(const int& n, const int& radius, const Point& p) 
{
	vector<Point> vp;
	for (int i = 0; i < n; ++i) 
	{
		double x = p.x + radius * cos((2*M_PI*i)/n);
		double y = p.y + radius * sin((2*M_PI*i)/n);
		vp.push_back(Point{int(x),int(y)});
	}
	return vp;
}

//
void drawPolygin (Simple_window& win, Polygon& poly, const int& radius, const Point& p0, const int& n) 
{
	vector<Point> vpPoly = calcPoints(n,radius,p0);
	for (Point p : vpPoly) poly.add(p);
	win.attach(poly);
}

int main()
{
	try 
	{
		Point t1(0,0);
		Simple_window win(t1,x_max(),y_max(),"Ex. 12.11 Ряд вложенных, правильных многоугольников.");
		
		int n = 3;
		int radius = 60; // 360/2*n где n - количество сторон многоугольника
		Point p0{x_max()/2,y_max()/2};// Середина окна

		Polygon poly1;
		drawPolygin(win,poly1,radius,p0,3);

		Polygon poly2;
		drawPolygin(win,poly2,radius+20,p0,4);

		Polygon poly3;
		drawPolygin(win,poly3,radius+40,p0,5);
//		poly3.set_color(Color::invisible);

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
