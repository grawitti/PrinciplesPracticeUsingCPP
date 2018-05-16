#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdio.h>
//#include"std_lib_facilities.h"
using namespace std;
/*
Программа суммирующая указанное количство из введенной последовательности чисел
*/

// Функция вывода результатов
void printResults(vector<int> printVector) // Принимает вектор целых цисел
{
  int sum = 0;
  for (int x : printVector)
  	{
    	cout << x << '\t';
    	sum+=x;;
  	}
  	cout << "\nСумма первых: " << printVector.size() << " чисел равна " << sum << '\n';
}

int main () 
{
	try 
	{
		cout << "Введите количество суммируемых значений:\n";
		int size = -1;
		cin >> size;
		if (size < 1) throw 1; // Проверка на положительное значение количества суммируемых чисел
  		cout << "Введите несколько целых чисел (| для окончания ввода):\n";
  		int inputNumber;
  		vector<int> numbers;
  		vector<int> numbersFix;
  		for (int i = 1; cin >> inputNumber; i++) 
  		{
  			numbers.push_back(inputNumber);
  			if (i <= size)
  			{  
    			numbersFix.push_back(inputNumber);
  			}
  		}
  		if (numbersFix.size() < size) throw 2; // Проверка что введено верное количество чисел
  		if (numbersFix.size() < numbers.size()) 
    	{
      		printResults(numbers);
      		return 0;
    	}	else 
      		{
    			printResults(numbersFix);
    			return 0;
   	  		}
	}
	catch (int err) 
	{
		if (err == 1) cerr << "Ошибка! Числа должны быть положительные.\n";
		if (err == 2) cerr << "Ошибка! Мало чисел или некоторые значения не являются числами.\n";
	}
	catch (runtime_error& e) 
	{
		cout << e.what() << '\n';
	} 
}
