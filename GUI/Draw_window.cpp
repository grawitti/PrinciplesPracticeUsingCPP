#include "Draw_window.h"

Draw_window::Draw_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
        move_button{Point{x_max() - 150, 0}, 70, 20, "move", cb_move},
        quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", cb_quit},
        move_x{Point{x_max()-310,0},50,20,"x:"},
        move_y{Point{x_max()-210,0},50,20,"y:"},
        shape_menu{Point{x_max()-70,30}, 70, 20, Menu::vertical, "Shape"},
        shape_button{Point{x_max()-80,30}, 80, 20, "Shape",cb_shape_menu}
{  
    attach(move_button);
    attach(quit_button);
    attach(move_x);
    attach(move_y);

    shape_menu.attach(new Button{Point{0,0},0,0,"circle",cb_circle});
    shape_menu.attach(new Button{Point{0,0},0,0,"rectangle",cb_rectangle});
    shape_menu.attach(new Button{Point{0,0},0,0,"triangle",cb_triangle});
    shape_menu.attach(new Button{Point{0,0},0,0,"hexagon",cb_hexagon});
    attach(shape_menu);
    shape_menu.hide();
    attach(shape_button);
}

void Draw_window::quit()
{
    hide();
}

void Draw_window::move()
{
    int x = move_x.get_int();
    int y = move_y.get_int();
    shapes[shapes.size()-1].move(x,y);
    redraw();
}

//Other buttons callbacks
void Draw_window::cb_move(Address, Address pw) { reference_to<Draw_window>(pw).move(); }
void Draw_window::cb_quit(Address, Address pw) { reference_to<Draw_window>(pw).quit(); }

void Draw_window::cb_circle(Address, Address pw) { reference_to<Draw_window>(pw).circle_pressed(); }
void Draw_window::cb_rectangle(Address, Address pw) { reference_to<Draw_window>(pw).rectangle_pressed(); }
void Draw_window::cb_triangle(Address, Address pw) { reference_to<Draw_window>(pw).triangle_pressed(); }
void Draw_window::cb_hexagon(Address, Address pw) { reference_to<Draw_window>(pw).hexagon_pressed(); }
void Draw_window::cb_shape_menu(Address, Address pw) 
{
    reference_to<Draw_window>(pw).shape_menu_pressed();
}