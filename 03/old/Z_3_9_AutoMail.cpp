#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
#include<cmath>
using namespace std;

int main ()
	{
		cout << "Введите Ваше имя и нажмите Enter:\n";
		string firstName;
		cin >> firstName;
		cout << "Введите имя адресата и нажмите Enter:\n";
		string addressFirstName;
		cin >> addressFirstName;
		cout << "Введите имя приятеля в дательном падеже и нажмите Enter:\n";
		string friendFirstName;
		cin >> friendFirstName;
		cout << "Укажите пол приятеля, введите m - если он мужчина или f - если она женщина и нажмите Enter:\n";
		char friendSex = 0;
		cin >> friendSex;
		string massegeSex;
		if (friendSex == 'm') massegeSex = "его";
			else massegeSex = "ее";
		cout << "Введите возраст адресата и нажмите Enter:\n";
		int addressAge = 0;
		cin >> addressAge;
		if (addressAge<=0 || addressAge>110) {
			cout << "Ты шутишь!\n";
			return 0;
		}
		string massegeAge;
		cout
		<< "Дорогой, " << addressFirstName << "!\n"
		<< "Как поживаешь? " << "\n"
		<< "Давно ли ты встречал " << friendFirstName << "?\n"
		<< "Если ты увидишь " << friendFirstName << " пожалуйста попроси " << massegeSex << " позвонить мне.\n"
		<< "Я слышал, ты только что отметил день рождения и тебе исполнилось " << addressAge << " лет.?\n";
		if (addressAge<=12) cout << "На следующий год тебе исполниться " << addressAge+1 << " лет.\n";
		if (addressAge==17) cout << "В следующем году ты сможешь голосовать.\n";
		if (addressAge>65) cout << "Я надеюсь ты не скучаешь на пенсии?\n";
		cout << "\n\nС глубочайшим Уважением " << firstName << "!\n";

	}
