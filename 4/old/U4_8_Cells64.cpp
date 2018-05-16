#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


// Основная функция
int main () {
	int cellsNumber = 1;
	int cellsSum = 1;
	for (int i = 1; i <= 64; i++) {
		cellsSum*=2;
		if (cellsSum > 1000 and cellsSum < 2000) {
			cout << "В " << i << " клетке: " << '\t' << cellsSum << " зерен." << '\n';
		}
		if (cellsSum > 1000000 and cellsSum < 2000000) {
			cout << "В " << i << " клетке: " << '\t' << cellsSum << " зерен." << '\n';
		}
		if (cellsSum > 1000000000 and cellsSum < 2000000000) {
			cout << "В " << i << " клетке: " << '\t' << cellsSum << " зерен." << '\n';
		}
		cout << i << '\t' << cellsSum << '\n';
	}
}
