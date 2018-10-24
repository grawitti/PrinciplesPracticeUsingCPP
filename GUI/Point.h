
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef POINT_GUARD
#include <iostream>
#define POINT_GUARD

//------------------------------------------------------------------------------

struct Point {
    int x, y;
    Point(int xx, int yy) : x(xx), y(yy) { }
    Point() :x(0), y(0) { }
};

//------------------------------------------------------------------------------

inline std::ostream& operator<<(std::ostream& os, Point p) { return os << p.x << ", " << p.y; }

//------------------------------------------------------------------------------

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }

//------------------------------------------------------------------------------

inline bool operator!=(Point a, Point b) { return !(a==b); }

//------------------------------------------------------------------------------

inline Point operator+(Point a, Point b) { return Point{a.x+b.x,a.y+b.y}; }

//------------------------------------------------------------------------------

inline Point operator-(Point a, Point b) { return Point{a.x-b.x,a.y-b.y}; }

//------------------------------------------------------------------------------

#endif // POINT_GUARD

