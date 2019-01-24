/*
    Date: 22.01.18
    Author: Grawitti
	Description: 
    Chapter 19 – Principles and Practice Using C++   
	Exercise - 8
*/

#include "../../std_lib_facilities.h"

using namespace std;

// user defined type for testing
template<class T> struct S {
    S() : i(0), d(0), c(0), s(""), t(T()) { }
    S(int ii, double dd, char cc, const string& ss, const T& tt)
        : i(ii), d(dd), c(cc), s(ss), t(tt) { }
    int i;
    double d;
    char c;
    string s;
    T t;
};
//------------------------------------------------------------------------------

template<class T> ostream& operator<<(ostream& os, S<T> s)
{
	return os << s.i << ' ' << s.d << ' ' << s.c << ' ' << s.s << ' ' << s.t;
}

template<typename T> class allocator_r {
public:
// Выделение памяти для n объектов типа Т
	T* allocate(int n) {
			T* p = static_cast<T*>(malloc(sizeof(T)*n));
			if(p==0) error("allocate: could not allocate memory.");
			return p;
	}	

// Освобождение памяти занятой n объектами типа Т с адресса р
	void deallocate(T* p) { free(p); }
// Создание объекта тиап Т со значением v по адресу p
	void construct(T* p, const T& v) {
		new (p) T(v); // Размещающий new
	}

	void destroy(T* p) { p->~T();} // Уничтожение объекта Т по адресу p Явный вызов деструктора класса
};

template<typename T, typename A = allocator_r<T>> class vector_a {
	A alloc;
	int sz;
	T* elem;
	int space;
public:
	vector_a() : sz(0), elem(0), space(0) {}
	explicit vector_a(int s);
	vector_a(const vector_a&); // copy constructor
	vector_a& operator=(const vector_a&); // copy assignment
	~vector_a();
	T& operator[](int n) { return at(n); }
	const T& operator[](int n) const { return at(n); }

	T& at(int n);
	const T& at(int n) const;

	int size() const { return sz; }
	int capacity() const { return space; }

	void resize(int newsize, T val = T());
	void push_back(const T& d);
	void reserve(int newalloc);

};

template<typename T, typename A>
void vector_a<T,A>::reserve(int newalloc) {
	if (newalloc<=space) return;
	T* p = alloc.allocate(newalloc);

	for(int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]);
	for(int i=0; i<sz; ++i) alloc.destroy(&elem[i]);
	alloc.deallocate(elem);
	elem = p;
	space = newalloc;
}

template<typename T, typename A>
void vector_a<T,A>::push_back(const T& val)
{
	if(space==0) reserve(8);
	else if(sz==space) reserve(2*space);
	alloc.construct(&elem[sz],val);
	++sz;
}

template<typename T, typename A>
void vector_a<T,A>::resize(int newsize, T val)
{
	reserve(newsize);
	for(int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);
	for(int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]);
	sz = newsize;
}

template<typename T, typename A>
T& vector_a<T,A>::at(int n)
{
	if(n<0 || sz<=n) throw Range_error(n);
	return elem[n];
}

template<typename T, typename A>
const T& vector_a<T,A>::at(int n) const
{
	if(n<0 || sz<=n) throw Range_error(n);
	return elem[n];
}

template<typename T, typename A>
vector_a<T,A>::vector_a(const vector_a& a) 
	: sz{a.sz}, elem{alloc.allocate(a.sz)}, space{a.sz} {
	for(int i=0; i<sz; ++i) { alloc.construct(&elem[i],a.elem[i]); }
}

template<typename T, typename A>
vector_a<T,A>::vector_a(int s) :sz(s), elem(alloc.allocate(s)), space(s) {
	for(int i=0; i<sz; ++i) { alloc.construct(&elem[i],T()); }
}

template<typename T, typename A>
vector_a<T,A>& vector_a<T,A>::operator=(const vector_a& a) {
	if(this==&a) return *this; // check self-assignment
	if(a.sz<=space) {
		for (int i=0; i<a.sz; ++i) { alloc.construct(&elem[i],a.elem[i]); }
		sz = a.sz;
		return *this;
	}

	T* p = alloc.allocate(a.sz);
	for(int i=0; i<a.sz; ++i) { alloc.construct(&p[i],a.elem[i]); }
	for(int i=0; i<sz; ++i) { alloc.destroy(&elem[i]); }
	space = sz = a.sz;
	elem = p;
	return *this;
}

template<typename T, typename A>
vector_a<T,A>::~vector_a() {
	for(int i=0; i<sz; ++i) { alloc.destroy(&elem[i]); }
	alloc.deallocate(elem);
}

// vector diagnostics
template<class T> void diag_vec(const vector_a<T>& v, const string& desc)
{
    cout << desc << "\n";
    cout << "\tsize: " << v.size() << "\n";
    cout << "\tcapacity: " << v.capacity() << "\n\t";
    for (int i = 0; i<v.size(); ++i)
        cout << v[i] << ' ';
    cout << "\n";
}

