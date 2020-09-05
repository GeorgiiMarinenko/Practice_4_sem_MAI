//
//  main.cpp
//  Ex 27 Integral
//
//  Created by Georgy Marinenko on 14/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include "math.h"
using namespace std;
char Graf[25][53];
double Function(double X)
{
    double Y;
    Y = sin(3*X)*sin(4*X)*sin(5*X);
    return Y;
}

void SetGraphAxis()
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

void CreateFunction(double a,double b)
{
    double x = a;
    double y;
    double NumbOfDevision = 30;
    double Legth_AB;
    double ScaleX;
    int PointX = 0;
    int PointY;

    Legth_AB = b - a;
    ScaleX = Legth_AB/NumbOfDevision;//Подсчет цены деления оси Х, это же -  шаг движения по оси
    
    while (x <= b)
    {
        y = Function(x);//Вычисление координаты точки
        PointX++;
        PointY = y*10;
//        cout << "PointX = " << PointX << "\tPointY = " << PointY << endl;
        if((PointX >= 0) && (PointY >= 0))
        {
            for(int i = 14; i >= 14-PointY; i--)
            {
                
                Graf[i][19+PointX] = '.';
            }
        }
        else if((PointX >= 0) && (PointY <= 0))
        {
            for(int i = 14; i <= 14+fabs(PointY); i++)
            {
                
                Graf[i][19+PointX] = '.';
            }
        }
        x += ScaleX;
    }
    cout  << "Центр оси координат = А("<< a << ";0)" << endl;
    cout << "Масштаб: \n  ц.д. оси Х: " << ScaleX << "\n  ц.д. оси У: 0.1" <<  endl;
}

void PrintGraf()
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

double RectangleMethod(double a, double b, double n)
{
    double Integral = 0.0;//Результат
    double h = (b-a)/n;//Шаг движения по отрезку
    cout << "Шаг разбиения = " << h  << endl;
    double x = a;
    double y;
    bool FirstEnter = true;
    while (x <= b)
    {
        x += h;
        y = Function(x);
        y *= h;
//        cout << y << " ";
        Integral += y;
    }
    return Integral;
}

int main()
{
    double a;
    double b;
    double n;
    double Integral;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "n = ";
    cin >> n;
    Integral = RectangleMethod(a, b, n);
    Integral = (long int)(Integral*10000) * 10000;
    cout << "Результат интегрирования = " << Integral << endl << endl;
    
    SetGraphAxis();
    CreateFunction(a, b);
    PrintGraf();
    return 0;
}
