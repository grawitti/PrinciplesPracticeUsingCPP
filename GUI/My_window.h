
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef MY_WINDOW_GUARD
#define MY_WINDOW_GUARD 1

#include "GUI.h"    // for My_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct My_window : Graph_lib::Window {
    My_window(Point xy, int w, int h, const string& title );
private:

    Vector_ref<Button> buttons;
    Button next_button;     // the "next" button
    Button quit_button;
    Point smile_loc{100,100};
    Image smile{smile_loc,"smile.jpg"};
    

    //Other buttons
    void next();            // action to be done when next_button is pressed
    void quit();
    void create_buttons();
    void button_pressed()
    {
        int ymin = 0-smile_loc.y;
        int ymax = y_max()-smile_loc.y;
        int xmin = 0-smile_loc.x;
        int xmax = x_max()-smile_loc.x;
        int x = rand_int(xmin,xmax-40);
        int y = rand_int(ymin,ymax-40);
        smile_loc = smile_loc+Point{x,y};
        smile.move(x,y);
        redraw();
    }

    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_button(Address, Address);
};
//------------------------------------------------------------------------------
#endif // MY_WINDOW_GUARD
