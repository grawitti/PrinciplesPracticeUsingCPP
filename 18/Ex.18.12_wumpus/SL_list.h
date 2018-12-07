#include "../../std_lib_facilities.h"

struct Link {
	Link(int nn, Link* n = nullptr, Link* b = nullptr, Link* c = nullptr) 
        : n(nn), next(n), room_b(b), room_c(c) { }
	Link* next;
	Link* room_b;
	Link* room_c;
	int n{0};
    bool wumpus{false};
    bool bat{false};
    bool hole{false};
};

class SL_list {
	public:
		SL_list(Link* f = nullptr, Link* l = nullptr, int ss = 0) : fir(f), las(l), s(ss) { }

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
			++s;
		}
		void print_list() const {
		cout << "\nDebug print:\nrooms_n: " << s-1 << endl;
			Link* current = first();
			int wumpus_n = -1;
			int bat_n = -1;
			int hole_n = -1;
			while(current) {
				cout << current->n; 
				if(current->next) cout << " (next: " << current->next->n;
				else cout << " (next: null";
				cout << ", room_b: " << current->room_b->n 
				<< ", room_c: " << current->room_c->n << ");" << endl;
				if(current->wumpus) wumpus_n = current->n;
				if(current->bat) bat_n = current->n;
				if(current->hole) hole_n = current->n;
				if(current) current = current->next;
			}
			cout << "Wumpus in: " << wumpus_n << " room.\n"
				<< "bat in: " << bat_n << " room.\n"
				<< "hole in: " << hole_n << " room.\n\n\n";
		}
		Link* find(int n) const {
			Link* current = first();
			while(current) {
				if(current->n == n) return current;
				if(current) current = current->next;
			}
			return nullptr;
		}
		int size() const { return s; }
		~SL_list() {
			// if(s>0) { 
			// 	Link* current = nullptr;
			// 	if(first()) current = first();
			// 	while(current) {
			// 		if(current) delete current;
			// 		current = current->next;
			// 	}
			// }
			// set_first(nullptr);
			// set_last(nullptr);
			// s = 0;
		}
	private:
		Link* fir;
		Link* las;
		int s;
};