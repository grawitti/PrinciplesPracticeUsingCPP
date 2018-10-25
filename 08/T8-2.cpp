#include "../std_lib_facilities.h"

void swapV(int a, int b) {
	int temp;
	temp = a;
	a=b;
	b=temp;
}

void swapR(int& a, int& b) {
	int temp;
	temp = a;
	a=b;
	b=temp;
}

void swapCr(const int& a, const int& b) {
	int temp;
	temp = a;
	a=b;
	b=temp;
}

int main () {
	double x = 7.7;
	double y = 9.9;
	cout << "x: " << x << ", y: " << y << endl;
	swapCr(7.7,9.9);

	cout << "x: " << x << ", y: " << y << endl;
}