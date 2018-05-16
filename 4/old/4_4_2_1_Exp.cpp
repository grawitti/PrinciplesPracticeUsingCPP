#include<iostream>
#include<cmath>
using namespace std;

int square (int x) {
	return x*x;
}
int main () {
		int i = 0;
		while (i<100) {
			cout << i << '\t' << square(i) << '\n';
			++i;
		}
	}
