/*
     Date: 31.10.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 4-5
*/
#include"../../GUI/GUI.h"
#include"../../GUI/Draw_window.h"

int main()
{  
   try
   {
       Draw_window win{Point{100,100},600,400,"Draw_window"};
       return Graph_lib::gui_main();
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
