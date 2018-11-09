#include <iostream>
#include <vector>

using namespace std;

class One
{
  public:
    One(string ss, int ii) : s(ss), i(ii)
    {
        cout << "constructor One {\n";
    }
    ~One()
    {
        cout << "} destructor One\n";
    }

  private:
    string s;
    int i;
};

class Two : public One
{
  public:
    Two(string ss, int ii) : One(ss, ii), i(ii), s(ss)
    {
        cout << "constructor Two {\n";
    }
    ~Two()
    {
        cout << "} destructor Two\n";
    }

  private:
    string s;
    int i;
};

int main()
{
    {
        One o("1",1);
    }
    
    Two t("2",2);
}