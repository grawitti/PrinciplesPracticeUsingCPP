/*
     Date: 12.11.18
     Author: Grawitti
     Chapter 17 – Principles and Practice Using C++   
     Exercise 10
*/

#include "../../std_lib_facilities.h"

using namespace std;

class Link {
public:
	string value;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		:value{v}, prev{p}, succ{s} {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s) ;
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

Link* Link::find(const string& s) 
{
	Link* p = this;
	while(p)
	{
		if(p->value == s) return p;
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
	cout << "{ ";
	while(p)
	{
		cout << p->value;
		if(p->next()) cout << ", ";
		p=p->next();
	}
	cout << " }\n";
}

int main()
{
    try
    {
		Link* norse_gods = new Link{"Thor"};
		norse_gods = norse_gods->insert(new Link{"Odin"});
		norse_gods = norse_gods->insert(new Link{"Zeus"});
		norse_gods = norse_gods->insert(new Link{"Freia"});

		Link* greek_gods = new Link{"Hera"};
		greek_gods = greek_gods->insert(new Link{"Athena"});
		greek_gods = greek_gods->insert(new Link{"Mars"});
		greek_gods = greek_gods->insert(new Link{"Poseidon"});

		Link* p = greek_gods->find("Mars");
		if(p) p->value = "Ares";

		Link* p2 = norse_gods->find("Zeus");
		if(p2)
		{
			if(p2==norse_gods) norse_gods = p2->next();
			p2->erase();
			greek_gods = greek_gods->insert(p2);
		}

		print_all(norse_gods);

		print_all(greek_gods);

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
