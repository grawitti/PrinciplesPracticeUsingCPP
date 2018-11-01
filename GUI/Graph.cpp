
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "Graph.h"

//------------------------------------------------------------------------------

namespace Graph_lib {

//------------------------------------------------------------------------------

ostream& operator<<(ostream& out, Point& a) {
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

//------------------------------------------------------------------------------

Shape::Shape() :
    lcolor(fl_color()),      // default color for lines and characters
    ls(0),                   // default style
    fcolor(Color::invisible) // no fill
{}

//------------------------------------------------------------------------------

void Shape::add(Point p)     // protected
{
    points.push_back(p);
}

//------------------------------------------------------------------------------

void Shape::set_point(int i,Point p)        // not used; not necessary so far
{
    points[i] = p;
}

//------------------------------------------------------------------------------

void Shape::draw_lines() const
{
    if (color().visibility() && 1<points.size())    // draw sole pixel?
        for (unsigned int i=1; i<points.size(); ++i)
            fl_line(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
}

//------------------------------------------------------------------------------

void Shape::draw() const
{
    Fl_Color oldc = fl_color();
    // there is no good portable way of retrieving the current style
    fl_color(lcolor.as_int());            // set color
    fl_line_style(ls.style(),ls.width()); // set style
    draw_lines();
    fl_color(oldc);      // reset color (to previous)
    fl_line_style(0);    // reset line style to default
}

//------------------------------------------------------------------------------


void Shape::move(int dx, int dy)    // move the shape +=dx and +=dy
{
    for (int i = 0; i<points.size(); ++i) {
        points[i].x+=dx;
        points[i].y+=dy;
    }
}

//------------------------------------------------------------------------------
// Поворот точки по окружности с центром в т. center и радиусом radius на угол alpha (в радианах Например 45 градусов = M_PI/4)
Point rotate(const Point& p, Point center, int radius, int grad)
{
	double alpha = (grad*M_PI)/180;
	double xa, ya;
	xa = center.x + radius * sin(alpha);
	ya = center.y + radius * cos(alpha);
	return {int(xa), int(ya)};
}

//------------------------------------------------------------------------------

Line::Line(Point p1, Point p2)    // construct a line from two points
{
    add(p1);    // add p1 to this shape
    add(p2);    // add p2 to this shape
}

//------------------------------------------------------------------------------

void Lines::add(Point p1, Point p2)
{
    Shape::add(p1);
    Shape::add(p2);
}

//------------------------------------------------------------------------------

// draw lines connecting pairs of points
void Lines::draw_lines() const
{
    if (color().visibility())
        for (int i=1; i<number_of_points(); i+=2)
            fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
}

//------------------------------------------------------------------------------
void Arrow::draw_lines() const
{
    Line::draw_lines();

    // add arrowhead: p2 and two points
    double line_len =
        sqrt(double(pow(point(1).x-point(0).x,2) + pow(point(1).y-point(0).y,2)));  // length of p1p2

    // coordinates of the a point on p1p2 with distance 8 from p2
    double pol_x = 8/line_len*point(0).x + (1-8/line_len)*point(1).x;
    double pol_y = 8/line_len*point(0).y + (1-8/line_len)*point(1).y;

    // pl is 4 away from p1p2 on the "left", pl_pol is orthogonal to p1p2
    double pl_x = pol_x + 4/line_len*(point(1).y-point(0).y);
    double pl_y = pol_y + 4/line_len*(point(0).x-point(1).x);

    // pr is 4 away from p1p2 on the "right", pr_pol is orthogonal to p1p2
    double pr_x = pol_x + 4/line_len*(point(0).y-point(1).y);
    double pr_y = pol_y + 4/line_len*(point(1).x-point(0).x);

    // draw arrowhead - is always filled in line color
    if (color().visibility()) {
        fl_begin_complex_polygon();
        fl_vertex(point(1).x,point(1).y);
        fl_vertex(pl_x,pl_y);
        fl_vertex(pr_x,pr_y);
        fl_end_complex_polygon();
    }
}
//------------------------------------------------------------------------------

// does two lines (p1,p2) and (p3,p4) intersect?
// if se return the distance of the intersect point as distances from p1
inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel)
{
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
    if (denom == 0){
        parallel= true;
        return pair<double,double>(0,0);
    }
    parallel = false;
    return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
                                ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
}

//------------------------------------------------------------------------------

//intersection between two line segments
//Returns true if the two segments intersect,
//in which case intersection is set to the point of intersection
bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
}

//------------------------------------------------------------------------------

void Polygon::add(Point p)
{
    int np = number_of_points();

    if (1<np) {    // check that thenew line isn'Pt parallel to the previous one
        if (p==point(np-1)) error("polygon point equal to previous point");
        bool parallel;
        line_intersect(point(np-1),p,point(np-2),point(np-1),parallel);
        if (parallel)
            error("two polygon points lie in a straight line");
    }

    for (int i = 1; i<np-1; ++i) {    // check that new segment doesn't interset and old point
        Point ignore(0,0);
        if (line_segment_intersect(point(np-1),p,point(i-1),point(i),ignore))
            error("intersect in polygon");
    }


    Closed_polyline::add(p);
}

//------------------------------------------------------------------------------

void Polygon::draw_lines() const
{
    if (number_of_points() < 3) error("less than 3 points in a Polygon");
    Closed_polyline::draw_lines();
}

//------------------------------------------------------------------------------

void Open_polyline::draw_lines() const
{
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility())
        Shape::draw_lines();
}

