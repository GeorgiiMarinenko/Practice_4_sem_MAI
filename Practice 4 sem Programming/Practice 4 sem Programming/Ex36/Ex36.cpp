//
//  Ex36.cpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 13/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#include "Ex36.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "math.h"
using namespace std;

Ex36::Ex36()
{
    this->filename = "InputFileEx36.txt";
}

int Ex36::Fact(int x)
{
    int y = 1;
    int Step = 1;
    while(Step <= x)
    {
        y *= Step;
        Step++;
    }
    return y;
}

double Ex36::Exp(double X)
{
    double Exp = 1;
    double RealExp;
    int Factorial = 1;
    int Exponent = 1;
    double Accuracy = 0.0001; //Точность вычисления
    
    RealExp = exp(X); //Подсчет табличного значения экспоненты
    while(fabs(Exp - RealExp) > Accuracy)
    {
        Exp += pow(X,Exponent)/Fact(Factorial);
        Factorial++;
        Exponent++;
    }
    return Exp;
}
double Ex36::Function1(double X, double K)
{
    double Y;
    Y = K*Exp(X) - sin(X);
    return Y;
}
double Ex36::Function2(double X)
{
    double Y;
    Y = 1/X + X;
    return Y;
}
void Ex36::PrintHeader()
{
    wstring point = L"Point#", x = L"X", y = L"Y";
    cout << "________________________________________" << endl;
    cout << "| ";
    wcout << setw (1) << point;
    wcout << setw (8) << x;
    wcout << setw (17) << y;
    wcout << setw (7) << "|" << endl;
    cout << "----------------------------------------" << endl;
}
char** Ex36::SetGraphAxis(char** Graf)
{
    Graf = new char*[42];
    for(int i = 0; i < 42; i++)
    {
        Graf[i] = new char [44];
    }
    for(int i = 0; i < 42; i++)
    {
        for(int j = 0; j < 44; j++)
        {
            Graf[i][j] = ' ';
        }
    }
    for(int i = 0; i < 41; i++) //Отрисовка горизонтальной оси
    {
        Graf[15][i] = '-';
    }
    Graf[15][42] = '>';
    Graf[15][43] = 'x';
    
    for(int i = 0; i < 30; i++) //Отрисовка вертикальной оси
    {
        Graf[i][20] = '|';
    }
    Graf[0][20] = 'y';
    Graf[1][20] = '^';
    
    return Graf;
}
void Ex36::CreateGraph(float X, float Y, char** Graf)
{
    int PointX = 1;
    int PointY = 1;
    
    X *= 10;
//    X = ((int)X%10);
    Y *= 100;
    Y = ((int)Y%100);
//    cout << "x = " << X << "  ";
//    cout << "y= " << Y << endl;
    PointX *= X;
    PointY *= Y;
    
    if((X >= 0) && (Y >= 0))
    {
        Graf[15 - PointY][20 + PointX] = '~';
        PointX = 1;
        PointY = 1;
        
    }
    else if((X >= 0) && (Y <= 0))
    {
        Graf[15 - PointY][20 + PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
    else if((X <= 0) && (Y >= 0))
    {
        Graf[15 - PointY][20 - PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
    else if((X <= 0) && (Y <= 0))
    {
        Graf[15 + PointY][20 - PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
}

void Ex36::PrintGraph(char** Graf)
{
    cout << "\t\t\t\t\tЦентральная точка коорд. осей принимает значение = A(0;0)" << endl;
    cout << "\t\t\t\t\tМасштаб:" << endl;
    cout << "\t\t\t\t\t1 деление по оси Х = 0.1" << endl;
    cout << "\t\t\t\t\t1 деление по оси Y = 0.01" << endl;
    cout << endl;
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 44; j++)
        {
            cout << Graf[i][j];
        }
        cout << endl;
    }
}

void Ex36::RecordGraph1(char** Graf)
{
    ofstream fout("Graph_function1_Ex36.txt", ios::out);
    fout << "\t\t\t\t\tЦентральная точка коорд. осей принимает значение = A(0;0)" << endl;
    fout << "\t\t\t\t\tМасштаб:" << endl;
    fout << "\t\t\t\t\t1 деление по оси Х = 0.1" << endl;
    fout << "\t\t\t\t\t1 деление по оси Y = 0.01" << endl;
    fout << endl;
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 44; j++)
        {
            fout << Graf[i][j];
        }
        fout << endl;
    }
    cout << "График успешно записан в файл\n" <<  endl;
}
void Ex36::RecordGraph2(char** Graf)
{
    ofstream fout("Graph_function2_Ex36.txt", ios::out);
    fout << "\t\t\t\t\tЦентральная точка коорд. осей принимает значение = A(0;0)" << endl;
    fout << "\t\t\t\t\tМасштаб:" << endl;
    fout << "\t\t\t\t\t1 деление по оси Х = 0.1" << endl;
    fout << "\t\t\t\t\t1 деление по оси Y = 0.01" << endl;
    fout << endl;
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 44; j++)
        {
            fout << Graf[i][j];
        }
        fout << endl;
    }
    cout << "График успешно записан в файл\n" <<  endl;
}
int Ex36::Start()
{
    setlocale(LC_ALL, "");
    
    double A; //Левая граница отрезка
    double B; //Правая граница отрезка
    double Step; //Шаг движения по отрезку
    double P; //Ограничение отрезка
    double K; //Коэффицент для уравнения 1
    double Array[5];//Массив с данным, считанных из файла
    double X;//Аргумент
    double Y;
    int i;//Счетчик прохода по индексам масива с входными данными
    int j;//Счетчик кол-ва точек функции на отрезке
    unsigned int MainChoice = 0;
    unsigned int RecordGrafChoice1 = 0;
    unsigned int RecordGrafChoice2 = 0;
    
    ifstream fin;//Объявление файлового потока
    fin.open(filename);
    if(!fin.is_open())
    {
        cout << "Error of opening, please check data and try again" << endl;
        return -1;
    }
    else
    {
        i = 0;
        while(!fin.eof())
        {
            fin >> Array[i];
            i++;
        }
        A = Array[0];
        B = Array[1];
        Step = Array[2];
        P = Array[3];
        K = Array[4];
    }
    while(MainChoice < 3)
    {
        cout << "\n\n<Введите номер функции, которую необходимо подсчитать>" << endl;
        cout << "1. y = " << K << "e^x-sinx, x <= " << P << endl;
        cout << "2. y=1/x+x, x > " << P << endl;
        cout << "*ДЛЯ ВЫХОДА НАЖМИТЕ КЛАВИШУ > 2*" << endl;
        cout << "Ввод действия: ";
        cin >> MainChoice;
        switch (MainChoice)
        {
            case 1:
                Graf1 = SetGraphAxis(Graf1);
                X = A; //Приравнение аргумента Х левой границе отрезка
                j = 1;
                wcout << setw (10) << "Function: y=" << K << "e^x-sinx, x <= " << P << endl;
                PrintHeader();
                while(X <= P)
                {
                    Y = Function1(X,K);
                    CreateGraph(X, Y,Graf1);
                    cout << "|";
                    wcout << setw (5) << j;
                    wcout << setw (11) << X;
                    wcout << setw (20) << Y;
                    cout << "  |";
                    cout << endl;
                    j++;
                    X += Step;
                }
                cout << "---------------------------------------\n" << endl;
                cout << endl;
                while (RecordGrafChoice1 < 3)
                {
                    cout << "Выберите действие:" << endl;
                    cout << "1. Вывести график функции y = " << K << "e^x-sinx, x <= " << P << " в консоль" << endl;
                    cout << "2. Записать график функции y = " << K << "e^x-sinx, x <= " << P << " в файл" << endl;
                    cout << "*ДЛЯ ВЫХОДА НАЖМИТЕ КЛАВИШУ > 2*" << endl;
                    cout << "Ввод действия: ";
                    cin >> RecordGrafChoice1;
                    switch (RecordGrafChoice1)
                    {
                        case 1:
                            PrintGraph(Graf1);
                            break;
                        case 2:
                            RecordGraph1(Graf1);
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                Graf2 = SetGraphAxis(Graf2);
                j = 1;
                X = P+Step;
                wcout << setw (10) << "\nFunction: " << "y=1/x+x, x > " << P << endl;
                PrintHeader();
                while(X <= B)
                {
                    Y = Function2(X);
                    CreateGraph(X, Y, Graf2);
                    cout << "|";
                    wcout << setw (5) << j;
                    wcout << setw (11) << X;
                    wcout << setw (20) << Y;
                    cout << "  |";
                    cout << endl;
                    j++;
                    X += Step;
                }
                cout << "---------------------------------------" << endl;
                cout <<  endl;
                while (RecordGrafChoice2 < 3)
                {
                    cout << "Выберите действие:" << endl;
                    cout << "1. Вывести график функции y=1/x+x, x > " << P <<  " в консоль" << endl;
                    cout << "2. Записать график функции y=1/x+x, x > " << P << " в файл" << endl;
                    cout << "*ДЛЯ ВЫХОДА НАЖМИТЕ КЛАВИШУ > 2*" << endl;
                    cout << "Ввод действия: ";
                    cin >> RecordGrafChoice2;
                    switch (RecordGrafChoice2)
                    {
                        case 1:
                            PrintGraph(Graf2);
                            break;
                        case 2:
                            RecordGraph2(Graf2);
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
