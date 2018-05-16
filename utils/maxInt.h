/*
 * Вычисление большего число из 2х целых чисел, без использования операторов ветвления, с побитовыми операторами.
*/

#include <iostream>

using namespace std;

/* Отражаем 1 в 0 и 0 в 1 */
int flip(int bit) {
	return 1^bit;
}

/* Возвращаем 1, если число положительное, и 0, если отрицательное */
int sign(int a) {
	/*
	cout << "a >> (sizeof(int) * CHAR_BIT - 1) = " << a << " >> (" << sizeof(int) << " * " << CHAR_BIT << " - 1) = " 
	<< (a >> (sizeof(int) * CHAR_BIT - 1)) << endl;
	*/
	return flip(((a >> (sizeof(int) * CHAR_BIT - 1))) & 0x1);
}

int getMaxNaive(int a, int b) {
	int k = sign(a - b); // Если результат (a - b) положительный, то k = 1
	int q = flip(k); // Если результат (a - b) отрицательный, то q = 1
	return a * k + b * q; // Меньше число умножается на 0, а большее число на 1.
}