//------------------------------------------------------------------------------

void Closed_polyline::draw_lines() const
{
    Open_polyline::draw_lines();    // first draw the "open poly line part"
    // then draw closing line:
    if (color().visibility())
        fl_line(point(number_of_points()-1).x,
        point(number_of_points()-1).y,
        point(0).x,
        point(0).y);
}

//------------------------------------------------------------------------------

void Striped_closed_polyline::fill_pattern()
{
    Point ymax = points[0]; // Find minimum and maximum points
    Point ymin = points[0];
    for (int i = 0; i < points.size(); i++) {
        if (points[i].y > ymax.y) {
            ymax = points[i];
        }
        if (points[i].y < ymin.y) {
            ymin = points[i];
        }
    }
    int delta = ymax.y - ymin.y;
    int step_size = 5;
    for (int i = 0; i < points.size() - 1; i++) {
        int counter = 0;
        for (int j = 0; j < delta; j += step_size) {
            if (points[i].y <= j + ymin.y && points[i + 1].y >= j + ymin.y) {
                Point temp = points[i + 1] - points[i];
                double slope = (double)temp.y / (double)temp.x;
                int x = (double)counter / slope;
                inters.push_back(Point(x + points[i].x, ymin.y + j));
                counter += step_size;
            }
            else if (points[i + 1].y <= j + ymin.y && points[i].y >= j + ymin.y) {
                Point temp = points[i] - points[i + 1];
                double slope = (double)temp.y / (double)temp.x;
                int x = (double)counter / slope;
                inters.push_back(Point(x + points[i + 1].x, ymin.y + j));
                counter += step_size;
            }
        }
    }
    // insertion_sort according to y
    int i, j;
    for (i = 1; i < inters.size(); i++) {
        j = i;
        while ((j>0) && (inters[j].y < inters[j - 1].y)) {
            swap(inters[j], inters[j - 1]);
            j = j - 1;
        }
    }
    for (int i = 0; i < inters.size() - 1; i++) {
        if (inters[i].y == inters[i + 1].y) {
            pattern.add(inters[i], inters[i + 1]);
        }
    }
	//pattern.set_color(col);
}

//------------------------------------------------------------------------------

void Striped_closed_polyline::draw_lines() const
{
    //if (fill_color().visibility()) {    // fill
        //fl_color(fill_color().as_int());
		pattern.draw();
	//}
    Closed_polyline::draw_lines();
}

//------------------------------------------------------------------------------

Point Regular_polygon::getNextPoint(int i)
{
	int x = loc.x + R*cos((2*M_PI*i)/n);
	int y = loc.y + R*sin((2*M_PI*i)/n);
	return Point{x,y};
}

