//
//  Ex27.hpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 17/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#ifndef Ex27_hpp
#define Ex27_hpp

#include <stdio.h>
using namespace std;

class Ex27
{
    
public:
    char Graf[25][53];
    
    Ex27();
    
    double Function1(double x);
    double Function2(double x);
    double Function3(double x);
    void SetGraphAxis();
    void CreateFunction(double a,double b);
    void PrintGraf();
    double RectangleMethod(double a, double b, double n, unsigned int FuncChoice);

    
    int Start();
};
#endif /* Ex27_hpp */
