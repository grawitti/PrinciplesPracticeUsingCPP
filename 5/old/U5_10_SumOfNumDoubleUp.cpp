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
void printResults(vector<double> printSumVector, vector<double> printDiffVector) // Принимает вектор целых цисел
{
  double sum = 0;
  cout << "\nСумма " << printSumVector.size() << " чисел(а) ( ";
  for (double x : printSumVector)	
  	{
    	cout << x << ' ';
    	sum+=x;
  	}
  	cout << ") равна " << sum << '\n';
  	cout << "Разность между соседними числами: ( ";
  	for (double x : printDiffVector)	
  	{
    	cout << x << ' ';
  	}
  	cout << ")\n";
}

int main () 
{
	try 
	{
		cout << "Введите количество суммируемых значений:\n";
		int size = -1;
		cin >> size;
		if (size < 1) throw 1; // Проверка на положительное значение количества суммируемых чисел
  		cout << "Введите несколько целых чисел (любой символ для окончания ввода):\n";
  		double inputNumber;
  		vector<double> numbers;
  		vector<double> numbersFix;
  		vector<double> diffNumbers;
  		for (int i = 0; cin >> inputNumber; i++) 
  		{
  			numbers.push_back(inputNumber); // Проверка на неявное преобразование переменной inputNumber типа double в тип int
  			if (i+1 <= size)
  			{	
  				if (numbersFix.size()%2)
  				{
  					diffNumbers.push_back(numbersFix[i-1] - inputNumber);
  					cout << numbersFix[i-1] << '\t' << inputNumber << '\n';
  				}
  				numbersFix.push_back(inputNumber);
  			}
  		}
  		if (numbersFix.size() < size) throw 2; // Проверка что введено верное количество чисел
  		if (numbersFix.size() < numbers.size()) 
    	{
    		cout << "Вы ввели: " << numbers.size() << " чисел(а), это больше чем ожидалось!\n"; 
      		printResults(numbers, diffNumbers);
      		printResults(numbersFix, diffNumbers);
      		return 0;
    	}	else 
      		{
    			printResults(numbers, diffNumbers);
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
