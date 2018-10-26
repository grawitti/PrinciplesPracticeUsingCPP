
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef Lines_window_GUARD
#define Lines_window_GUARD 1

#include "GUI.h"    // for Lines_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title );
private:
    Open_polyline lines;

    Button next_button;     // the "next" button
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button menu_button;

    void change(Color c) { lines.set_color(c); }

    void hide_menu() { color_menu.hide(), menu_button.show(); }

    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); }
    void black_pressed() { change(Color::black); hide_menu(); }
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void next();            // action to be done when next_button is pressed
    void quit();

    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
};
//------------------------------------------------------------------------------
#endif // Lines_window_GUARD
