#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите число от 0 до 4 словом, например: ноль, и нажниме Enter\n";
		string word = "";
		cin >> word;
		if (word == "ноль") cout << "Вы ввели слово " << word << " = 0\n";
			else if (word == "один") cout << "Вы ввели слово " << word << " = 1\n";
				else if (word == "два") cout << "Вы ввели слово " << word << " = 2\n";
					else if (word == "три") cout << "Вы ввели слово " << word << " = 3\n";
						else if (word == "четыре") cout << "Вы ввели слово " << word << " = 4\n";
							else cout << "Я умею считать только от 0-4, слово: |" << word << "| мне не известно!\n";
	}
