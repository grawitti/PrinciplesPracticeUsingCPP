
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"
#include <math.h>
#include <iostream>

namespace Graph_lib {

// defense against ill-behaved Linux macros:
#undef major
#undef minor

//------------------------------------------------------------------------------

// Color is the type we use to represent color. We can use Color like this:
//    grid.set_color(Color::red);
struct Color {
    enum Color_type {
        red=FL_RED,
        blue=FL_BLUE,
        green=FL_GREEN,
        yellow=FL_YELLOW,
        white=FL_WHITE,
        black=FL_BLACK,
        magenta=FL_MAGENTA,
        cyan=FL_CYAN,
        dark_red=FL_DARK_RED,
        dark_green=FL_DARK_GREEN,
        dark_yellow=FL_DARK_YELLOW,
        dark_blue=FL_DARK_BLUE,
        dark_magenta=FL_DARK_MAGENTA,
        dark_cyan=FL_DARK_CYAN
    };

    enum Transparency { invisible = 0, visible=255 };

    Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
    Color(int cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Transparency vv) :c(Fl_Color()), v(vv) { }    // default color

    int as_int() const { return c; }
public:
    char visibility() const { return v; }
    void set_visibility(Transparency vv) { v=vv; }
private:
    char v;    // invisible and visible for now
    Fl_Color c;
};

//------------------------------------------------------------------------------

struct Line_style {
    enum Line_style_type {
        solid=FL_SOLID,            // -------
        dash=FL_DASH,              // - - - -
        dot=FL_DOT,                // .......
        dashdot=FL_DASHDOT,        // - . - .
        dashdotdot=FL_DASHDOTDOT,  // -..-..
    };

    Line_style(Line_style_type ss) :s(ss), w(0) { }
    Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
    Line_style(int ss) :s(ss), w(0) { }

    int width() const { return w; }
    int style() const { return s; }
private:
    int s;
    int w;
};

//------------------------------------------------------------------------------

class Font {
public:
    enum Font_type {
        helvetica=FL_HELVETICA,
        helvetica_bold=FL_HELVETICA_BOLD,
        helvetica_italic=FL_HELVETICA_ITALIC,
        helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
        courier=FL_COURIER,
        courier_bold=FL_COURIER_BOLD,
        courier_italic=FL_COURIER_ITALIC,
        courier_bold_italic=FL_COURIER_BOLD_ITALIC,
        times=FL_TIMES,
        times_bold=FL_TIMES_BOLD,
        times_italic=FL_TIMES_ITALIC,
        times_bold_italic=FL_TIMES_BOLD_ITALIC,
        symbol=FL_SYMBOL,
        screen=FL_SCREEN,
        screen_bold=FL_SCREEN_BOLD,
        zapf_dingbats=FL_ZAPF_DINGBATS
    };

    Font(Font_type ff) :f(ff) { }
    Font(int ff) :f(ff) { }

    int as_int() const { return f; }
private:
    int f;
};

//------------------------------------------------------------------------------

template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;
public:
    Vector_ref() {}
    Vector_ref(T& a) { push_back(a); }
    Vector_ref(T& a, T& b);
    Vector_ref(T& a, T& b, T& c);
    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
    {
        if (a) push_back(a);
        if (b) push_back(b);
        if (c) push_back(c);
        if (d) push_back(d);
    }

    ~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }

    T& operator[](int i) { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }

    int size() const { return v.size(); }
};

//------------------------------------------------------------------------------

typedef double Fct(double);

class Shape  {        // deals with color and style, and holds sequence of lines
public:
    void draw() const;                 // deal with color and draw lines
    virtual void move(int dx, int dy); // move the shape +=dx and +=dy

    void set_color(Color col) { lcolor = col; }
    Color color() const { return lcolor; }
    void set_style(Line_style sty) { ls = sty; }
    Line_style style() const { return ls; }
    void set_fill_color(Color col) { fcolor = col; }
    Color fill_color() const { return fcolor; }

