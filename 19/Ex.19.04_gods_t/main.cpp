/*
    Date: 25.12.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 4
*/

#include "../../std_lib_facilities.h"

using namespace std;

template<typename T>
struct God
{
	T name;
	T morphology;
	T transport;
	T weapon;
};

class Link {
public:
	God<string> value;
	Link(const God<string>& v, Link* p = nullptr, Link* s = nullptr)
		:value{v}, prev{p}, succ{s} {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find_name(const string& s) ;
	Link* find_morph(const string& s) ;
	Link* advance(int n);
	Link* next() const {return succ;}
	Link* previous() const {return prev;}

private:
	Link* prev;
	Link* succ;

};

Link* Link::insert(Link* n)
{
	if(n==nullptr) return this;
	if(this==nullptr) return n;
	n->succ = this;
	if(this->prev) this->prev->succ = n;
	n->prev = this->prev;
	this->prev = n;
	return n;
}

Link* Link::add(Link* n)
{
	if(n==nullptr) return this;
	if(this==nullptr) return n;
	n->prev = this;
	if(this->succ) this->succ->prev = n;
	n->succ = this->succ;
	this->succ = n;
	return n;
}

Link* Link::erase()
{
	if(this==nullptr) return nullptr;
	if(this->succ) this->succ->prev = this->prev;
	if(this->prev) this->prev->succ = this->succ;
	return this->succ;
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
	else if(n<0)
	{
		while(n++)
		{
			if(p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
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
		Link* gods = new Link{God<string>{"Thor","Norse","","Thunderbolt"}};
		gods = gods->insert(new Link{God<string>{"Odin","Norse","flying horse","Goongner"}});
		gods = gods->insert(new Link{God<string>{"Zeus","Greek","","Thunderbolt"}});
		gods = gods->insert(new Link{God<string>{"Freia","Norse"}});
		gods = gods->insert(new Link{God<string>{"Hera","Greek"}});
		gods = gods->insert(new Link{God<string>{"Athena","Greek","","Sword"}});
		gods = gods->insert(new Link{God<string>{"Mars","Greek"}});
		gods = gods->insert(new Link{God<string>{"Rod","Sloviansky","","Rain"}});
		gods = gods->insert(new Link{God<string>{"Svarog","Sloviansky","","Thunderbolt"}});

		cout << "\nAll gods:\n";
		print_all(gods);

		Link* p = gods->find_name("Mars");
		if(p) p->value.name = "Ares";

		Link* greek_gods = nullptr;
		Link* p2 = gods;
		while(p2)
		{
			if(p2->value.morphology == "Greek") greek_gods = greek_gods->insert(new Link{p2->value});
			p2=p2->next();
		}
		cout << "\nGreek  gods:\n";
		print_all(greek_gods);

		Link* norse_gods = nullptr;
		Link* p3 = gods;
		while(p3)
		{
			if(p3->value.morphology == "Norse") norse_gods = norse_gods->insert(new Link{p3->value});
			p3=p3->next();
		}
		cout << "\nNorse gods:\n";
		print_all(norse_gods);

		Link* slovian_gods = nullptr;
		Link* p4 = gods;
		while(p4)
		{
			if(p4->value.morphology == "Sloviansky") slovian_gods = slovian_gods->insert(new Link{p4->value});
			p4=p4->next();
		}
		cout << "\nSloviansky gods:\n";
		print_all(slovian_gods);

		return 0;
	}
	catch (const exception &e)
	{
		cerr << "Exception: " << e.what() << '\n';
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