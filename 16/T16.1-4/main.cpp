/*
     Date: 26.10.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Task 1-4
*/
#include"../../GUI/GUI.h"
#include"../../GUI/Lines_window.h"

int main()
{  
   try
   {
       Lines_window win{Point{100,100},600,400,"lines"};
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
