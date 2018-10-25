#include<iostream>
#include<cmath>
using namespace std;

int square (int x) {
	return x*x;
}
int main () {
	for (int i = 0; i < 100; i++) {
		cout << i << '\t' << square(i) << '\n';
	}
}
