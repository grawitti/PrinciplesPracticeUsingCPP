/**
 Дата создания: 12.10.18
 Автор: Руслан
 Назначение: 
 Глава 14, Упр. 15-16, стр. 572, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../std_lib_facilities.h"

using namespace std;

class Iteratorr {
	Iteratorr(){}

	virtual double* next() = 0;
};

class Vector_iterator {
public:
	Vector_iterator(vector<double> vdd) :vd(vdd) {}

	virtual double* next() 
	{
		if(vd.size()<1) return 0;
		double* n = &vd[i];
		if (i<=vd.size()) ++i;
		return n;
	}

private:
	vector<double> vd;
	int i{0};
};

class List_iterator {
public:
	List_iterator(list<double> ldd) :ld(ldd) {}

	virtual double* next()
	{
		if(ld.size()<1) return 0;
		double* n = &*ild;
		ild = std::next(ild); 
		return n;
	}

private:
	list<double> ld;
	list<double>::iterator ild{ld.begin()};
};

int main()
{
	try 
	{
		vector<double> vd {1,2,3,4,5,6};
		Vector_iterator vid{vd};
		cout << "Vector_iterator:\n";
		for(int i = 0; i< vd.size(); ++i)
		{
			double d = *vid.next();
			cout << d << endl;
		}

		list<double> ld {7,8,9,10,11};
		List_iterator lid{ld};
		cout << "List_iterator:\n";
		for(int i = 0; i<ld.size(); ++i)
		{
			double d = *lid.next();
			cout << d << endl;
		}

		cout << "\nlist:\n";
		list<double> ld2 {12,13,14,15};
		list<double>::iterator ild2 = ld2.begin();
		for(int i = 0; i<ld2.size(); ++i)
		{
			double d = *ild2;
			cout << d << endl;
			ild2=std::next(ild2);
		}

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
