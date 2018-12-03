/*
    Date: 03.12.18
    Author: Grawitti
	Description: 
    Chapter 18 – Principles and Practice Using C++   
	Exercise 12 - Vumpus
*/

#include "SL_list.h"
#include <random>
#include <ctime>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> random_int_vec(int min, int max, int size)
{
    // random_device rnd_dev;
    mt19937 m_gen(time(0));
    uniform_int_distribution<int> dist(min,max);
    auto gen = bind(dist, m_gen);

    vector<int> vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}

int main()
{
	try
	{
	// 	SL_list l;
    //     for(int i=0; i<rooms_count; ++i)
    //     {
    //         l.push_back(new Link(i));
    //     }
	// 	l.print_s_list();

        vector<int> vi = random_int_vec(3,10,100);
        for(int i : vi) cout << i << ", ";
        cout << endl;

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