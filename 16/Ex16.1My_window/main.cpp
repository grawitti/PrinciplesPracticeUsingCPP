/*
     Date: 31.10.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 1
*/
#include"../../GUI/GUI.h"
#include"../../GUI/My_window.h"

int main()
{  
   try
   {
       My_window win{Point{100,100},600,400,"My_window"};
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
