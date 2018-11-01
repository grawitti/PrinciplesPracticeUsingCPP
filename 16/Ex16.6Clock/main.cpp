/*
     Date: 31.10.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 6
*/
#include"../../GUI/GUI.h"
#include"../../GUI/Window.h"

// void callback(void*)
// {
//     Fl::redraw();
//     Fl::repeat_timeout(10.0, callback);
// }

using namespace Graph_lib;

int main()
{  
   try
   {
       int xmax = 600;
       int ymax = 400;
       Window win{Point{1500,400},xmax,ymax,"Clock"};
       Clock cl{Point{xmax/2,ymax/2},100};
       win.attach(cl);
       for(int i = 0; Fl::check(); ++i)
       {
            // Fl::add_timeout(10.0, callback); // needed void callback(void*) function

            // usleep(1000000); // old metod, for UNIX: #include <unistd.h>, for Windows: #include <windows.h>

            struct timespec time_wait = {0,99999999}; // timespec{int seconds,int nanoseconds} - struct for the time format data.
            struct timespec time_write;
            nanosleep(&time_wait,&time_write);
        
            cl.get_system_time();
            cl.update_lines();
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
