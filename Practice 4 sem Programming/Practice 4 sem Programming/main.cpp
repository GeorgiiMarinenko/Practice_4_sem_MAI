//
//  main.cpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 13/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#include <iostream>
#include "Ex8.hpp"
#include "Ex27.hpp"
#include "Ex36.hpp"


int main()
{
    unsigned int Choice = 0;
    Ex8 Task8;
    Ex27 Task27;
    Ex36 Task36;
    while (Choice < 4)
    {
        cout << "Для запуска задания 1 - <<Подсчет частоты употребления букв в тексте>>, нажмите 1 "<< endl;
        cout << "Для запуска задания 2 - <<Разработка программы вычисления значений  интеграла от 3-х функций>>, нажмите 2" << endl;
        cout << "Для запуска задания 3 - <<Разработка программы вычисления значений функции>>, нажмите 3" << endl;
        cout << "Для запуска задания 4 - <<Разработка программы перевод римских чисел в арабские и обратно >>, нажмите 3" << endl;
        cout << "*Для выхода нажмите клавишу > 3*" << endl;
        cout << "Введите действие: ";
        cin >> Choice;
        switch (Choice)
        {
            case 1:
                Task8.Start();
                break;
            case 2:
                Task27.Start();
                break;
            case 3:
                Task36.Start();
            default:
                break;
        }
    }
    return 0;
}
