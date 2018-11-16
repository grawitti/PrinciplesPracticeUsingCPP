/*
     Date: 16.11.18
     Author: Grawitti
     Chapter 18 – Principles and Practice Using C++   
     Exercise 10
*/

#include "../../std_lib_facilities.h"

using namespace std;

// is palindrome, use string
bool is_palindrome(const string &s)
{
	string se;
	for (int i = s.length() - 1; i >= 0; --i)
		se += s[i];
	for (int i = 0; i < s.length() - 1; ++i)
		if (s[i] != se[i])
			return false;
	return true;
}

// is palindrome, use array
bool is_palindrome_a(const char s[], int n)
{
	char se[n];
	for (int i = n - 1; i >= 0; --i)
		se[(n - 1) - i] = s[i];
	for (int i = 0; i < n - 1; ++i)
		if (s[i] != se[i])
			return false;
	return true;
}

// is palindrome, use pointer
bool is_palindrome_p(char *s, int n)
{
	char *se = new char[n];
	se += n - 1;
	for (int i = n; i > 0; --i)
	{
		*se = *s;
		if (i > 1)
			se--;
		s++;
	}
	s -= n;
	for (int i = 0; *s; ++i)
	{
		if (*s != *se)
			return false;
		s++;
		se++;
	}
	return true;
}

istream &read_word(istream &is, char *buffer, int max)
{
	// is.width(max);
	is >> buffer;
	if(strlen(buffer) > max)
	{
		cout << "Characters in string > 128! Continue (y/n)?\n";
		char answer;
		cin >> answer;
		switch(answer)
		{
			case 'n': buffer[128] = 0;
			break;

			case 'y': 
			break;

			default: error("y or n!");
		}
	}
	return is;
}

int main()
{
	try
	{
/* 
//strings
		for(string s; cin>>s;)
		{
			if(s == "exit") break;
			cout << s << " is";
			if(!is_palindrome(s)) cout << " not";
			cout << " a palindrome\n";
		}
*/

// arrays
		const int max = 128;
		char* s = new char;
		for(; read_word(cin,s,max); )
		{
			if(*s=='q') break;
			cout << s << " is";
			if(!is_palindrome_a(s,strlen(s))) cout << " not";
			cout << " a palindrome\n";	
		}
		delete s;

/* 
		const int max = 128;
		for (char s[max]; read_word(cin, s, max);)
		{
			if (*s == 'q')
				break;
			cout << s << " is";
			if (!is_palindrome_p(&s[0], strlen(s)))
				cout << " not";
			cout << " a palindrome\n";
		}
*/
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
