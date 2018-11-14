/*
     Date: 14.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Exercise 1
*/

#include "../../std_lib_facilities.h"

using namespace std;

// Copying char string into dynamic memory, without indexing, using * oprator.
char* strdup(const char* s)
{
	char* result = new char;
	int i = 0;
	while (*s) {
		*result = *s;
		result++;
		s++;
		i++;
	}
	return result-i;
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
		char s[] = "Hello, World!";
		char* s2 = strdup(s);

		print_char_array(cout,s2);

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
