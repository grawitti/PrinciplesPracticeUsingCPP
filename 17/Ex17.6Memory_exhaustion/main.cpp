/*
     Date: 12.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 6
*/

#include "../../std_lib_facilities.h"

using namespace std;

int main()
{
    try
    {
		cout << "WARNING!!!\nWhis program calling memory exhaustion!\n";
		
		int number_strings = 100;	
		for(int i=0; true; i++)
		{
			string* s = new string[number_strings];
			cout << i << ':' << i*number_strings << " strings.\n";
		}	

		return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
		keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception!" << '\n';
		keep_window_open();
        return 2;
    }
}
