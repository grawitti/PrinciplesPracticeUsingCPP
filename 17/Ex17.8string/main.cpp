/*
     Date: 12.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 8
*/

#include "../../std_lib_facilities.h"

using namespace std;

int main()
{
    try
    {
		cout << "Enter character, for exit enter '!'\n";
		string s = "";
		char ch = '0';
		for(int i=0; cin >> ch; ++i)
		{
			if(ch == '!') break;
			s += ch;		
		}

		cout << s << endl;
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
