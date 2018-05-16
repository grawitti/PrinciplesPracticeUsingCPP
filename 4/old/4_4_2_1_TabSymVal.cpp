#include<iostream>
#include<cmath>
using namespace std;

int main () {
	int value;
	char symbol = 'a';
	while (symbol<='z') {
		value=symbol;
		cout << symbol << '\t' << value << '\n';
		symbol++;
		}
}
