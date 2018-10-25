#include<iostream>
#include<cmath>
using namespace std;

int main () {
	int value=0;
	for (char symbol = 'a'; symbol<='z'; symbol++) {
		value=symbol;
		cout << symbol << '\t' << value << '\n';
	}
}
