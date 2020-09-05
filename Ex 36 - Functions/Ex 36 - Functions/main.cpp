#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

const char *filename = "InputFileEx36.txt";
char Graf[24][44];

int Fact(int x)//Функция поиска факториала
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

double Exp(double X)
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
double Function1(double X, double K)
{
    double Y;
    Y = K*Exp(X) - sin(X);
    return Y;
}

double Function2(double X)
{
    double Y;
    Y = 1/X + X;
    return Y;
}

void PrintHeader()
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

void SetGraphAxis()
{
    cout << "График:" << endl;
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 44; j++)
        {
            Graf[i][j] = ' ';
        }
    }
    for(int i = 0; i < 41; i++) //Отрисовка горизонтальной оси
    {
        Graf[10][i] = '-';
    }
    Graf[10][32] = '>';
    Graf[10][33] = 'x';
    
    for(int i = 0; i < 21; i++) //Отрисовка вертикальной оси
    {
        Graf[i][16] = '|';
    }
    Graf[0][16] = 'y';
    Graf[1][16] = '^';
}

void CreateGraph(float X, float Y)
{
    int PointX = 1;
    int PointY = 1;
    
    X *= 10;
    Y *= 100;
    Y = (int)Y;
//    cout << "x = " << X << "  ";
//    cout << "y= " << Y << endl;
    PointX *= X;
    PointY *= Y;
    
    if((X > 0) && (Y > 0))
    {
        Graf[10 + PointY][16 + PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
    else if((X > 0) && (Y < 0))
    {
        Graf[10 - PointY][16 + PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
    else if((X < 0) && (Y > 0))
    {
        Graf[10 + PointY][16 - PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
    else if((X < 0) && (Y < 0))
    {
        Graf[10 - PointY][16 - PointX] = '~';
        PointX = 1;
        PointY = 1;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    
    double A; //Левая граница отрезка
    double B; //Правая граница отрезка
    double Step; //Шаг движения по отрезку
    double P; //Ограничение отрезка
    double K; //Коэффицент для уравнения 1
    double Array[5];
    
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open())
    {
        cout << "Error of opening, please check data and try again" << endl;
        return -1;
    }
    else
    {
       int i = 0;
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
    SetGraphAxis();
    double X = A;
    double Y;
    int j = 1;
    wcout << setw (10) << "Function: y=" << K << "e^x-sinx, x <= " << P << endl;
    PrintHeader();
    
    while(X <= P)
    {
        Y = Function1(X,K);
        CreateGraph(X, Y);
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
    
    j = 1;
    cout << endl;
    wcout << setw (10) << "Function: " << "y=1/x+x, x > " << P << endl;
    PrintHeader();
    while(X <= B+0.1)
    {
        Y = Function2(X);
        
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
    
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 34; j++)
        {
            cout << Graf[i][j];
        }
        cout << endl;
    }
    
    return 0;
    
}
