#include<iostream>
#include<cmath>
using namespace std;

int square (int x) {
	int value = x;
	for (int i = 1 ; i < x; i++) {
		value+=x;
	}
	return value;
}
int main () {
	for (int i = 0; i < 100; i++) {
		cout << i << '\t' << square(i) << '\n';
	}
}
