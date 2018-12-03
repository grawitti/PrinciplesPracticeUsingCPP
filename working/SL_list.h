#include "../../std_lib_facilities.h"

struct Link {
	Link(int nn, Link* n = nullptr, Link* b = nullptr, Link* c = nullptr) 
        : n(nn), next(n), room_b(b), room_c(c) { }
	Link* next;
	Link* room_b;
	Link* room_c;
	int n{0};
    bool vumpus{false};
    bool bat{false};
    bool hole{false};
};

class SL_list {
	public:
		SL_list(Link* f = nullptr, Link* l = nullptr) : fir(f), las(l) { }

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
				cout << current->n << endl;
				if(current) current = current->next;
			}
		}
		~SL_list() {  
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