/*
     Date: 09.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 3
*/

#include "../../std_lib_facilities.h"

using namespace std;

void to_lower(char* s)
{
	const int BEGIN_UPPER = int('A'); // int('A') = 65 
	const int END_UPPER = int('Z');
	const int BEGIN_LOWER = int('a');

	int int_char;
	for (int i = 0; s[i]!=0; ++i) 
	{
		int_char = int(s[i]);
		if(int_char >= BEGIN_UPPER && int_char <= END_UPPER) s[i] = char(BEGIN_LOWER+(int_char-BEGIN_UPPER));
	}
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
		char* s = new char[13] {'H','e','l','l','o',',',' ','W','o','r','l','d','!'};
		print_char_array(cout,s);

		to_lower(s);
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
