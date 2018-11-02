#include "Convert_window.h"

Convert_window::Convert_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
    in_box_amount{Point{20,20},70,20,""},
    out_box_result{Point{105,20},70,20,"="},
    convert_button{Point{70, 50}, 70, 20, "convert", cb_convert},
    convert_menu{Point{200,20}, 120, 20, Menu::vertical, "Choice converter"},
    convert_menu_button{Point{200,20}, 120, 20, "Choice converter",cb_menu},
    label_base{Point{125,18},"USD"},
    label_target{Point{40,18},"RUB"}
{
    // Open and reading file currencies rate
    read_file(open_file(ifs, "currency_rate.txt"),vc_rate);

    // Draw currencies
    for(int i = 0; i<vc_rate.size(); ++i)
    {
        ostringstream ss;
        ss << vc_rate[i].base << '/' << vc_rate[i].target << ':' << vc_rate[i].rate;
        rate_text.push_back(new Text{Point{w-100,i*20+20},ss.str()});
        rate_text[rate_text.size()-1].set_color(Color::black);
        attach(rate_text[rate_text.size()-1]);
    }

    // attach elements
    attach(in_box_amount);
    attach(out_box_result);
    attach(convert_button);

    convert_menu.attach(new Button{Point{0,0},0,0,"USD>RUB",cb_rub});
    convert_menu.attach(new Button{Point{0,0},0,0,"USD>EUR",cb_eur});
    convert_menu.attach(new Button{Point{0,0},0,0,"USD>GBP",cb_gbp});
    convert_menu.attach(new Button{Point{0,0},0,0,"USD>CNY",cb_cny});
    attach(convert_menu);
    convert_menu.hide();
    attach(convert_menu_button);

    label_base.set_color(Color::red);
    label_target.set_color(Color::blue);
    attach(label_base);
    attach(label_target);

    // Set default converter on startup
    base = vc_rate[0].rate; // USD>RUB
}

// Open file
ifstream& Convert_window::open_file(ifstream &ifs, string file_name)
{
    ifs.open(file_name);
    if (!ifs.is_open())
        error("Cannot open file ", file_name);
    return ifs;
}

// Reading currency rates from the file
void Convert_window::read_file(ifstream& ifs, vector<Currency>& vc)
{
    while(ifs)
    {
        char ch, ch2;
        string base ,target;
        ifs >> ch;
        if (ch != '(') error("Unknown file data format:");
        for(int i = 0; i<3; ++i)
        {
            char c;
            ifs >> c;
            base+=c;
        }
        if(base != "USD") error("Base cyrency must be USD:",base);
        ifs >> ch;
        if (ch != '/') error("Unknown file data format:");
        for(int i = 0; i<3; ++i)
        {
            char c;
            ifs >> c;
            target+=c;
        }
        ifs >> ch;
        if (ch != ':') error("Unknown file data format:");
        double rate;
        ifs >> rate;
        if(ifs.fail())
        {
            ifs.clear();
            char c;
            ifs >> c;
            if (isspace(c) || c == '\000') break;
            else error("Unknown file data format");
        }
        ifs >> ch >> ch2;
        if (ch != ')' || ch2 != ',') error("Unknown file data format:");
        vc.push_back({base,target,rate});
        cout << base << '/' << target << ':' << rate << " ...reading OK.\n";
    }
}

void Convert_window::rub_pressed()
{ 
    for(int i = 0; i<vc_rate.size(); ++i)
    {
        if(vc_rate[i].target == "RUB") 
        {
            base = vc_rate[i].rate;
            label_target.set_label(vc_rate[i].target);
            break;
        }
    }
    if(label_target.label() != "RUB")  error("Cannot find RUB in vc_rate");
    hide_menu();
    redraw();
}

void Convert_window::eur_pressed()
{ 
    for(int i = 0; i<vc_rate.size(); ++i)
    {
        if(vc_rate[i].target == "EUR") 
        {
            base = vc_rate[i].rate;
            label_target.set_label(vc_rate[i].target);
            break;
        }
    }
    if(label_target.label() != "EUR") error("Cannot find EUR in vc_rate");
    hide_menu();
    redraw();
}

void Convert_window::gbp_pressed()
{ 
    for(int i = 0; i<vc_rate.size(); ++i)
    {
        if(vc_rate[i].target == "GBP") 
        {
            base = vc_rate[i].rate;
            label_target.set_label(vc_rate[i].target);
            break;
        }
    }
    if(label_target.label() != "GBP") error("Cannot find GBP in vc_rate");
    hide_menu();
    redraw();
}

void Convert_window::cny_pressed()
{ 
    for(int i = 0; i<vc_rate.size(); ++i)
    {
        if(vc_rate[i].target == "CHY") 
        {
            base = vc_rate[i].rate;
            label_target.set_label(vc_rate[i].target);
            break;
        }
    }
    if(label_target.label() != "CHY") error("Cannot find CNY in vc_rate");
    hide_menu();
    redraw();
}

// Converter currencies
void Convert_window::convert()
{
    double amount = in_box_amount.get_double();
    ostringstream ss;
    double result = 0.0;
    if(amount == -999999) result = 0;
    else result = amount / base;
    ss << result;
    out_box_result.put(ss.str());
}

// callbacks
void Convert_window::cb_rub(Address, Address pw) { reference_to<Convert_window>(pw).rub_pressed(); }
void Convert_window::cb_eur(Address, Address pw) { reference_to<Convert_window>(pw).eur_pressed(); }
void Convert_window::cb_gbp(Address, Address pw) { reference_to<Convert_window>(pw).gbp_pressed(); }
void Convert_window::cb_cny(Address, Address pw) { reference_to<Convert_window>(pw).cny_pressed(); }
void Convert_window::cb_convert(Address, Address pw) { reference_to<Convert_window>(pw).convert(); }
void Convert_window::cb_menu(Address, Address pw) {reference_to<Convert_window>(pw).convert_menu_pressed();}