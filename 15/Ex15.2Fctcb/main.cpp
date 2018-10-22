/**
 ���� ��������: 12.10.18
 �����: ������
 ����������:
 ����� 14, ���. 17, ���. 573, �. ���������� "���������������� �������� � �������� � �������������� �++" (2 ���. 2016 �.)
 ������:
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
		Simple_window win(t1,x_max(),y_max(),"��. 14, ���. 17 �������� ������ exeption.");

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
