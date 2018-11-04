
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef Func_WINDOW_GUARD
#define Func_WINDOW_GUARD 1

#include "GUI.h" // for Func_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Func_window : Graph_lib::Window
{
    Func_window(Point xy, int w, int h, const string &title);

  private:
    Button next_button; // the "next" button
    In_box x_start_box;
    In_box x_end_box;
    Out_box output_box;
    Axis ax;
    Axis ay;
    Menu function_menu;
    Button function_button;
    Vector_ref<Function> vf;

    // Scalling
    inline static int xmax{600};
    inline static int ymax = 400;
    inline static int xoffset = 30;
    inline static int yoffset = 30;
    inline static int xspace = 30;
    inline static int yspace = 60;
    inline static int xlength = xmax - xoffset - xspace;
    inline static int ylength = ymax - yoffset - yspace;
    int r_min = 0;
    int r_max = 15;
    inline static int x_scale = 30;
    inline static int y_scale = 30;

    //
    void next();
    void hide_menu() { function_menu.hide(), function_button.show(); }
    void sin_pressed();
    void log_pressed();
    void menu_pressed() { function_button.hide(); function_menu.show(); }

    static void cb_next(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_sin(Address, Address);
    static void cb_log(Address, Address);
};
//------------------------------------------------------------------------------
#endif // Func_WINDOW_GUARD
