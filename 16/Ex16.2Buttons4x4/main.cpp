/*
     Date: 31.10.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 2
*/
#include"../../GUI/GUI.h"
#include"../../GUI/My_window.h"

int main()
{  
   try
   {
       My_window win{Point{100,100},600,400,"Buttons 4x4"};
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
