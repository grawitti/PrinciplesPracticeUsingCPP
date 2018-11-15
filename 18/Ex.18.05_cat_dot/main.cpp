/*
     Date: 15.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Exercise 5
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

// Compare char* s1 and s2
int strcmp(const char* s1, const char* s2)
{
	while(*s1)
	{
		if(*s1<*s2) return -1;
		if(*s1>*s2) return 1;
		if(*s1==*s2) { s1++; s2++; }
	}
	if(*s2) return -1;
	return 0;
}

// Concatenate string s1 and s2
string cat_dot(const string& s1, const string& s2)
{
	return s1+"."+s2;
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

		char s3[] = "llo";

		char* s4 = findx(s,s3);
		print_char_array(cout,s4);

		char s5[] = "llo, Wo";

		cout << strcmp(s3,s5) << endl;

		string st1 = "One";
		string st2 = "Two";
		cout << cat_dot(st1,st2) << endl; 

// This code maybe call the exceptions Ex.18.4
/*
		char s6 = 's';
		char* s7 = strdup(&s6);
		print_char_array(cout,s7);
		print_char_array(cout,findx(s7,s7));
		cout << strcmp(s7,s7) << endl;
		char* s8 = new char;
		for(int i=0; i < 14; ++i) s8[i] = 's';
		char* s9 = strdup(s8);
		print_char_array(cout,s9);
*/
// End incorrect code Ex.18.4

		return 0;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << '\n';
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
