
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <cmath>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <random>

using namespace std;

//------------------------------------------------------------------------------

// Helper function to show an error message
inline void error(const string& errormessage)
{
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

inline void error(string s1, string s2)
{
    error(s1+s2);
}

//------------------------------------------------------------------------------
// Generate random int 
inline int rand_int(int min, int max)
{
    static default_random_engine ran;
    return uniform_int_distribution<>(min,max) (ran);
}

//------------------------------------------------------------------------------

#endif // STD_LIB_FACILITIES_GUARD
