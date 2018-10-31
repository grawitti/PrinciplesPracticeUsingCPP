#include "My_window.h"

My_window::My_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
      next_button{Point{x_max() - 150, 0}, 70, 20, "Next", cb_next},
      quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", cb_quit}
{
    attach(next_button);
    attach(quit_button);
}

void My_window::quit()
{
    hide();
}

void My_window::next()
{
    redraw();
}

//Other buttons callbacks
void My_window::cb_next(Address, Address pw) { reference_to<My_window>(pw).next(); }
void My_window::cb_quit(Address, Address pw) { reference_to<My_window>(pw).quit(); }