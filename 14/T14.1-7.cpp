/**
 Дата создания: 16.07.18
 Автор: Руслан
 Назначение: 
 Глава 14, зад. 1-7, стр. 569, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

using namespace std;

class B1 {
public:
	virtual void vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
	void vf() override { cout << "D1::vf()\n";  }
	void f() { cout << "D1::f()\n";  }
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2::pvf()\n"; }
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	void pvf() override { cout << s << endl; }

	string s{"D21::pvf"};
};

class D22 : public B2 {
public:
	void pvf() override { cout << i << endl; }

	int i{22};
};

void f(B2& b2)
{
	b2.pvf();
}

int main()
{
	try 
	{
		//B1 b1;
		//b1.vf();
		//b1.f();

		//D1 d1;
		//d1.vf();
		//d1.f();

		//B1 &bl = d1;
		//bl.vf();
		//bl.f();
		
		//D2 d2;
		//d2.vf();
		//d2.f();
		//d2.pvf();
		
		D21 d21;
		D22 d22;
		f(d21);
		f(d22);

		
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
