//  HEADERS

#include <FL/Fl.H>

#include <FL/Fl_Window.H>

#include <FL/Fl_Menu_Bar.H>

#include <FL/Fl_File_Chooser.H>

//      GLOBALS

Fl_Menu_Bar             *m;

Fl_File_Chooser         *fc;

#define          FONT_SIZE    14

void fc_callback(Fl_File_Chooser *fc, void *data)

{

        if(fc->value())

        {                                                                                               

                 printf( "Chosen file: \"%s\"\n", fc->value() );

        }

    return;                                                                                        

}

void open_cb(Fl_Widget*, void*)                                                                     

{

    fc->callback(fc_callback);

    fc->show();                                                                                                                                 

    while(fc->shown())

           Fl::wait();

        if( fc->count() == 1 )                                                                         

    {

        printf("File was selected\n");

    }

}

void quit_cb(Fl_Widget*, void*)

{

   exit(0);

}

Fl_Menu_Item MenuEng[] = {

   { "&File",                   0, 0, 0, FL_SUBMENU },

     { "&Open",                FL_CTRL + 'o', (Fl_Callback *)open_cb },

     { "&Save",                FL_CTRL + 's', 0 },

     { "E&xit",         FL_CTRL + 'q', (Fl_Callback *)quit_cb, 0 },

     { 0 },

   { "&Help", 0, 0, 0, FL_SUBMENU },

      { "&About",           FL_CTRL + 'a' , 0 },

      { 0 },

   { 0 }

};

int main(int argc, char **argv) {

    Fl_Window *window = new Fl_Window(300, 300, "Sample");

    window->color(FL_WHITE);

    m = new Fl_Menu_Bar(0, 0, 640, 25);

    m->copy(MenuEng);

    m->box(FL_UP_BOX);

    m->textcolor(FL_BLUE);

    m->textfont(FL_TIMES);

    m->textsize(FONT_SIZE);

    fc = new Fl_File_Chooser(".", "*.{txt,cpp}", Fl_File_Chooser::SINGLE, "File_Chooser_Dialog");

    window->show();

    window->callback( (Fl_Callback *)quit_cb, window );

    return Fl::run();

}