    Point point(int i) const { return points[i]; } // read only access to points
    int number_of_points() const { return int(points.size()); }

    virtual ~Shape() { }
protected:
    Shape();
    virtual void draw_lines() const;   // draw the appropriate lines
    void add(Point p);                 // add p to points
    void set_point(int i,Point p);     // points[i]=p;
//private:
    vector<Point> points;              // not used by all shapes
    Color lcolor;                      // color for lines and characters
    Line_style ls;
    Color fcolor;                      // fill color

    Shape(const Shape&);               // prevent copying
    Shape& operator=(const Shape&);
};

//------------------------------------------------------------------------------

struct Function : Shape {
    // the function parameters are not stored
    Function(Fct f, double r1, double r2, Point orig,
        int count = 100, double xscale = 25, double yscale = 25);
};
//------------------------------------------------------------------------------

struct Fct_stored : Function {
public:
	Fct_stored(Fct ff, double rr1, double rr2, Point o, int c = 100, double xs = 25, double ys = 25, double p = 1) 
	: f(ff), r1(rr1), r2(rr2), xy(o), count(c), xscale(xs), yscale(ys), precisions(p), Function{ff,rr1,rr2,o,c,xs,ys} {  }

	double last_r1() { return r1; }
	double last_r2() { return r2; }
	Point last_xy() { return xy; }
	int last_count() { return count; }
	double last_xscale() { return xscale; }
	double last_yscale() { return yscale; }
	Fct* last_fct() { return f; }

private:
	Fct* f;
    double r1;
    double r2;
    Point xy;
    int count;
    double xscale;
    double yscale;
	double precisions;
};
//------------------------------------------------------------------------------

struct Line : Shape {            // a Line is a Shape defined by two Points
    Line(Point p1, Point p2);    // construct a line from two points
};

//------------------------------------------------------------------------------

struct Rectangle : Shape {

    Rectangle(Point xy, int ww, int hh) : loc(xy), w(ww), h(hh)
    {
        add(xy);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
    }

    Rectangle(Point x, Point y) : w(y.x-x.x), h(y.y-x.y)
    {
		loc = x;
        add(x);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
    }
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
	Point n() const  { return loc+Point{w/2,0}; }
	Point nw() const { return loc; }
	Point ne() const  { return loc+Point{w,0}; }
	Point west() const  { return loc+Point{0,h/2}; }
	Point e() const  { return loc+Point{w,h/2}; }
	Point sw() const  { return loc+Point{0,h}; }
	Point s() const  { return loc+Point{w/2,h}; }
	Point se() const  { return loc+Point{w,h}; }
	Point center() const  { return loc+Point{w/2,h/2}; }
protected:
	Point loc;
    int h;    // height
    int w;    // width
};

//------------------------------------------------------------------------------

struct Striped_rectangle : Rectangle {
	Striped_rectangle(Point xy, int ww, int hh) : Rectangle{xy,ww,hh} {  }

