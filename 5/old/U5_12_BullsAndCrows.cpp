#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include"std_lib_facilities.h"
using namespace std;

/*
Игра  "Быки и коровы". Программа хранит вектор из 4х  различных чисел от 0-9 (например: 1234, но не 2233).
Пользователь должен угадать это число. Допустим программа загадала 1234, а пользователь назвал 1359,
программа должна ответить "1 бык и 1 корова", поскольку пользователь угадал одну цифру(1) в правильной позиции (бык)
и одну правильную цифру (3) в неправильной позиции (корова). Угадывание продолжается пока пользователь не получит 4 быков,
т.е. не угадает все 4 цифры в правильных позициях.
*/

// Функция заполняет вектор 4мя случайными, целыми числами
vector<int> guess() 
{
	vector<int> preGuessNumbers;
	int guessNumber = 0;
	for (int i = 0; i <= 3; )
	{	
		srand(time(NULL));
		guessNumber = 1 + rand() % 9;
		if (preGuessNumbers.size() == 0)
		{
			preGuessNumbers.push_back(guessNumber);
			++i;
		} 
		else 
		{
			for (int j = i; j >= 0; j--) {
				if (guessNumber == preGuessNumbers[j])
				{
					break;
				}
				if (j == 0)
				{
					preGuessNumbers.push_back(guessNumber);
					++i;
				}
			}
		}
	}

//  Вывод значений вектора
	cout << "Загадал! Начинай отгадывать: \n";
	/*for (int x : preGuessNumbers) 
	{
		cout << x;
	}
	cout << '\n';*/
	return preGuessNumbers;
}

// Функция запроса числа у пользователя
int responseNumber () 
{
	int preInputNumber = 0;
	cin >> preInputNumber;
		if (preInputNumber < 0)
		{
			throw 2;
		}
		if (preInputNumber/1000 < 1 || preInputNumber/1000 > 9)
		{
			throw 1;
		}
	return preInputNumber;	
}

// Функция разбора числа по разрядам
vector<int> divDigit(int preInputNumber) 
{
	vector<int> preInputNumbers(4);
		for (int i = 3; i >= 0; i--) 
		{
			preInputNumbers[i] = preInputNumber%10;
			preInputNumber /= 10;
		}
		return preInputNumbers;
}
		

int main () 
{
	try
	{	
		vector<int> guessNumbers;
		bool newGame = true;
		cout << "\nСейчас я загадаю 4х значное целое число, а ты попробуй отгадать!\n";
		// Запрос числа у пользователя
		for (; true; ) 
		{
			if (newGame == true)
			{
				guessNumbers = guess();
				newGame = false;
			}
		
		if (guessNumbers.size() <= 0)
		{
			throw 3;
		}
		int inputNumber = responseNumber();
		// Разбор числа по разрядам и запись его в вектор
		vector<int>inputNumbers = divDigit(inputNumber);

		// Сравнение введеного числа с загаданным
		int bulls = 0;
		int crows = 0;
		for (int i = 0; i < inputNumbers.size(); i++) 
		{
			if (inputNumbers[i] == guessNumbers[i])
			{
				bulls++;
			} else 
			  {
				for (int x : guessNumbers) 
				{
					if (inputNumbers[i] == x)
					{
						crows++;
					}
				}
			  }
		}
		if (bulls == 4)
		{
			cout << "Поздравляем! " << bulls << " бык(а) вы угадали число.\nНачинаем с начала.\n" 
				 << "Подождите несколько секунд я загадаю новое число!\n";
			newGame = true;
			continue;
		}
		cout << bulls << " бык(а) и " << crows << " коров(а,ы)\n";
		}
	}

	// Ошибки
	catch (int err) 
	{
		if (err == 1) cout << "Ошибка! Вы ввели не 4х значное, целое число." << '\n';
		if (err == 2) cout << "Ошибка! Вы ввели отрицательное число." << '\n';
		if (err == 3) cout << "Ошибка! Функция заполнения вектора не вернула вектор." << '\n';
	}
	catch (runtime_error& e) 
	{
		cout << e.what() << '\n';
	} 
}
