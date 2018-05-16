/*
 * Вычисление большего число из 2х целых чисел, без использования операторов ветвления, с побитовыми операторами.
*/

#include "../std_lib_facilities.h"

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

int main(int argc, char *argv[])
{
	cout << "Вычисление большего число из 2х целых чисел, без использования операторов ветвления, с побитовыми операторами.\n";
	
	int a = 0;
	int b = 0;

	cout << "Введите два числа через пробел: ";
	cin >> a >> b;

	cout << "Большее число из введеных: " << getMaxNaive(a,b) << endl;

	keep_window_open();
	
	return 0;
}
