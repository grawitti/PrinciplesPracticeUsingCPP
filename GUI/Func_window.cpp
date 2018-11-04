#include "Func_window.h"

Func_window::Func_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
      next_button{Point{250, 10}, 70, 20, "Build", cb_next},
      x_start_box{Point{70, 10}, 60, 20, "x start:"},
      x_end_box{Point{180, 10}, 60, 20, "x end:"},
      output_box{Point{400, 10}, 60, 20, "current x:"},
      ax{Axis::x, Point{xoffset, ymax - yoffset}, xlength, 20, "x"},
      ay{Axis::y, Point{xoffset, ymax - yoffset}, ylength, 12, "y"},
      function_menu{Point{x_max() - 80, 10}, 70, 20, Menu::vertical, "Functions"},
      function_button{Point{x_max() - 80, 10}, 80, 20, "Functions", cb_menu}
{
    attach(next_button);
    attach(x_start_box);
    attach(x_end_box);
    attach(output_box);

    ax.set_color(Color::black);
    ay.set_color(Color::black);
    attach(ax);
    attach(ay);

    function_menu.attach(new Button{Point{0, 0}, 0, 0, "sin", cb_sin});
    function_menu.attach(new Button{Point{0, 0}, 0, 0, "log", cb_log});
    attach(function_menu);
    function_menu.hide();
    attach(function_button);
}

void Func_window::next()
{
    vf[vf.size() - 1].set_color(Color::red);
    if (vf.size() > 1) detach(vf[vf.size() - 2]);
    attach(vf[vf.size() - 1]);
    redraw();
}

void Func_window::log_pressed()
{
    hide_menu();
    r_min = x_start_box.get_int();
    r_max = x_end_box.get_int();
    ostringstream ss;
    ss << r_min << '-' << r_max;
    output_box.put(ss.str());
    vf.push_back(new Function(log, r_min, r_max, Point{xoffset, ymax/2}, 200, x_scale, y_scale));
    
}
void Func_window::sin_pressed()
{
    hide_menu();
    r_min = x_start_box.get_int();
    r_max = x_end_box.get_int();
    ostringstream ss;
    ss << r_min << '-' << r_max;
    output_box.put(ss.str());
    vf.push_back(new Function(sin, r_min, r_max, Point{xoffset, ymax/2}, 200, x_scale, y_scale));
}

//Other buttons callbacks
void Func_window::cb_next(Address, Address pw) { reference_to<Func_window>(pw).next(); }
void Func_window::cb_menu(Address, Address pw) { reference_to<Func_window>(pw).menu_pressed(); }
void Func_window::cb_sin(Address, Address pw) { reference_to<Func_window>(pw).sin_pressed(); }
void Func_window::cb_log(Address, Address pw) { reference_to<Func_window>(pw).log_pressed(); }