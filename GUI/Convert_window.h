
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef Convert_window_GUARD
#define Convert_window_GUARD 1

#include "GUI.h"    // for Convert_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
// Struct for save currency rates 
struct Currency {
public:
    string base;
    string target;
    double rate;
};

//------------------------------------------------------------------------------

struct Convert_window : Graph_lib::Window {
    Convert_window(Point xy, int w, int h, const string& title );
private:
    Vector_ref<Text> rate_text;
    In_box in_box_amount;
    Out_box out_box_result;
    Button convert_button;
    Menu convert_menu;
    Button convert_menu_button;
    double base{0};
    Text label_target;
    Text label_base;

    ifstream ifs;
    vector<Currency> vc_rate;

    void hide_menu() { convert_menu.hide(), convert_menu_button.show(); }
    void convert_menu_pressed() { convert_menu_button.hide(); convert_menu.show(); }
    void rub_pressed();
    void eur_pressed();
    void gbp_pressed();
    void cny_pressed();

    ifstream& open_file(ifstream &ifs, string file_name);
    void read_file(ifstream& ifs, vector<Currency>& vc);
    void convert();

    static void cb_convert(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_rub(Address, Address);
    static void cb_eur(Address, Address);
    static void cb_gbp(Address, Address);
    static void cb_cny(Address, Address);
};
//------------------------------------------------------------------------------
#endif // Convert_window_GUARD

