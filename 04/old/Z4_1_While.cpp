#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
		char numberOne;
		char numberTwo;
		while (true) {
			int i = 1;
			while (i <= 2) {
				cin >> numberOne;
				if (numberOne=='|') return 0;
				cin >> numberTwo;
				if (numberTwo=='|') return 0;
				cout << numberOne << '\t' << numberTwo << '\n';
				i++;
			}
		}
}
