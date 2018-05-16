
#include<iostream>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите 3 Слова, после каждого слова нажимайте Enter\n";
		string valueA = "";
		string valueB = "";
		string valueC = "";
		cin>>valueA>>valueB>>valueC;
		cout << "1 Слово: " << valueA << "\n2 Слово: " << valueB << "\n3 Слово: " << valueC << " \n";
		string valueMin = "";
		if (valueA==valueB & valueB==valueC)
		{
			cout << valueA << ", " << valueB << ", " << valueC << "\n";
		}
		char markMin = '0';
		if (valueA<valueB)
		{
			valueMin=valueA;
			markMin='a';
		}
			else
			{
				valueMin=valueB;
				markMin='b';
			}
		if (valueC<valueMin)
		{
			valueMin=valueC;
			markMin='c';
			cout << "\nМеньшее Слово = " << valueMin << " \n";
		}
		else cout << "\nМеньшее Слово = " << valueMin << " \n";
		cout << valueMin << ", ";
		if (markMin=='a')
		{
			if (valueB<valueC) cout << valueB << ", " << valueC << "\n";
				else cout << valueC << ", " << valueB << "\n";
		}
		if (markMin=='b')
		{
			if (valueA<valueC) cout << valueA << ", " << valueC << "\n";
				else cout << valueC << ", " << valueA << "\n";
		}
		if (markMin=='c')
		{
			if (valueA<valueB) cout << valueA << ", " << valueB << "\n";
				else cout << valueB << ", " << valueA << "\n";
		}

	}
