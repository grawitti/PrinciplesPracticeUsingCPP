/**
 Дата создания: 06.09.18
 Автор: Руслан
 Назначение: 
 Глава 14, упр. 9, стр. 571, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
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
		Simple_window win(t1,x_max(),y_max(),"Гл. 14, упр. 9 Chess(Group).");

		Circle cc{Point{100,100},50};
		cc.set_fill_color(Color::black);
		win.attach(cc);

		Point center{x_max()/2,y_max()/2};
		Mark m(center,'C');
		win.attach(m);

		Circle c{center-Point{200,0}, 100};
		win.attach(c);

		Group grp;
		grp.shape_add(c);

		Rectangle r{center, 100,100};
		win.attach(r);

		grp.shape_add(r);	

		win.wait_for_button();		
		grp.move(0,100);

		win.wait_for_button();		
		grp.set_color(Color::red);

		win.wait_for_button();		
		grp.set_fill_color(Color::blue);

		win.wait_for_button();		
		grp.set_style(Line_style::dash);

		win.wait_for_button();		
		win.detach(r);
		win.detach(c);
		win.detach(m);
		win.detach(cc);

		Point xy{40,40};
		int size = 100;
		Vector_ref<Rectangle> vr;

		Group board;
		for(int i = 0; i < 8; ++i) 
		{
			for(int j = 0; j < 8; ++j) 
			{
				vr.push_back(new Rectangle{xy+Point{j*size,i*size},size,size});
				if (i%2 == 0){
				if (j%2 == 0) vr[vr.size()-1].set_fill_color(Color::black);
				else vr[vr.size()-1].set_fill_color(Color::white);
				} else if (i%2 != 0) { 
					if (j%2 != 0) vr[vr.size()-1].set_fill_color(Color::black);
					else vr[vr.size()-1].set_fill_color(Color::white);
				}
				board.shape_add(vr[vr.size()-1]);
				win.attach(vr[vr.size()-1]);
			}
		}

		win.wait_for_button();		
		Vector_ref<Circle> vc;
		Group wch;
		for(int i = 0; i < 16; ++i){
			vc.push_back(new Circle{vr[i].center(),50});
			wch.shape_add(vc[i]);
			win.attach(vc[i]);
		}
		wch.set_fill_color(Color::white);

		Vector_ref<Circle> vc1;
		Group bch;
		for(int i = 48; i < vr.size(); ++i){
			vc1.push_back(new Circle{vr[i].center(),50});
			bch.shape_add(vc1[vc1.size()-1]);
			win.attach(vc1[vc1.size()-1]);
		}
		bch.set_fill_color(Color::black);

		win.wait_for_button();		
		bch.move(0,-100);
		
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