//------------------------------------------------------------------------------

void draw_mark(Point xy, char c)
{
    static const int dx = 4;
    static const int dy = 4;

    string m(1,c);
    fl_draw(m.c_str(),xy.x-dx,xy.y+dy);
}

//------------------------------------------------------------------------------

void Marked_polyline::draw_lines() const
{
    Open_polyline::draw_lines();
    for (int i=0; i<number_of_points(); ++i)
        draw_mark(point(i),mark[i%mark.size()]);
}

//------------------------------------------------------------------------------

void Rectangle::draw_lines() const
{
    if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
        fl_rectf(point(0).x,point(0).y,w,h);
    }

    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,w,h);
    }
}

//------------------------------------------------------------------------------

void Striped_rectangle::draw_lines() const
{
    if (fill_color().visibility()) {    // fill lines
        fl_color(fill_color().as_int());
        fl_rect(point(0).x,point(0).y,w,h);
		for(int i = 1; i < h; i+=2)
		{
			fl_line(loc.x,loc.y+i,loc.x+w-1,loc.y+i);
		}
	}
    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,w,h);
    }
}

//------------------------------------------------------------------------------

Circle::Circle(Point p, int rr)    // center and radius
	: loc(p), r(rr)
{
    add(Point(p.x-r,p.y-r));       // store top-left corner
}

//------------------------------------------------------------------------------

Point Circle::center() const
{
    return Point(point(0).x+r, point(0).y+r);
}

//------------------------------------------------------------------------------

void Circle::draw_lines() const {
	if (fill_color().visibility())
	{
        fl_color(fill_color().as_int());
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
    if (color().visibility()) fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
}

//------------------------------------------------------------------------------
void Clock::draw_lines() const {
    Circle c{xy,size};
    c.set_color(Color::black);
    c.draw();

    Text t12{c.n()-Point{10,5},"12"};
    t12.set_color(Color::black);
    t12.draw();

    Text t3{c.e()+Point{3,5},"3"};
    t3.set_color(Color::black);
    t3.draw();

    Text t6{c.s()+Point{-3,10},"6"};
    t6.set_color(Color::black);
    t6.draw();

    Text t9{c.w()+Point{-10,5},"9"};
    t9.set_color(Color::black);
    t9.draw();

    for(int i = 0; i < arrows.size(); ++i)
    {
        arrows[i].draw();
    }
}
//------------------------------------------------------------------------------

void Clock::get_system_time() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    hh = now->tm_hour % 12;
    mm = now->tm_min;
    ss = now->tm_sec;
}

//------------------------------------------------------------------------------
void Clock::create_lines()
{
    arrows.push_back(new Line(xy,Point{rotate(xy,xy,-size,-6*ss)}));
    arrows[0].set_color(Color::red);
    arrows[0].set_style(Line_style(Line_style::solid,1));
    arrows.push_back(new Line(xy,Point{rotate(xy,xy,-size+0.8*size,-6*mm)}));
    arrows[1].set_color(Color::blue);
    arrows[1].set_style(Line_style(Line_style::solid,2));
    arrows.push_back(new Line(xy,Point{rotate(xy,xy,-size+0.5*size,-30*hh)}));
    arrows[2].set_color(Color::black);
    arrows[2].set_style(Line_style(Line_style::solid,4));
}
//------------------------------------------------------------------------------

void Clock::update_lines()
{
    arrows[0].set_point(1,Point{rotate(xy,xy,-size,-6*ss)});
    arrows[1].set_point(1,Point{rotate(xy,xy,-size+10,-6*mm)});
    arrows[2].set_point(1,Point{rotate(xy,xy,-size+20,-30*hh)});
}

//------------------------------------------------------------------------------


void Striped_circle::draw_lines() const
{
	if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
		for(int i = 2; i < 180; i+=2)
		{
			fl_line((loc.x+r*sin((i*M_PI)/180))-1,loc.y+r*cos((i*M_PI)/180),(loc.x+r*sin(((360-i)*M_PI)/180))+1,loc.y+r*cos(((360-i)*M_PI)/180));
		}
	}
    if (color().visibility())
		fl_color(color().as_int());
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
}

