/*
     Date: 01.11.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 7
*/
#include"../../GUI/GUI.h"
#include"../../GUI/Window.h"

using namespace Graph_lib;

bool fly = false;

void cb_start(Address, Address pw) { fly = true; }

void cb_stop(Address, Address pw) { fly = false; }

int main()
{  
   try
   {
       int xmax = 600;
       int ymax = 400;
       Window win{Point{1500,400},xmax,ymax,"Airplane"};
       Button start_button{Point{20,20},70,20,"start",cb_start};
       win.attach(start_button);
       Button stop_button{Point{100,20},70,20,"stop",cb_stop};
       win.attach(stop_button);

       Image airplane{Point{0,100},"airplane.jpg"};
       win.attach(airplane);
       
       for(int i = 0; Fl::check(); ++i)
       {
            struct timespec time_wait = {0,99999999}; // timespec{int seconds,int nanoseconds} - struct for the time format data.
            struct timespec time_write;
            nanosleep(&time_wait,&time_write);
            if (fly) airplane.move(3,0);
            Fl::redraw();

       }
       return (Fl::run());
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
       return 1;
   }
    catch(...)
   {
       std::cerr << "Unknown exception!" << '\n';
       return 2;
   }
}
