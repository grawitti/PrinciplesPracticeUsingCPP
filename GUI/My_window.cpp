#include "My_window.h"

My_window::My_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
      next_button{Point{x_max() - 150, 0}, 70, 20, "Next", cb_next},
      quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", cb_quit}
{
    create_buttons();
    
    for(int i = 0; i < buttons.size(); ++i)
    {
        attach(buttons[i]);
    }
    
    attach(smile);
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
void My_window::create_buttons()
{
    int xoffset = 100;
    int yoffset = 100;
    int b_size = 40;
    int i_label = 0;
    Point first {xoffset, yoffset};
    // Create 4x4 buttons set
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            buttons.push_back(new Button{first+Point{b_size*j,b_size*i},
                                        b_size,b_size,to_string(i_label),cb_button});
            ++i_label;
        } 
    }
}

//Other buttons callbacks
void My_window::cb_next(Address, Address pw) { reference_to<My_window>(pw).next(); }
void My_window::cb_quit(Address, Address pw) { reference_to<My_window>(pw).quit(); }
void My_window::cb_button(Address, Address pw) {reference_to<My_window>(pw).button_pressed();}