//------------------------------------------------------------------------------

void Smiley::draw_eyes() const
{
	fl_arc(center().x-r/3,center().y-r/3,2,2,0,360); // left eye
	fl_arc(center().x+r/3,center().y-r/3,2,2,0,360); // right eye
}
//------------------------------------------------------------------------------

void Smiley::draw_mouth() const
{
	fl_arc(point(0).x+r/2,point(0).y+r/2,r,r,195,345); // mouth
}

//------------------------------------------------------------------------------

void Smiley::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360); // Circle
		draw_eyes();
		draw_mouth();
}

//------------------------------------------------------------------------------

void Frowny::draw_mouth() const
{
	fl_arc(point(0).x+r/2,point(0).y+r,r,r,15,165);
}
//------------------------------------------------------------------------------

void Frowny::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
		draw_eyes();
		draw_mouth();
}

//------------------------------------------------------------------------------

void Smiley_hat::draw_hat() const
{
	fl_line(n().x-r/2,n().y,n().x+r/2,n().y);
	fl_line(n().x-r/4,n().y,n().x-r/3,n().y-r/3);
	fl_line(n().x+r/4,n().y,n().x+r/3,n().y-r/3);
	fl_line(n().x-r/3,n().y-r/3,n().x+r/3,n().y-r/3);
}

//------------------------------------------------------------------------------

void Smiley_hat::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360); // Circle
		draw_eyes();
		draw_mouth();
		draw_hat();
}

//------------------------------------------------------------------------------

void Frowny_hat::draw_hat() const
{
	fl_line(n().x-r/2,n().y,n().x+r/2,n().y);
	fl_line(n().x-r/3,n().y,n().x-r/4,n().y-r/3);
	fl_line(n().x+r/3,n().y,n().x+r/4,n().y-r/3);
	fl_line(n().x-r/4,n().y-r/3,n().x+r/4,n().y-r/3);
}

//------------------------------------------------------------------------------

void Frowny_hat::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360); // Circle
		draw_eyes();
		draw_mouth();
		draw_hat();
}


//------------------------------------------------------------------------------

void Ellipse::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,w+w,h+h,0,360);
}

//------------------------------------------------------------------------------

void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,w+w,h+h,start,end);
}
//------------------------------------------------------------------------------

void Box::draw_lines() const
{
	if (color().visibility())
	{
		//Lines
		int r = d/2; // Radius
		fl_line(point(0).x-r,point(0).y,point(1).x+r,point(1).y); // Top Line
		fl_line(point(2).x+r,point(2).y-1,point(3).x-r,point(3).y-1); // Bottom
		fl_line(point(1).x,point(1).y+r,point(2).x,point(2).y-r); // Left
		fl_line(point(3).x-1,point(3).y-r,point(0).x-1,point(0).y+r); // Right

		// Arcs
		fl_arc(point(0).x-d,point(0).y,d,d,0,90); // Top right angle. 0,90 - angle for arc = 0 to 90 ...
		fl_arc(point(1).x,point(1).y,d,d,90,180); // Top left
		fl_arc(point(2).x,point(2).y-d,d,d,180,270); // Bottom left
		fl_arc(point(3).x-d,point(3).y-d,d,d,270,360); // Bottom right

		// Text
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(1,12);
		fl_draw(lab.c_str(),west().x+20,west().y);
		fl_font(ofnt,osz);
	}
}

//------------------------------------------------------------------------------

void Text::draw_lines() const
{
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(fnt.as_int(),fnt_sz);
    fl_draw(lab.c_str(),point(0).x,point(0).y);
    fl_font(ofnt,osz);
}

//------------------------------------------------------------------------------

