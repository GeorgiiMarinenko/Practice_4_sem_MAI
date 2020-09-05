//
//  Ex27.cpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 17/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#include "Ex27.hpp"
#include <iostream>
#include "math.h"
using namespace std;

Ex27::Ex27()
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 53; j++)
        {
            Graf[i][j] = ' ';
        }
    }
}

double Ex27::Function1(double X)
{
    double Y;
    Y = sin(3*X);
    return Y;
}

double Ex27::Function2(double X)
{
    double Y;
    Y = 0.5;
    return Y;
}

double Ex27::Function3(double X)
{
    double Y;
    Y = sin(2*X);
    return Y;
}

void Ex27::SetGraphAxis()
{
    cout << "График:" << endl;
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 53; j++)
        {
            Graf[i][j] = ' ';
        }
    }
    for(int i = 0; i < 50; i++) //Отрисовка горизонтальной оси
    {
        Graf[14][i] = '-';
    }
    Graf[14][51] = '>';
    Graf[14][52] = 'x';
    
    for(int i = 0; i < 53; i++) //Отрисовка вертикальной оси
    {
        Graf[i][19] = '|';
    }
    Graf[0][19] = 'y';
    Graf[1][19] = '^';
}

void Ex27::CreateFunction(double a,double b)
{
    double x = a;
    double y1;
    int Counter = 1;
    double NumbOfDevision = 30;
    double Legth_AB;
    double ScaleX;
    int PointX = 1;
    int PointY = 0;


    Legth_AB = b - a;
    ScaleX = Legth_AB/NumbOfDevision;//Подсчет цены деления оси Х, это же -  шаг движения по оси
    
    while (x <= b)
    {
//        cout << "\nPointX = " << PointX;
        while (Counter < 4)
        {
            if(Counter == 1){
                y1 = Function1(x);//Вычисление координаты точки
                PointY = y1*10;
                if((PointX >= 0) && (PointY >= 0))
                {
                    Graf[14-PointY][19+PointX] = '.';
                }
                else if((PointX >= 0) && (PointY <= 0))
                {
                    Graf[14-PointY][19+PointX] = '.';
                }
//                cout << "\tPointY1 = " << PointY;
            }
            if(Counter == 2){
                y1 = Function2(x);
                PointY = y1*10;
                if((PointX >= 0) && (PointY >= 0))
                {
                    Graf[14-PointY][19+PointX] = '-';
                }
                else if((PointX >= 0) && (PointY <= 0))
                {
                    Graf[14-PointY][19+PointX] = '-';
                }
//                cout << "\tPointY2 = " << PointY;
            }
            if(Counter == 3){
                y1 = Function3(x);
                PointY = y1*10;
                if((PointX >= 0) && (PointY >= 0))
                {
                    Graf[14-PointY][19+PointX] = '*';
                }
                else if((PointX >= 0) && (PointY <= 0))
                {
                    Graf[14-PointY][19+PointX] = '*';
                }
//                cout << "\tPointY3 = " << PointY;
            }
            Counter++;
        }
        PointX++;
        x += ScaleX;
        Counter = 1;
    }
    cout  << "Центр оси координат = А("<< a << ";0)" << endl;
    cout << "Масштаб: \n  ц.д. оси Х: " << ScaleX << "\n  ц.д. оси У: 0.1" <<  endl;
}

void Ex27::PrintGraf()
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 53; j++)
        {
            cout << Graf[i][j];
        }
        cout << endl;
    }
}

double Ex27::RectangleMethod(double a, double b, double n,unsigned int FuncChoice)
{
    double Integral = 0.0;//Результат
    double h = (b-a)/n;//Шаг движения по отрезку
//    cout << "Шаг разбиения = " << h  << endl;
    double x = a;
    double y = 0.0;
    
        while (x <= b)
        {
                x += h;
            if (FuncChoice == 1){
                y = Function1(x);
            }
            else if(FuncChoice == 2){
                y = Function2(x);
            }
            else if (FuncChoice == 3){
                y = Function3(x);
            }
            y *= h;
            Integral += y;
//            cout << Integral << endl;
        }
    return Integral;
}


int Ex27::Start()
{
    int Step = 200;
    double Eps = 0.0001;
    
    double a;
    double b;
    double n;
    double FirstIntegral;
    double SecondIntegral;
    
    unsigned int Choice = 0;
    unsigned int FuncChoice = 0;
    
    while (Choice < 5)
    {
        cout << "Выберите необходимую функцию для подсчета интеграла:" << endl;
        cout << "1. Y = sin(3*X)" << endl;
        cout << "2. Y = 2X" <<  endl;
        cout << "3. Y = X^2" << endl;
        cout << "4. Вывести графики всех функциий на экран" << endl;
        cout << "*Для выхода нажмите клавишу > 4*" << endl;
        cout << "Введите действие: ";
        cin >> Choice;
        FuncChoice = Choice;
        switch (Choice)
        {
            case 1:
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "n = ";
                cin >> n;
                FirstIntegral = RectangleMethod(a, b, n, FuncChoice);
                n += Step;
                SecondIntegral = RectangleMethod(a, b, n, FuncChoice);
                while (fabs(FirstIntegral - SecondIntegral)> Eps)
                {
                    n += Step;
                    FirstIntegral = SecondIntegral;
                    SecondIntegral = RectangleMethod(a, b, n, FuncChoice);
                }
                cout << "\nФункция: Y = sin(3*X)" << endl;
                cout << "Результат интегрирования = " << SecondIntegral << endl << endl;
                break;
            
            case 2:
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "n = ";
                cin >> n;
                FirstIntegral = RectangleMethod(a, b, n, FuncChoice);
                n += Step;
                SecondIntegral = RectangleMethod(a, b, n, FuncChoice);
                while (fabs(FirstIntegral - SecondIntegral)> Eps)
                {
                    n += Step;
                    FirstIntegral = SecondIntegral;
                    SecondIntegral = RectangleMethod(a, b, n, FuncChoice);
                }
                cout << "\nФункция: Y = 0.5" << endl;
                cout << "Результат интегрирования = " << FirstIntegral << endl << endl;
                break;
            case 3:
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "n = ";
                cin >> n;
                FirstIntegral = RectangleMethod(a, b, n, FuncChoice);
                n += Step;
                SecondIntegral = RectangleMethod(a, b, n, FuncChoice);
                while (fabs(FirstIntegral - SecondIntegral)> Eps)
                {
                    n += Step;
                    FirstIntegral = SecondIntegral;
                    SecondIntegral = RectangleMethod(a, b, n, FuncChoice);
//                    cout << "1 = " << FirstIntegral << endl;
//                    cout << "2 = " << SecondIntegral << endl;
                }
                cout << "\nФункция: Y = sin(2*x)" << endl;
                cout << "Результат интегрирования = " << FirstIntegral << endl << endl;
                break;
            case 4:
                cout << "Укажите интервал, в котором необходимо вывести графики функций:" << endl;
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "n = ";
                SetGraphAxis();
                CreateFunction(a, b);
                PrintGraf();
                break;
            default:
                break;
        }
    }
    
    return 0;
}
