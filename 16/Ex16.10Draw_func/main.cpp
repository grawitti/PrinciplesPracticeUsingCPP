/*
     Date: 04.11.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 10
*/
#include "../../GUI/GUI.h"
#include "../../GUI/Func_window.h"

int main()
{
    try
    {
        // Scaling
        Point open_window{x_max() / 2, 200};
        int x_width = 600;
        int y_height = 400;

        Func_window win{open_window, x_width, y_height, "Func_window"};
        
        return Graph_lib::gui_main();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception!" << '\n';
        return 2;
    }
}