Axis::Axis(Orientation d, Point xy, int length, int n, string lab) :
    label(Point(0,0),lab)
{
    if (length<0) error("bad axis length");
    switch (d){
    case Axis::x:
    {
        Shape::add(xy); // axis line
        Shape::add(Point(xy.x+length,xy.y));

        if (1<n) {      // add notches
            int dist = length/n;
            int x = xy.x+dist;
            for (int i = 0; i<n; ++i) {
                notches.add(Point(x,xy.y),Point(x,xy.y-5));
                x += dist;
            }
        }
        // label under the line
        label.move(length/3,xy.y+20);
        break;
    }
    case Axis::y:
    {
        Shape::add(xy); // a y-axis goes up
        Shape::add(Point(xy.x,xy.y-length));

        if (1<n) {      // add notches
            int dist = length/n;
            int y = xy.y-dist;
            for (int i = 0; i<n; ++i) {
                notches.add(Point(xy.x,y),Point(xy.x+5,y));
                y -= dist;
            }
        }
        // label at top
        label.move(xy.x-10,xy.y-length-10);
        break;
    }
    case Axis::z:
        error("z axis not implemented");
    }
}

//------------------------------------------------------------------------------

void Axis::draw_lines() const
{
    Shape::draw_lines();
    notches.draw();  // the notches may have a different color from the line
    label.draw();    // the label may have a different color from the line
}

//------------------------------------------------------------------------------

void Axis::set_color(Color c)
{
    Shape::set_color(c);
    notches.set_color(c);
    label.set_color(c);
}

//------------------------------------------------------------------------------

void Axis::move(int dx, int dy)
{
    Shape::move(dx,dy);
    notches.move(dx,dy);
    label.move(dx,dy);
}

//------------------------------------------------------------------------------

void Group::draw() const {
	for(int i = 0; i < shapes.size(); ++i) shapes[i].draw();
}

//------------------------------------------------------------------------------

void Group::move(int dx, int dy) {
	for(int i = 0; i < shapes.size(); ++i) shapes[i].move(dx,dy);
}

//------------------------------------------------------------------------------

void Group::set_color(Color col) {
	for(int i = 0; i < shapes.size(); ++i)
	{
		Shape::set_color(col);
		for(int i = 0; i < shapes.size(); ++i) shapes[i].set_color(col);
	}
}

//------------------------------------------------------------------------------

void Group::set_fill_color(Color col) {
	for(int i = 0; i < shapes.size(); ++i)
	{
		Shape::set_fill_color(col);
		for(int i = 0; i < shapes.size(); ++i) shapes[i].set_fill_color(col);
	}
}

//------------------------------------------------------------------------------

void Group::set_style(Line_style sty) {
	for(int i = 0; i < shapes.size(); ++i)
	{
		Shape::set_style(sty);
		for(int i = 0; i < shapes.size(); ++i) shapes[i].set_style(sty);
	}
}

//------------------------------------------------------------------------------

void Chess::draw() const {
	for(int i = 0; i < board.size(); ++i) board[i].draw();
	for(int i = 0; i < checkers.size(); ++i) checkers[i].draw();
}

//------------------------------------------------------------------------------

Chess::Chess (Point xy, int i) :loc(xy), size(i) {
	board.push_back(new Rectangle{loc,size,size});
}

//------------------------------------------------------------------------------

Function::Function(Fct f, double r1, double r2, Point xy,
                   int count, double xscale, double yscale)
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
    if (r2-r1<=0) error("bad graphing range");
    if (count <=0) error("non-positive graphing count");
    double dist = (r2-r1)/count;
    double r = r1;
    for (int i = 0; i<count; ++i) {
        add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
        r += dist;
    }
}
//------------------------------------------------------------------------------

ifstream can_open(const string& s)
// check if a file named s exists and can be opened for reading
{
    ifstream ff(s.c_str());
    return ff;
}

//------------------------------------------------------------------------------

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

Suffix::Encoding get_encoding(const string& s)
{
    struct SuffixMap
    {
        const char*      extension;
        Suffix::Encoding suffix;
    };

    static SuffixMap smap[] = {
        {".jpg",  Suffix::jpg},
        {".jpeg", Suffix::jpg},
        {".gif",  Suffix::gif},
    };

    for (int i = 0, n = ARRAY_SIZE(smap); i < n; i++)
    {
        int len = strlen(smap[i].extension);

        if (s.length() >= len && s.substr(s.length()-len, len) == smap[i].extension)
            return smap[i].suffix;
    }

    return Suffix::none;
}

