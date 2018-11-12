/*
     Date: 12.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 4
*/

#include "../../std_lib_facilities.h"

using namespace std;

char* strdup(const char* s)
{
	char* result = new char;
	for (int i=0; i< s[i]!=0; ++i) {
		result[i] = s[i];
	}
	return result;
}

void print_char_array(ostream& os, const char* s)
{
	for (int i = 0; s[i]!=0; ++i) os << s[i];
	os << endl;	
}

int main()
{
    try
    {
		char s[14] = {"Hello, World!"};
		print_char_array(cout,s);

		char* s2 = strdup(s);
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
