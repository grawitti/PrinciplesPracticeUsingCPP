/*
     Date: 12.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 7
*/

#include "../../std_lib_facilities.h"

using namespace std;

void print_char_array(ostream& os, const char* s)
{
	if(s == nullptr) error ("nullptr string.");
	for (int i = 0; s[i]!=0; ++i) os << s[i];
	os << endl;	
}

int main()
{
    try
    {
		cout << "Enter character, for exit enter '!'\n";
		char* s = new char;
		char ch = '0';
		for(int i=0; cin >> ch; ++i)
		{
			if(ch == '!') break;
			s[i] = ch;		
		}

		print_char_array(cout,s);

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
