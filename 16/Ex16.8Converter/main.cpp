/*
     Date: 01.11.18
     Author: Grawitti
     Chapter 16 – Principles and Practice Using C++   
     Exerciese 8
*/
#include "../../GUI/GUI.h"
#include "../../GUI/Convert_window.h"

using namespace Graph_lib;

int main()
{
    try
    {
        // Scalling
        int xmax = 600;
        int ymax = 400;
        
        Convert_window c_win{Point{1500, 400}, xmax, ymax, "Converter"};

        return (Fl::run());
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
