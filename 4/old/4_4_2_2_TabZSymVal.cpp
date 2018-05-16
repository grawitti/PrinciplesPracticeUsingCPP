#include<iostream>
#include<cmath>
using namespace std;

int main () {
	int value=0;
	for (char symbol = 'A'; symbol<='Z'; symbol++) {
		value=symbol;
		cout << symbol << '\t' << value << '\n';
	}
}
