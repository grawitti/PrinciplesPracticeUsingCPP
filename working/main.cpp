/*
    Date: 23.11.18
    Author: Grawitti
	Description: 
    Chapter 18 – Principles and Practice Using C++   
	Exercise 11 - Skip list
*/

#include "../../std_lib_facilities.h"
#include "Vector_ref.h"

struct Link {
	Link(int v, Link* n = nullptr, Link* d = nullptr) : value(v), next(n), down(d) { }
	Link* next;
	Link* down;
	int value;
};

class List {
	public:
		List(Link* f = nullptr, Link* l = nullptr) : fir(f), las(l) { }

		Link* first() const { return fir; }
		void set_first(Link* f) { fir = f; }
		Link* last() const { return las; }
		void set_last(Link* l) { las = l; }
		void push_back(Link* p) {
			if(last()) 
			{
				last()->next = p;
				set_last(p);
				p->next = nullptr;
			}
			else 
			{
				set_first(p);
				set_last(p);
			}
		}
		void print_s_list() const {
			Link* current = first();
			while(current) {
				cout << current->value << endl;
				if(current) current = current->next;
			}
		}
		~List() {  
			Link* current = first();
			while(current) {
				delete current;
				current = current->next;
			}
		}
	private:
		Link* fir;
		Link* las;
};

class Skip_list : public List {
public:
	Skip_list(Link* f = nullptr, Link* l = nullptr) :fir(f), las(l) {
		src_list->set_first(fir);
		src_list->set_last(las);
		create_skip_list();
	}

	void create_skip_list() {
		if(fir && las) {
			src_list->set_first(fir);
			src_list->set_last(las);
		}
		levels.push_back(src_list);
		if(src_list->first() && (src_list->first() != src_list->last())) {
			for(int i=0; levels[i]->first() != levels[i]->last() ;++i)
			{
				cout << "create\n";
				Link* current = levels[i]->first();
				List* temp_list;
				while(current) {
					temp_list->push_back(new Link(current->value));
					temp_list->last()->down = current;
					if (current->next) current=current->next->next;
				}
				levels.push_back(temp_list);
				temp_list->print_s_list();
				levels[levels.size()-1]->print_s_list();
			}
		}
	}

private:
	Link* fir;
	Link* las;
	List* src_list;
	Vector_ref<List*> levels;
};

using namespace std;

int main()
{
	try
	{
		List l;
		l.push_back(new Link(0));
		l.push_back(new Link(1));
		l.push_back(new Link(2));
		l.print_s_list();

		Link* l1 = new Link(5);
		Link* l2 = new Link(6);
		Skip_list sl(l1,l2);
		// sl.push_back(new Link(4));
		// sl.push_back(new Link(3));
		sl.print_s_list();

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
