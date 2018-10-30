/**
	Date: 30.10.18
	Author: Grawitti
	Chapter 15 – Principles and Practice Using C++	 
	Exerciese 8
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
		Simple_window win(t1,x_max()/2,y_max()/2,"Chapter 15 Exerciese 8. Growth the people Gistogram.");

		// Scaling settings
		constexpr int xmax = 600;
		constexpr int ymax = 400;
		constexpr int xoffset = 100;
		constexpr int yoffset = 100;
		constexpr int xspace = 50;
		constexpr int yspace = 50;
		constexpr int xlength = xmax-xoffset-xspace;
		constexpr int ylength = ymax-yoffset-yspace;

		string iname = "growth.txt";
		ifstream ifs{iname};
		if(!ifs) error("Невозможно открыть файл ", iname);

		Gistogram gis(Point{xoffset,ymax-yoffset},xlength,ylength,"Growth the people");

		double growth = 0.0;
		double amount = 0.0;
		while(ifs)
	   	{
			char ch1, ch2, ch3, ch4;
			ifs >> ch1 >> growth >> ch2 >> amount >> ch3 >> ch4;
			if (ch1 != '(' || ch2 != ',' || ch3 != ')' || ch4 != ',') error("Неверный формат входных данных файла:",iname);
			ostringstream ss;
			ss << growth;
			gis.add_col(amount,ss.str());	
			if(ifs.fail())
			{
				ifs.clear();
				char c;
				ifs >> c;
				if (isspace(c) || c == '\000') break;
				else error("Ошибка формата данных в файле ", iname);
			}
		}
		win.attach(gis);

		win.wait_for_button();		
	}
	catch (exception& e) 
	{
		cerr << "\nError: " << e.what() << endl;
		return 1;
	}
	catch (...) 
	{
		cerr << "\nUnknown exception!\n";
		return 2;
	}
	return 0;
}
