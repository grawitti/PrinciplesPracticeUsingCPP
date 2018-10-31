
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef Draw_window_GUARD
#define Draw_window_GUARD 1

#include "GUI.h"    // for Draw_window only (doesn't really belong in Window.h)
#include "Graph.h"
//#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Draw_window : Graph_lib::Window {
    Draw_window(Point xy, int w, int h, const string& title);
private:
    Button move_button;     // the "next" button
    Button quit_button;
    In_box move_x;
    In_box move_y;
    Menu shape_menu;
    Button shape_button;
    int size = 50;
    Vector_ref<Shape> shapes;
    
    //Other buttons
    void move();            // action to be done when next_button is pressed
    void quit();

    static void cb_move(Address, Address);
    static void cb_quit(Address, Address);

    void hide_shape_menu() { shape_menu.hide(), shape_button.show(); }
    void shape_menu_pressed() { shape_button.hide(); shape_menu.show(); }
    void circle_pressed() 
    { 
        shapes.push_back(new Circle{Point{size,size},size});
        if (shapes.size()>1) detach(shapes[shapes.size()-2]);
        attach(shapes[shapes.size()-1]);
        hide_shape_menu(); 
    }
    void rectangle_pressed() 
    { 
        shapes.push_back(new Rectangle{Point{size,size},size,size});
        if (shapes.size()>1) detach(shapes[shapes.size()-2]);
        attach(shapes[shapes.size()-1]);
        hide_shape_menu(); 
    }
    void triangle_pressed() 
    { 
        shapes.push_back(new Right_triangle{Point{size,size},size,size});
        if (shapes.size()>1) detach(shapes[shapes.size()-2]);
        attach(shapes[shapes.size()-1]);
        hide_shape_menu(); 
    }
    void hexagon_pressed() 
    { 
        shapes.push_back(new Regular_hexagon{Point{size,size},size});
        if (shapes.size()>1) detach(shapes[shapes.size()-2]);
        attach(shapes[shapes.size()-1]);
        hide_shape_menu(); 
    }

    static void cb_shape_menu(Address, Address);
    static void cb_circle(Address, Address);
    static void cb_rectangle(Address, Address);
    static void cb_triangle(Address, Address);
    static void cb_hexagon(Address, Address);
};
//------------------------------------------------------------------------------
#endif // Draw_window_GUARD
