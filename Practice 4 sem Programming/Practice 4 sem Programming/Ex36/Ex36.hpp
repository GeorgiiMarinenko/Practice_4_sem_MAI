//
//  Ex36.hpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 13/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#ifndef Ex36_hpp
#define Ex36_hpp

#include <stdio.h>
using namespace std;

class Ex36
{
    
public:
    char* filename;
    char** Graf1;
    char** Graf2;
    
    Ex36();
    
    int Fact(int x);//Функция поиска факториала
    double Exp(double X);//Подсчет экспоненты
    double Function1(double X, double K);//Расчет 1 функции
    double Function2(double X);//Расчет 2 функции
    void PrintHeader();//Печать заголовка таблицы
    char** SetGraphAxis(char** Graf);//Отрисовка осей координат графика
    void CreateGraph(float X, float Y, char** Graf);//Создание графиков функций
    void PrintGraph(char** Graf);//Печать графиков в консоль
    void RecordGraph1(char** Graf);//Запись графика 1-й функции в файл
    void RecordGraph2(char** Graf);//Запись графика 2-й функции в файл
    
    int Start();
};

#endif /* Ex36_hpp */
