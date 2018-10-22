/**
 Дата создания: 13.09.18
 Автор: Руслан
 Назначение: 
 Глава 15, зад. Определение класса1-9, стр. 603-604, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

using namespace std;

struct Person {
public:
	Person(string fn = "First Name", string sn = "Second Name", int a = 0) :first_names(fn), second_names(sn),  ages(a) 
	{
		checkPerson(first_names,second_names,ages); 
	}
	string first_name() const { return first_names; }
	string second_name() const { return second_names; }
	int age() const { return ages;  }
	void checkPerson (const string& first_name, const string& second_name, const int& age); 
	friend istream& operator>>(istream& is, Person& p);
	Person& operator=(const Person& p);
private:
	string first_names;
	string second_names;
	int ages;
};

void Person::checkPerson (const string& first_name, const string& second_name, const int& age) 
{
	if (age < 0 || age > 150) error("Возраст < 0 или > 150.",age);
	for(char c : first_name) 
	{
		switch(c) {
			case ';': case ':': case '\"': case '\'':
		   	case '[': case ']': case '*': case '&': case '^':
			case '%': case '$': case '#': case '@': case '!':
			error("first_name содержит не поддерживаемый символ",c);
		default: break;
		}
	}
	for(char c : second_name) 
	{
		switch(c) {
			case ';': case ':': case '\"': case '\'':
		   	case '[': case ']': case '*': case '&': case '^':
			case '%': case '$': case '#': case '@': case '!':
			error("second_name содержит не поддерживаемый символ",c);
		default: break;
		}
	}
}

istream& operator>>(istream& is, Person& p) {
	Person pp;
	if (is >> pp.first_names >> pp.second_names >> pp.ages) 
	{
		p = pp;
		return is;
	}
	else 
	{
		is.clear(ios_base::failbit);
		cerr << "Ошибка ввода данных.";
		return is;
	}	
}

ostream& operator<<(ostream& os, Person p)
{
	return os << p.first_name() << ' ' << p.second_name() << ", " << p.age();
}

Person& Person::operator=(const Person& p)
{
	//if (this.names == p.names) return *p;
	checkPerson(p.first_name(),p.second_name(),p.age());
	first_names = p.first_names;
	second_names = p.second_names;
	ages = p.ages;
	return *this;
}

int main()
{
	try 
	{
		vector<Person> vp;
		cout << "Введите Имя Фамилию возраст и нажмите клавишу Enter. (Например: Иван Иванов 20)." << endl;
		for(char c;  cin >> c; )
		{
			if(c == '.') break;
			cin.putback(c);
			Person temp_p;
		   	cin >> temp_p; 
			cout << "Вводите еще или выведите резельтаты, с помощью символа: ." << endl;
			vp.push_back(temp_p);
		} 		

		for(Person p : vp) cout << p << endl;

		keep_window_open();
	}
	catch (exception& e) 
	{
		cerr << "\nОшибка: " << e.what() << endl;
		return 1;
		keep_window_open();
	}
	catch (...) 
	{
		cerr << "\nНеизвестное исключение!\n";
		return 2;
		keep_window_open();
	}
	return 0;
}
