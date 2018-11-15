/*
     Date: 14.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Exercise 2
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

// Finding first input string x into string s, without indexing, using * operator.
char* findx(const char* s, const char* x)
{
	char* result = nullptr;
	int i = 0;
	int j = 0;
	while (*s)
	{
		if(*s == *x)
		{
			while(*x)
			{
				if(*(x+1)==0) result = strdup(s-j);
				if(*s == *x)
				{
					s++;
					x++;
					++i;
					++j;
					continue;
				}
				++j;
				break;
			}
		}
		s++;
	}
	return result ? result : nullptr;
}

void print_char_array(ostream& os, const char* s)
{
	if(!s) error ("s == null.");
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

		char s3[] = "World";

		char* s4 = findx(s,s3);
		print_char_array(cout,s4);

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
