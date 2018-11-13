/*
     Date: 13.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 14
*/

#include "../../std_lib_facilities.h"

using namespace std;

struct God
{
	string name;
	string morphology;
	string transport;
	string weapon;
};

class Link {
public:
	God value;
	Link(const God& v, Link* s = nullptr)
		:value{v}, succ{s} {}

	Link* add(Link* n);
	Link* erase_last();
	Link* find_name(const string& s) ;
	Link* find_morph(const string& s) ;
	Link* advance(int n);
	Link* next() const {return succ;}

private:
	Link* succ;

};

Link* Link::add(Link* n)
{
	if(n==nullptr) return this;
	if(this==nullptr) return n;
	this->succ = n;
	return n;
}

Link* Link::erase_last()
{
	if(this==nullptr) return nullptr;
	this->succ = nullptr;
	return this;
}

Link* Link::find_name(const string& s) 
{
	Link* p = this;
	while(p)
	{
		if(p->value.name == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::find_morph(const string& s) 
{
	Link* p = this;
	while(p)
	{
		if(p->value.morphology == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n) 
{
	Link* p = this;
	if(p==nullptr) return nullptr;
	if (0<n)
	{
		while(n--)
		{
			if(p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if(n<0) error("It is single-linked list.");
	return p;
}

void print_all(Link* p)
{
	while(p)
	{
		cout << p->value.name << ": (" << p->value.morphology << ", " << p->value.transport << ", " << p->value.weapon << ")";
		if(p->next()) cout << ",\n";
		p=p->next();
	}
	cout << endl; 
}

int main()
{
    try
    {
		Link* gods = new Link{God{"Thor","Norse","","Thunderbolt"}};
		gods = gods->add(new Link{God{"Odin","Norse","flying horse","Goongner"}});
		gods = gods->add(new Link{God{"Zeus","Greek","","Thunderbolt"}});
		gods = gods->add(new Link{God{"Freia","Norse"}});
		gods = gods->add(new Link{God{"Hera","Greek"}});
		gods = gods->add(new Link{God{"Athena","Greek","","Sword"}});
		gods = gods->add(new Link{God{"Mars","Greek"}});
		gods = gods->add(new Link{God{"Rod","Sloviansky","","Rain"}});
		gods = gods->add(new Link{God{"Svarog","Sloviansky","","Thunderbolt"}});

		cout << "\nAll gods:\n";
		print_all(gods);

		Link* p = gods->find_name("Mars");
		if(p) p->value.name = "Ares";

		Link* greek_gods = nullptr;
		Link* p2 = gods;
		while(p2)
		{
			if(p2->value.morphology == "Greek") greek_gods = greek_gods->add(new Link{p2->value});
			p2=p2->next();
		}
		cout << "\nGreek  gods:\n";
		print_all(greek_gods);

		Link* norse_gods = nullptr;
		Link* p3 = gods;
		while(p3)
		{
			if(p3->value.morphology == "Norse") norse_gods = norse_gods->add(new Link{p3->value});
			p3=p3->next();
		}
		cout << "\nNorse gods:\n";
		print_all(norse_gods);

		Link* slovian_gods = nullptr;
		Link* p4 = gods;
		while(p4)
		{
			if(p4->value.morphology == "Sloviansky") slovian_gods = slovian_gods->add(new Link{p4->value});
			p4=p4->next();
		}
		cout << "\nSloviansky gods:\n";
		print_all(slovian_gods);

		return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
		keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception!" << '\n';
		keep_window_open();
        return 2;
    }
}
