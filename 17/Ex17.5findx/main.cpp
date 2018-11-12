/*
     Date: 12.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 5
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

char* findx(const char* s, const char* x)
{
	char* result = nullptr;
	for (int i=0; s[i]!=0; ++i) 
	{
		if(s[i] == x[0])
		{
			for(int j=0; x[j]!=0; ++j)
			{
				if(x[j+1]==0) result = &strdup(s)[i-j];	
				if(s[i] == x[j]) 
				{
					++i;
					continue;
				}
				break;
			}
		}		
	}
	return result;
}

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
		char s[19] = {"Hello, World, etc!"};
		print_char_array(cout,s);

		char* s2 = strdup(s);
		print_char_array(cout,s);

		char s3[6] = {"World"};

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