	void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Open_polyline : Shape {         // open sequence of lines
    void add(Point p) { Shape::add(p); }
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Closed_polyline : Open_polyline { // closed sequence of lines
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Regular_polygon : Closed_polyline { // closed sequence of lines
	Regular_polygon(Point p, int rr, int nn) : loc{p}, R{rr}, n{nn}
	{
		if(n < 3) error("Number of sides must be 3 or more.");
		for(int i = 0; i < n; ++i)
		{
			add(getNextPoint(i));
		}
	}
	Regular_polygon() {  }

	Point getNextPoint(int i);

	Point loc; // coordinate of polygon's center
	int R; // Radius
	int n{3}; // Namber of sides
};

//------------------------------------------------------------------------------

struct Regular_hexagon : Regular_polygon {
	Regular_hexagon(Point p, int rr) : Regular_polygon{p, rr, 6} {  }
};

//------------------------------------------------------------------------------

struct Octagon : Regular_polygon {
	Octagon(Point p, int rr) : Regular_polygon{p, rr, 8} {  }
};

//------------------------------------------------------------------------------

Point rotate(const Point& p, Point center, int radius, int grad);

struct Right_triangle : Closed_polyline {
	Right_triangle(Point p, int hh, int ww) : loc{p}, h{hh}, w{ww}
	{
		add(loc);
		add(loc-Point{0,h});
		add(loc+Point{w,0});
	}

	Right_triangle(Point p, int hh, int ww, int grd) : loc{p}, h{hh}, w{ww}, grad{grd}
	{
		Point p1{rotate(loc-Point{0,h},loc,w,grad)};
		Point p2{rotate(loc+Point{w,0},loc,h,grad+90)};
		add(loc);
		add(p1);
		add(p2);
	}

	Point n() { return loc-Point{0,h}; }
	Point s() { return loc+Point{w/2,0}; }
	Point loc;
	int h;
	int w;
	int grad;
};

//------------------------------------------------------------------------------

struct Polygon : Closed_polyline {    // closed sequence of non-intersecting lines
    void add(Point p);
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Lines : Shape {                 // related lines
    void draw_lines() const;
    void add(Point p1, Point p2);      // add a line defined by two points
};

//------------------------------------------------------------------------------

struct Arrow : Line {
    Arrow(Point p1, Point p2) :Line(p1,p2) { }
    void draw_lines() const;
};

//struct Arrow : Lines {                 // related lines
	//Arrow(Point p1, Point p2)
	//{
		//add(p1,p2);
	//}
    //void draw_lines() const;
//};

//------------------------------------------------------------------------------

struct Text : Shape {
    // the point is the bottom left of the first letter
	//Text() {}
    Text(Point x, const string& s) : lab(s), fnt(fl_font()), fnt_sz(fl_size()) { add(x); }

    void draw_lines() const;

    void set_label(const string& s) { lab = s; }
    string label() const { return lab; }

    void set_font(Font f) { fnt = f; }
    Font font() const { return Font(fnt); }

    void set_font_size(int s) { fnt_sz = s; }
    int font_size() const { return fnt_sz; }
	Text& operator=(const Text& right)
	{
		point(0) = right.point(0);
		lab = right.lab;
		return *this;
	}
private:
    string lab;    // label
    Font fnt;
    int fnt_sz;
};

//------------------------------------------------------------------------------

struct Axis : Shape {
    enum Orientation { x, y, z };
    Axis(Orientation d, Point xy, int length,
        int number_of_notches=0, string label = "");

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

    Text label;
    Lines notches;
};

//------------------------------------------------------------------------------

struct Circle : Shape {
    Circle(Point p, int rr);    // center and radius
	Circle() {  }

    void draw_lines() const;

    Point center() const ;
    int radius() const { return r; }
    void set_radius(int rr) { r=rr; }

	Point c() { return loc; }
	Point n() const { return loc-Point{0,r}; }
	Point s() const { return loc+Point{0,r}; }
	Point w() { return loc-Point{r,0}; }
	Point e() { return loc+Point{r,0}; }

protected:
	Point loc;
    int r;
};

//------------------------------------------------------------------------------

struct Striped_circle : Circle {
	Striped_circle(Point p, int rr) : Circle{p,rr} {  }

	void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Immobile_Circle : Circle {
	Immobile_Circle(Point p, int r) : Circle{p,r} {
		add(Point(p.x-r,p.y-r));
	}
	void move(int dx, int dy) { error("Class Immobile_Circle objects cannot be moved."); }
};

//------------------------------------------------------------------------------

struct Smiley : Circle {
	Smiley(Point p, int r) : Circle{p, r} {
		add(Point(p.x-r,p.y-r));
	}
	void draw_eyes() const;
	void draw_mouth() const;
	void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Frowny : Smiley {
	Frowny(Point p, int r) : Smiley{p, r} {
		add(Point(p.x-r,p.y-r));
	}
	void draw_mouth() const;
	void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Smiley_hat : Smiley {
	Smiley_hat(Point p, int r) : Smiley{p, r}
	{
		add(Point(p.x-r,p.y-r));
	}
	void draw_hat() const;
	void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Frowny_hat : Frowny {
	Frowny_hat(Point p, int r) : Frowny{p, r} {
		add(Point(p.x-r,p.y-r));
	}
	void draw_hat() const;
	void draw_lines() const;
};

//------------------------------------------------------------------------------


struct Ellipse : Shape {
	Ellipse() {}
    Ellipse(Point p, int w, int h)    // center, min, and max distance from center
        : loc(p), w(w), h(h)
    {
        add(Point(p.x-w,p.y-h));
    }

    void draw_lines() const;

    Point center() const { return Point(point(0).x+w,point(0).y+h); }
    Point focus1() const { return Point(center().x+int(sqrt(double(w*w-h*h))),center().y); }
    Point focus2() const { return Point(center().x-int(sqrt(double(w*w-h*h))),center().y); }

    void set_major(int ww) { w=ww; }
    int major() const { return w; }
    void set_minor(int hh) { h=hh; }
    int minor() const { return h; }

	Point n() { return loc-Point{0,h}; }
	Point west() { return loc-Point{w,0}; }
	Point c() { return loc; }
	Point e() { return loc+Point{w,0}; }
	Point s() { return loc+Point{0,h}; }
private:
	Point loc;
    int w;
    int h;
};

//------------------------------------------------------------------------------

struct Arc : Ellipse {
	Arc(Point p, int w, int h, int s, int e)
		: w(w), h(h), start(s), end(e)
	{
        add(Point(p.x-w,p.y-h));
	}

	void draw_lines() const;
private:
	int w;
	int h;
	int start;
	int end;
};

//------------------------------------------------------------------------------

struct Box : Shape {
	Box() {}
	Box(Point xy, int w, int h, int d)
		: loc(xy), w(w), h(h), d(d)
		{
			add(xy+Point{w,0}); // Top Right point
			add(xy); // Top left
			add(xy+Point{0,h}); // Bottom left
			add(xy+Point{w,h}); // Bottom right
		}
	Box(Point xy, int w, int h, int d, string lab)
		: loc(xy), w(w), h(h), d(d), lab(lab)
		{
			add(xy+Point{w,0}); // Top Right point
			add(xy); // Top left
			add(xy+Point{0,h}); // Bottom left
			add(xy+Point{w,h}); // Bottom right
		}
	void draw_lines() const;

	Point nw() { return loc; }
	Point n() const { return loc+Point{w/2,0}; }
	Point s() { return loc+Point{w/2,h}; }
	Point west() const { return loc+Point{0,h/2}; }
	Point e() { return loc+Point{w,h/2}; }
	Point center() const { return loc+Point{w/2,h/2}; }

protected:
	Point loc;
	int w; // Width
	int h; // Height
	int d; // Circle diameter for angles
	string lab;
};

//------------------------------------------------------------------------------

struct Marked_polyline : Open_polyline {
    Marked_polyline(const string& m) :mark(m) { }
    void draw_lines() const;
private:
    string mark;
};

//------------------------------------------------------------------------------

struct Marks : Marked_polyline {
    Marks(const string& m) :Marked_polyline(m)
    {
        set_color(Color(Color::invisible));
    }
};

//------------------------------------------------------------------------------

struct Mark : Marks {
    Mark(Point xy, char c) : Marks(string(1,c))
    {
        add(xy);
    }
};

//------------------------------------------------------------------------------

class Striped_closed_polyline : public Closed_polyline
{
public:
    Striped_closed_polyline(vector<Point> pts)
        :points(pts)
    {
        for (int i = 0; i < pts.size(); i++) {
            Closed_polyline::add(pts[i]);
        }
        points.push_back(pts[0]);
		fill_pattern();
		//set_fill_color();
    }
	void fill_pattern();
	//void set_fill_color();
    void draw_lines() const;

    vector<Point> inters;
    Lines pattern;
private:
    Point a;
    int r;
    vector<Point> points;
};

//------------------------------------------------------------------------------

struct Group : Shape {
	void shape_add(Shape& s) { shapes.push_back(s); }

	void draw() const;
	void move(int dx, int dy);
	void set_color(Color col);
	void set_style(Line_style sty);
	void set_fill_color(Color col);

protected:
	Vector_ref<Shape> shapes;
	using Shape::number_of_points;
	using Shape::points;
	using Shape::add;
	using Shape::set_point;
};

//------------------------------------------------------------------------------

struct Chess : Group {
	Chess(Point xy, int i);
	void draw() const;
protected:
	Point loc;
	int size;
	Vector_ref<Shape> board;
	Vector_ref<Shape> checkers;
};

//------------------------------------------------------------------------------

struct Suffix {
    enum Encoding { none, jpg, gif  };
};

Suffix::Encoding get_encoding(const string& s);

//------------------------------------------------------------------------------

struct Image : Shape {
    Image(Point xy, string file_name, Suffix::Encoding e = Suffix::none);
    ~Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
private:
    int w,h;  // define "masking box" within image relative to position (cx,cy)
    int cx,cy;
    Fl_Image* p;
    Text fn;
};

//------------------------------------------------------------------------------

struct Bad_image : Fl_Image {
    Bad_image(int h, int w) : Fl_Image(h,w,0) { }
    void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};


//------------------------------------------------------------------------------
class PseudoWindow : public Shape {
public:
PseudoWindow(Point xy, int hh, int ww, string m) :loc(xy), h(hh), w(ww), mark(m) {  }

Point center() { return loc+Point{w/2,h/2}; }

void draw_lines() const;

private:
Point loc;
int h;
int w;
string mark;
int radius{20};
int top_panel_size{20};
};

//------------------------------------------------------------------------------

struct BinaryTree : public Shape {
public:
	enum Ribs {arrow_down, arrow_up, line};
	BinaryTree(int w, int l, Ribs rr = BinaryTree::line, Color r_col = Color::black) :w_width(w), levels(l), rib(rr), ribs_color(r_col)
	{
		if(levels > 8 || levels < 0) error("levels could not be > 8 and < 0");
		build_tree();
		put_text();
	}

	int step_left(const int& i);
	int step_rigth(const int& i);
	void add_text(string pos, string text);
	void build_tree();
	void put_text();
	void draw_labels() const;
	void draw_ribs() const;
	void draw_lines() const;
protected:
	Vector_ref<Circle> nodes;
	Vector_ref<Text> labels;
	Ribs rib;
	Color ribs_color;
	int w_width;
	int radius{20};
	int interval{radius*2+20};
	int levels;
};

//------------------------------------------------------------------------------

struct BinaryTreeT : public BinaryTree {
	BinaryTreeT(int w, int l) : BinaryTree::BinaryTree(w,l) {}
	void draw_lines() const;
};
//------------------------------------------------------------------------------

struct Gistogram : public Shape
{
public:
	Gistogram(Point p, int xl, int yl, string l)
	: xy(p), xlength(xl), ylength(yl), label(l)	
	{
		if (xlength < 0 || ylength < 0) error("xlength and ylength must be > 0.");
		if (xy.x < 0 || xy.y < 0) error("Point xy must be > 0.");
	}
	void add_col(double v, string l);
	void set_x_label(string l) { x_label=l; }
	void set_y_label(string l) { y_label=l; }
	void set_color_labels(Color c) { color_labels=c; }
	void set_color_values(Color c) { color_values=c; }
	void set_color_columns(Color c) { color_columns=c; }
	void draw_lines() const;
private:
	Point xy;
	int xlength;
	int ylength;
	string label;
	vector<double> cols_value;
	vector<string> cols_label;
	int col_w;
	int offset;
	string x_label{""};
	string y_label{""};
	Color color_labels{Color::black};
	Color color_values{Color::red};
	Color color_columns{Color::blue};
};

//------------------------------------------------------------------------------
} // of namespace Graph_lib

#endif
