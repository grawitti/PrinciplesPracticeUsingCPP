//
//  main.cpp
//  Ex15.2Fct
//
//  Created by Руслан Сахибгареев on 19/10/2018.
//  Copyright © 2018 Руслан Сахибгареев. All rights reserved.
//

#include "../../../std_lib_facilities.h"

using namespace std;

int main()
{
    try
    {
        cout << "Введите число для вычисления его факториала:\n";
        
        Function_arg(cos, 0, 50, x_max()/2, y_max()/2,);
        
        keep_window_open();
    }
    catch (exception& e)
    {
        cerr << "\nОшибка: " << e.what() << endl;
        return 1;
        keep_window_open();
    }
    catch (...)
    {
        cerr << "\nНеизвестное исключение!\n";
        return 2;
        keep_window_open();
    }
    return 0;
}