//------------------------------------------------------------------------------

// somewhat over-elaborate constructor
// because errors related to image files can be such a pain to debug
Image::Image(Point xy, string s, Suffix::Encoding e)
    :w(0), h(0), fn(xy,"")
{
    add(xy);

    if (!can_open(s)) {    // can we open s?
        fn.set_label("cannot open \""+s+'\"');
        p = new Bad_image(30,20);    // the "error image"
        return;
    }

    if (e == Suffix::none) e = get_encoding(s);

    switch(e) {        // check if it is a known encoding
    case Suffix::jpg:
        p = new Fl_JPEG_Image(s.c_str());
        break;
    case Suffix::gif:
        p = new Fl_GIF_Image(s.c_str());
        break;
    default:    // Unsupported image encoding
        fn.set_label("unsupported file type \""+s+'\"');
        p = new Bad_image(30,20);    // the "error image"
    }
}

//------------------------------------------------------------------------------

void Image::draw_lines() const
{
    if (fn.label()!="") fn.draw_lines();

    if (w&&h)
        p->draw(point(0).x,point(0).y,w,h,cx,cy);
    else
        p->draw(point(0).x,point(0).y);
}

//------------------------------------------------------------------------------

void PseudoWindow::draw_lines() const {
	Box bx{loc,w,h,radius};
	Line lt{loc+Point{0,top_panel_size},loc+Point{w-1,top_panel_size}};
	Point start_buttons{loc+Point{10,5}};
	bx.draw();
	lt.draw();
	Vector_ref<Rectangle> buttons;
	vector<Color> buttons_color {Color::red, Color::yellow, Color::green};
	int buttons_size = 10;
	int buttons_offset = 10;
	for(int i = 0; i<3; ++i)
	{
		buttons.push_back(new Rectangle{start_buttons+Point{i*(buttons_size+buttons_offset),0},buttons_size,buttons_size});
		buttons[i].set_fill_color(buttons_color[i]);
		buttons[i].draw();
	}
}

//------------------------------------------------------------------------------

void BinaryTree::draw_ribs() const
{
	for(int i = 0; i < nodes.size(); i++)
	{
		if(i>0)
		{
			Vector_ref<Shape> ribs;
			Point start_point{nodes[i].n()};
			Point end_point;
			if(i%2 != 0) end_point = {nodes[i/2].s()};
			else end_point = {nodes[(i/2)-1].s()};
			switch(rib) {
				case BinaryTree::arrow_up:
				{
					ribs.push_back(new Arrow(start_point,end_point));
				break;
				}
				case BinaryTree::arrow_down:
				{
					swap(start_point.x,end_point.x);
					swap(start_point.y,end_point.y);
					ribs.push_back(new Arrow(start_point,end_point));
				break;
				}
				default:
				{
					ribs.push_back(new Line(start_point,end_point));
				break;
				}
			}
			ribs[ribs.size()-1].set_color(ribs_color);
			ribs[ribs.size()-1].draw();
		}
	}
}
//------------------------------------------------------------------------------

int BinaryTree::step_left(const int& i)
{
	return i*2+1;
}

//------------------------------------------------------------------------------

int BinaryTree::step_rigth(const int& i)
{
	return i*2+2;
}
//------------------------------------------------------------------------------

void BinaryTree::add_text(string pos, string text)
{
	if (pos.size() > levels-1) error("Text label positions cannot  > levels-1");
	int i = 0;
	for(char c : pos)
	{
		if (!(isspace(c)))
		{
			switch(c)
			{
				case '0':
					return labels[0].set_label(text);
				break;
				case 'l':
					i = step_left(i);
				break;
				case 'r':
					i = step_rigth(i);
				break;
				default: error("Text for oisitions of node must be l, r or 0");
			}
		}
		else continue;
	}
	labels[i].set_label(text);
}
//------------------------------------------------------------------------------