int main()
{
	try
	{
// test integer
    // default constructor
    vector_a<int> v;
    diag_vec(v,"constructed with v");

    // constructor with int argument
    vector_a<int> v1(5);
    diag_vec(v1,"constructed with v1(5)");

// Check for bad index access
//	cout << v1[6] << endl;
//	cout << v1[-1] << endl;

    // copy constructor
    for (int i = 0; i<v1.size(); ++i) v1[i] = i;
    vector_a<int> v2 = v1;
    diag_vec(v2,"copy constructed from modified v1");

    // copy assignment
    vector_a<int> v3(1);   // shorter than v2
    diag_vec(v3,"v3 after initialisation");
    v2 = v2;    // self-assignment
    v1 = v2;    // copy assignment without need to allocate new memory
    v3 = v2;    // copy assignment with new allocation required
    diag_vec(v3,"v3 after copy assignment from v2");

    // range checked access
//    cout << v1.at(5) << "\n";   // runtime error

    // growth
    v3.reserve(5);  // nothing should happen
    diag_vec(v3,"v3 after reserve(5)");
    v3.reserve(10); // adding space
    diag_vec(v3,"v3 after reserve(10)");
    v3.resize(3);
    diag_vec(v3,"v3 after resize(3)");
    v3.resize(10);
    diag_vec(v3,"v3 after resize(10)");
    v3.push_back(99);
    v3.push_back(100);
    diag_vec(v3,"v3 after two push_back()");

    // test string
    // default constructor
    vector_a<string> vs;
    diag_vec(vs,"constructed with vs");

    // constructor with int argument
    vector_a<string> vs1(5);
    diag_vec(vs1,"constructed with vs1(5)");

    // copy constructor
    vs1[0] = "zero";
    vs1[1] = "one";
    vs1[2] = "two";
    vs1[3] = "three";
    vs1[4] = "four";
    vector_a<string> vs2 = vs1;
    diag_vec(vs2,"copy constructed from modified vs1");

    // copy assignment
    vector_a<string> vs3(1);   // shorter than vs2

    diag_vec(vs3,"vs3 after initialisation");
    vs2 = vs2;    // self-assignment
    vs1 = vs2;    // copy assignment without need to allocate new memory
    vs3 = vs2;    // copy assignment with new allocation required
    diag_vec(vs3,"vs3 after copy assignment from vs2");

    // range checked access
//    cout << vs1.at(5) << "\n";   // runtime error

    // growth
    vs3.reserve(5);  // nothing should happen
    diag_vec(vs3,"vs3 after reserve(5)");
    vs3.reserve(10); // adding space
    diag_vec(vs3,"vs3 after reserve(10)");
    vs3.resize(3);
    diag_vec(vs3,"vs3 after resize(3)");
    vs3.resize(10);
    diag_vec(vs3,"vs3 after resize(10)");
    vs3.push_back("ninety-nine");
    vs3.push_back("one hundred");
    diag_vec(vs3,"vs3 after two push_back()");

    // test user defined type
    // default constructor
    vector_a<S<bool> > vudt;
    diag_vec(vudt,"constructed with vudt");

    // constructor with int argument
    vector_a<S<bool> > vudt1(5);
    diag_vec(vudt1,"constructed with vudt1(5)");

    // copy constructor
    for (int i = 0; i<vudt1.size(); ++i) {
        vudt1[i].i = i;
        vudt1[i].d = 1.1*i;
        vudt1[i].c = 'a'+i;
        ostringstream oss;
        oss << "string" << vudt1[i].c;
        vudt1[i].s = oss.str();
        vudt1[i].t = i%2==0;
    }
    vector_a<S<bool> > vudt2 = vudt1;
    diag_vec(vudt2,"copy constructed from modified vudt1");

    // copy assignment
    vector_a<S<bool> > vudt3(1);   // shorter than vs2
    diag_vec(vudt3,"vudt3 after initialisation");
    vudt2 = vudt2;    // self-assignment
    vudt1 = vudt2;    // copy assignment without need to allocate new memory
    vudt3 = vudt2;    // copy assignment with new allocation required
    diag_vec(vudt3,"vudt3 after copy assignment from vudt2");

    // range checked access
//    cout << vudt1.at(5) << "\n";   // runtime error

    // growth
    vudt3.reserve(5);  // nothing should happen
    diag_vec(vudt3,"vudt3 after reserve(5)");
    vudt3.reserve(10); // adding space
    diag_vec(vudt3,"vudt3 after reserve(10)");
    vudt3.resize(3);
    diag_vec(vudt3,"vudt3 after resize(3)");
    vudt3.resize(10,vudt2[4]);
    diag_vec(vudt3,"vudt3 after resize(10,vudt2[4])");
    vudt3.push_back(vudt2[2]);
    vudt3.push_back(vudt2[3]);
    diag_vec(vudt3,"vudt3 after two push_back()");

    // all destructors are called here
		keep_window_open();
		return 0;
	}
	catch (const exception &e)
	{
		cerr << "Exception: " << e.what() << ";\n";
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
