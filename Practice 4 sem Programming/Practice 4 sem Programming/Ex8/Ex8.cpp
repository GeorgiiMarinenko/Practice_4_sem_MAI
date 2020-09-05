//
//  Ex8.cpp
//  Practice 4 sem Programming
//
//  Created by Georgy Marinenko on 13/04/2020.
//  Copyright © 2020 Marinenko Georgii. All rights reserved.
//

#include "Ex8.hpp"
#include <iostream>
#include <fstream>
using namespace std;


Ex8::Ex8()
{
    this->AlphabetBig = "QWERTYUIOPASDFGHJKLZXCVBNM";
    this->AlphabetSmall = "qwertyuiopasdfghjklzxcvbnm";
    this->Consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    this->filename = "InputText_Ex_8.txt";
}
int Ex8::FindConsonants(char* Line, int AllLetters)
{
    bool FirstConsonant = false;
    bool SecondConsonant = false;
    int Step = 0;
    int TwoConsonants = 0;
    
    for(int i = 0; i < AllLetters; i++)
    {
        for(int j = 0; j < 42; j++)
        {
            if(Line[i] == Consonants[j])
            {
                
                if(FirstConsonant == false)
                {
                    FirstConsonant = true;
                    Step = 0;
                    break;
                }
                else
                {
                    SecondConsonant = true;
                    break;
                }
            }
        }
        Step++;
        if(Step > 2)
        {
            FirstConsonant = false;
            SecondConsonant = false;
        }
        if((FirstConsonant == true) && (SecondConsonant == true))
        {
            TwoConsonants++;
            i-=2;
        }
    }
    return TwoConsonants;
}

int Ex8::FindInd(char CurrentElem)
{
    for(int i = 0; i < 26; i++)
    {
        if((CurrentElem == AlphabetBig[i]) || (CurrentElem == AlphabetSmall[i]))
        {
            return i;
        }
    }
    return -1;
}

void Ex8::Sorting(long double* Repits)
{
    unsigned char Alphabet[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    //Begin of sorting
    int size = 26;
    int Max;
    float TempRep, TempAlph;
    
    for (int i = 0; i < size - 1; i++)
    {
        Max = i;
        for (int j = i + 1; j < size; j++)
        {
            if (Repits[j] > Repits[Max])
            {
                Max = j;
            }
        }
        TempRep = Repits[i];
        Repits[i] = Repits[Max];
        Repits[Max] = TempRep;
        
        TempAlph = Alphabet[i];
        Alphabet[i] = Alphabet[Max];
        Alphabet[Max] = TempAlph;
    }//End of sorting
}
int Ex8::Start()
{
    unsigned char Alphabet[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    long double Repits[26]; //Массив повторение
    double Persantage[26];//Массив процентного соотношения частоты употребления букв
    for(int i = 0; i < 26; i ++)//Обнуление массивов
    {
        Repits[i] = 0;
        Persantage[i] = 0.;
    }
    char CurrentString[1024];
    int AllLetters = 0; //Счетчик всех букв в тексте
    int TwoConsonants;//Счетчик кол-ва стояющих вместе согласных
    int Index;//Индекс текущей буквы в тексте
    int i;//Счетчик
    int Max;//Максимальное число употребления в тексте одной буквы
    char Diagram[30][53];//Матрица для вывода гистограммы
    int Numb;//Счетчик для создания отступа между столбцами гистограммы
    
    //Переменные для управления меню:
    unsigned int ShowText = 0;
    unsigned int ShowStatistics = 0;
    unsigned int CreateDiagramm = 0;
    unsigned int RecordDiagramInFile = 0;
    
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open())
    {
        cout << "Error of opening, please check data and try again" << endl;
        return -1;
    }
    else
    {
        cout << "File opened successfuly!\n" << endl;
        i = 0;
        while(!fin.eof())
        {
            fin >> CurrentString[i];
            Index = FindInd(CurrentString[i]);
            if(Index != -1)
            {
                Repits[Index]++;
                AllLetters++;
            }
            i++;
        }
        if(AllLetters == 0)
        {
            cout << "Файл пуст" << endl;
            return 0;
        }
        cout << "Для вывода текста в консоль нажмите 1" << endl;
        cout << "Иначе нажмите клавишу > 1" << endl;
        cout << "Введите действие: ";
        cin >> ShowText;
        if(ShowText == 1)
        {
            for( int i = 0 ; i < AllLetters; i++)
            {
                cout << CurrentString[i];
            }
        }
        cout << endl;
        TwoConsonants = FindConsonants(CurrentString, AllLetters);
        
        Sorting(Repits);//Sorting
    }
    //Вычисление процентного соотношения употребления букв в тексте
    cout << "Для вычисления процентного соотношения употребления букв в тексте и вывода статистики на экран нажмите 1" << endl;
    cout << "Иначе нажмите клавишу > 1" << endl;
    cout << "Введите действие: ";
    cin >> ShowStatistics;
    if(ShowStatistics == 1)
    {
        for(int i = 0; i < 26; i++)
        {
            Persantage[i] = Repits[i]/AllLetters*100;
            cout << "[" << Alphabet[i] << "] = " << Repits[i] << " - " << Persantage[i] << " %" << endl;
        }
        cout << "Всего символов в тексте: " << AllLetters << endl;
        cout << "Две согласные, стоящие рядом, были обнаружены " << TwoConsonants << " раз(а)\n" << endl;
    }
    
    cout << "Для создания гистограммы и вывода ее в консоль нажмите 1" << endl;
    cout << "Иначе нажмите клавишу > 1" << endl;
    cout << "Введите действие: ";
    cin >> CreateDiagramm;
    if(CreateDiagramm == 1)
    {
        //Создание диаграммы
        Max = Repits[0];
        Numb = 0;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 53; j++)
            {
                Diagram[i][j] = ' ';
            }
        }
        for(int i = 0; i < 53;i++)
        {
            Diagram[28][i] = '-';
            Diagram[29][i] = '_';
        }
        for(int j = 0; j < 26; j++)
        {
            Diagram[29][1+Numb] = Alphabet[j];
            Numb +=2;
        }
        Numb = 0;
        for(int i = 0; i < 26; i++)
        {
            int Difference = 27 - (int)(Repits[i]/Max*27);
            for(int j = 27;j > Difference;j--)
            {
                Diagram[j][1+Numb] = '=';
            }
            Numb +=2;
        }
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<53;j++)
            {
                cout << Diagram[i][j];
            }
            cout << endl;
        }
        cout << "\n\nМасштаб: 1 буква - " << (float)27/(float)Repits[0] << " символ(ов) '='\n\n";
        
        cout << "Для записи гистограммы в файл нажмите 1" << endl;
        cout << "Иначе нажмите клавишу > 1" << endl;
        cout << "Введите действие: ";
        cin >> RecordDiagramInFile;
        if(RecordDiagramInFile == 1)
        {
            //Запись диаграммы в файл
            ofstream fout("Output_file_Ex8.txt", ios::out);
               for (int i = 0; i < 30; i++)
               {
                   for (int j = 0; j < 53; j++)
                   {
                       fout << Diagram[i][j];
                   }
                   fout << '\n';
               }
            fout << "\n\nМасштаб: 1 буква - " << (float)27/(float)Repits[0] << " символ(ов) '='\n";
            cout << "*Запись в файл прошла успешно*\n" << endl;
            fin.close();
            return 0;
        }
    }
    return 0;
}
