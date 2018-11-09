#include <iostream>
#include <vector>

using namespace std;

int main()
{
    char c = 'c';
    char* pc = &c;
    bool b = true;
    bool* pb = &b;
    int i = 1000;
    int* pi = &i;
    double d = 1000.0;
    double* pd = &d;
    vector<int> v(1000);
    string s = "ksjdsbdfksdjbf&*%&$^#&89898989898989898989898898989898989898989898989";
    string* ps = &s;
    cout << "sizeof(char)=" << sizeof(char) << "\tsizeof(c)=" << sizeof(c) << endl
        << "sizeof(char*)=" << sizeof(char*) << "\tsizeof(pc)=" << sizeof(pc) << endl
         << "sizeof(bool)=" << sizeof(bool) << "\tsizeof(b)=" << sizeof(b) << endl
          << "sizeof(bool*)=" << sizeof(bool*) << "\tsizeof(pb)=" << sizeof(pb) << endl
         << "sizeof(int)=" << sizeof(int) << "\tsizeof(i)=" << sizeof(i) << endl
         << "sizeof(int*)=" << sizeof(int*) << "\tsizeof(pi)=" << sizeof(pi) << endl
         << "sizeof(double)=" << sizeof(double) << "\tsizeof(d)=" << sizeof(d) << endl
         << "sizeof(double*)=" << sizeof(double*) << "\tsizeof(pd)=" << sizeof(pd) << endl
         << "sizeof(string)=" << sizeof(string) << "\tsizeof(s)=" << sizeof(s) << endl
         << "sizeof(string*)=" << sizeof(string*) << "\tsizeof(ps)=" << sizeof(ps) << endl
         << "sizeof(vector<int> v)=" << sizeof(v) << endl;
}