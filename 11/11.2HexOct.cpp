#include "../std_lib_facilities.h"

int main(int argc, char *argv[])
{
	int day = 13;
	int age = 32;

	cout << "dec\t" << day 
		<< "\nhex\t" << hex << day
		<< "\noct\t" << oct << day
		<< "\nage\t" << age << endl;

	cout << showbase << dec<< "dec\t" << day 
		<< "\nhex\t" << hex << day
		<< "\noct\t" << oct << day
		<< "\nage\t" << age << endl;

	int a;
	int b;
	int c;

	cin.unsetf(ios::dec);
	cin.unsetf(ios::oct);
	cin.unsetf(ios::hex);

	cin >> a >> b >> c;
	cout << dec << a << '\t' << b << '\t' << c << endl;
	keep_window_open();

	return 0;
}
