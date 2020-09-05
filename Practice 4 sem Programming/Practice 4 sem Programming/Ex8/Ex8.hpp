//
//  Ex8.hpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 13/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#ifndef Ex8_hpp
#define Ex8_hpp

#include <stdio.h>
using namespace std;

class Ex8
{
    
public:
    char* AlphabetBig;
    char* AlphabetSmall;
    char* Consonants;
    char *filename;
    
    Ex8();
    
    int FindInd(char CurrentElem);//Поиск соответсвующего индекса индексу буквы
    void DiagramCreation(float Repits, int AllLetters);//Создание диаграммы
    int FindConsonants(char* Line, int AllLetters);//Поиск двух рядомстоящих согласных
    void Sorting(long double* Repits);//Функция сортировки
    
    int Start();
};
#endif /* Ex8_hpp */
