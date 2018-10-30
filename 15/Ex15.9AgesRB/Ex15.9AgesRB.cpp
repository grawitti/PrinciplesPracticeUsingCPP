/**
	Date: 30.10.18
	Author: Grawitti
	Chapter 15 – Principles and Practice Using C++	 
	Exerciese 9
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
		Simple_window win(t1,x_max()/2,y_max()/2+300,"Chapter 15 Exerciese 9. Ages the people RB Gistogram.");

		// Scaling settings
		const int xmax = x_max()/2;
		const int ymax = y_max()/2+300;
		constexpr int xoffset = 100;
		constexpr int yoffset = 50;
		constexpr int xspace = 50;
		constexpr int yspace = 60;
		const int xlength = xmax-xoffset-xspace;
		const int ylength = ymax-yoffset-yspace;

		string iname = "ages_rb.txt";
		ifstream ifs{iname};
		if(!ifs) error("Невозможно открыть файл ", iname);

		Gistogram gis(Point{xoffset,ymax-yoffset},xlength,ylength,"Ages the people RB");

		double amount = 0.0;
		double d1 = 0.0;
		double d2 = 0.0;
		while(ifs)
	   	{
			char ch1, ch2, ch3, ch4, ch5;
			ifs >> ch1 >> amount >> ch2 >> d1 >> ch3 >> d2 >> ch4 >> ch5;
			if (ch1 != '(' || ch2 != ',' || ch3 != '-' || ch4 != ')' || ch5 != ',') error("Неверный формат входных данных файла:",iname);
			ostringstream ss;
			ss << d1 << '-' << d2;
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
		gis.set_x_label("Ages");
		gis.set_y_label("Amount");
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
