/**
 Дата создания: 24.05.18
 Автор: Руслан
 Назначение: Суперэлипс
 Глава 12, упр. 12, стр. 492, Б. Страуструп "Программирование принципы и практика с использованием С++" (2 изд. 2016 г.)
 Пример:
**/

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include <stdexcept>
#include <iostream>
//using namespace Graph_lib;

#define PI 3.14159265359

template <typename T> 
int sgn(T val);

vector<Point> generateSuperEllipse(double CoeffA, double CoeffB, double expN, double expM, int centX, int centY, double precision);
/*
    Class: SuperEllipse
    Each initialized object
    generates a superellipse
    using the parameters of the
    constructor. The two member
    functions draw the generated
    points.
*/
class SuperEllipse{
    public:
    SuperEllipse(double CoeffA, double CoeffB, double expN, double expM, int centX, int centY, double precision){
        // generate ellipse points
        coordinates = generateSuperEllipse(CoeffA, CoeffB, expN, expM, centX, centY, precision);
    }
    // draw a Star-like pattern connecting superellipse's single point to the rest of its equally spaced points 
    void drawStar();
    // draw a superellipse out of the generated points contained in private member coordinates
    void drawSuperEllipse();
private: 
    vector<Point> coordinates;
};

//------------------------------------------------------------------------------------------------------------------------------
int main(){
    try{
    // Superellipse parameters
    // exponents
    double n = 1/2.;
    double m = 1/2.;
    // coefficient 
    double A = 200.0;
    double B = 200.0;
    // center point of the graph
    const int centX = x_max() / 2.;
    const int centY = y_max() / 2.;
    // incrementation step
    double di = 0.01;

    SuperEllipse se(A, B, n, m, centX, centY, di);
    se.drawSuperEllipse();
    // push next button to see the star
    se.drawStar();

}catch(exception& e){
    cerr << e.what() <<endl;
    getchar();              
}catch(...){
    cerr <<"Default exception!"<<endl;
    getchar();              
}
return 0;
}
//------------------------------------------------------------------------------------------------------------------------------
/*
    Function: sgn()
    Use: int singedOneorZero = sgn(anyType);
    Returns either -1, 0 or 1 if the input
    value is < 0 , == 0 or > =, respectivelly.
*/
template <typename T> 
int sgn(T val){
    return (T(0) < val) - (val < T(0));
}

/*
    Function: generateSuperEllipse()
    Use: vector<Point> generateSuperEllipse(double coeffA, double coeffB, 
                                    double expN, double expM, 
                                    int centX, int centY, 
                                    double precision)
    This function generates a set of superellipse coordinates based
    on the following parametric equations:
    x(theta) = coeffA * pow(abs(cos(theta)), 2 / n) * sgn(cos(theta)) + centX;
    y(theta) = coeffB * pow(abs(sin(theta)), 2 / m) * sgn(sin(theta)) + centY;
    and returns a vector containing them.
*/
vector<Point> generateSuperEllipse(double coeffA, double coeffB, double expN, double expM, int centX, int centY, double precision = 0.01){
if(precision < 0.01 || precision > 1) error("Precision out of range!");

vector<Point> superEllipseCoordinates;
Point temp, sEllipseCoordinate;

for(double d = -1; d < 1; d += precision){
        double theta = d * PI; 
        int x = coeffA * pow(abs((double)cos(theta)), (double)2.0 / expM) * sgn(cos(theta));
        int y = coeffB * pow(abs((double)sin(theta)), (double)2.0 / expN) * sgn(sin(theta));
        sEllipseCoordinate = Point(x + centX/2. , y + centY);
        // check for duplicate points
        if(sEllipseCoordinate != temp) superEllipseCoordinates.push_back(sEllipseCoordinate);
        temp = sEllipseCoordinate;  
    }
return superEllipseCoordinates;
}


// Class Superellipse members implementation
/*
    Member Function: drawStar()
    Use: SuperEllipse sEobject.drawStar();
    Generates a Simple_window 
    object and draws a star-like pattern
    by connecting a single one of 
    the, already generated superellipse
    points to the equally spaced remaining point.
    Finally it attaches the drawing
    to the window object.
*/
void SuperEllipse::drawStar(){
    const int swWidth = 800;
    const int swHeight = 800;
    Simple_window sw(Point((x_max()- swWidth) / 2. , (y_max() - swHeight) / 2.), 
                 swWidth, swHeight, "Chapter 12 Exercise 12");
    // If the initial value of the counter: i is not divided by a number (100) it connects 
    // a lot of points and results in filling the superellipse 
    for(size_t i = coordinates.size() / 100; i < coordinates.size(); ++i){
        for(size_t j = i+1; j < coordinates.size(); ++j){
            Graph_lib::Line* star = new Line(Point(coordinates[0]),Point(coordinates[j]));
            sw.attach(*star);
        }
    }
    sw.wait_for_button();
}

/*
    Member Function: drawSuperEllipse();
    Use: SuperEllipse sEobject.drawSuperEllipse();
    Generates a Simple_windoq object
    and draws an open polyline of the 
    coordinates passed as parameter (in the case
    superellipse). Finally it attaches the drawing
    to the window object.
*/
void SuperEllipse::drawSuperEllipse(){
    const int swWidth = 800;
    const int swHeight = 800;
    Simple_window sw(Point((x_max()- swWidth) / 2. , (y_max() - swHeight) / 2.), 
                 swWidth, swHeight, "Chapter 12 Exercise 12");

    Graph_lib::Open_polyline superEllipse;
    for(size_t i = 0; i < coordinates.size(); ++i)  superEllipse.add(coordinates[i]); 
        sw.attach(superEllipse);
        sw.wait_for_button();
}
