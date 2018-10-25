#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите оператор и два числа, нажимайте Enter после ввода каждого значения\n";
		char operation = '0';
		double numA = 0;
		double numB = 0;
		cin >> operation >> numA >> numB;
		if (operation == '+')
		{
			double sum = numA+numB;
			cout << numA << " + " << numB << " = " << sum << "\n";
		}
			else if (operation == '-')
			{
				double subtrac = numA-numB;
				cout << numA << " - " << numB << " = " << subtrac << "\n";
			}
				else if (operation == '*')
				{
					double mult = numA*numB;
					cout << numA << " * " << numB << " = " << mult << "\n";
				}
					else if (operation == '/')
					{
						double divine = numA/numB;
						cout << numA << " / " << numB << " = " << divine << "\n";
					}
	}