void BinaryTree::build_tree()
{
	int y = interval;
	int w = w_width/2;
	int r = radius;
	for(int i = 0; i < levels; ++i)
	{
		int x = w;
		for(int j = 0; x < w_width-25; ++j)
		{
			if (j%2 == 0)
			{
				nodes.push_back(new Circle(Point{x,y},r));
			}
			x+=w;
		}
		y+=interval;
		y-=y/10; // -10% intervals per level
		w/=2;
		r-=(r*2)/10; // -20% radius per level
	}
}
//------------------------------------------------------------------------------

void BinaryTree::put_text()
{
	for(int i = 0; i < nodes.size(); ++i)
	{
		labels.push_back(new Text(nodes[i].center()+Point{-6,3},""));
	}
}
//------------------------------------------------------------------------------

void BinaryTree::draw_labels() const
{
	for(int i = 0; i < labels.size(); ++i)
	{
		labels[i].draw();
	}
}

//------------------------------------------------------------------------------

void BinaryTree::draw_lines() const {
	for(int i = 0; i < nodes.size(); ++i)
	{
		nodes[i].draw();
	}
	if(nodes.size()>1) draw_ribs();
	draw_labels();
}
//------------------------------------------------------------------------------

void BinaryTreeT::draw_lines() const {
	Vector_ref<Right_triangle> nodes;
	Vector_ref<Line> ribs;
	int y = interval;
	int w = w_width/2;
	int r = radius;
	for(int i = 0; i < levels; ++i)
	{
		int x = w;
		for(int j = 0; x < w_width-25; ++j)
		{
			if (j%2 == 0)
			{
				nodes.push_back(new Right_triangle(Point{x,y},r,r));
				nodes[nodes.size()-1].draw();
				if(i>0)
				{
					if((nodes.size()-1)%2 != 0)
					{
						ribs.push_back(new Line(nodes[nodes.size()-1].n(),nodes[(nodes.size()-1)/2].s()));
					} else ribs.push_back(new Line(nodes[nodes.size()-1].n(),nodes[((nodes.size()-1)/2)-1].s()));
					ribs[ribs.size()-1].draw();
				}
			}
			x+=w;
		}
		y+=interval;
		y-=y/10; // -10% intervals per level
		w/=2;
		r-=(r*2)/10; // -20% radius per level
	}
}
//------------------------------------------------------------------------------

void Gistogram::add_col(double v, string l)
{
	cols_value.push_back(v);
	cols_label.push_back(l);
	col_w = (xlength/cols_value.size())/3;
	offset = col_w;
	Fl::redraw();
}
//------------------------------------------------------------------------------

void Gistogram::draw_lines() const
{
	Axis x(Axis::x,xy,xlength,0,x_label);
	x.set_color(Color::black);
	x.label.move(xlength-offset,-20);
	x.draw();

	Axis y(Axis::y,xy,ylength,0,y_label);
	y.set_color(Color::black);
	y.draw();

	Text t_label(xy+Point{xlength/2,-ylength-20},label);
	t_label.set_color(color_labels);
	t_label.draw();

	Vector_ref<Rectangle> cols_temp;
	Vector_ref<Text> cols_label_temp;
	Vector_ref<Text> cols_value_temp;
	for(int i = 0; i < cols_value.size(); ++i)
	{
		//
		Point next_point{xy+Point{(col_w*i)+(offset*(i+1)),int(-cols_value[i])}};
		cols_temp.push_back(new Rectangle{next_point,col_w,int(cols_value[i])});
		cols_temp[cols_temp.size()-1].set_color(Color::black);
		cols_temp[cols_temp.size()-1].set_fill_color(color_columns);
		cols_temp[cols_temp.size()-1].draw();

		cols_label_temp.push_back(new Text(next_point+Point{0,int(cols_value[i]+20)},cols_label[i]));
		cols_label_temp[cols_label_temp.size()-1].set_color(color_labels);
		cols_label_temp[cols_label_temp.size()-1].draw();

		ostringstream ss;
		ss << cols_value[i];
		cols_value_temp.push_back(new Text(next_point+Point{0,-20},ss.str()));
		cols_value_temp[cols_value_temp.size()-1].set_color(color_values);
		cols_value_temp[cols_value_temp.size()-1].draw();
	}
}

//------------------------------------------------------------------------------
} // of namespace Graph_lib
