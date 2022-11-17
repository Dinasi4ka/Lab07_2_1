// Lab07_2_it.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a,const int k, const int n, const int Low, const int High);
void Print(int** a,const int k, const int n);
int Create(int** a, const int k, const int n);


int main()
{
    srand((unsigned)time(NULL));

    int Low = -30;
    int High = 70;

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];


    Create(a,k, n, Low, High);
    Print(a,k, n);

    cout << "Sum= " << Calc(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a,const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a,const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
int Calc(int** a, const int k, const int n)
{
    int max = 0, Sum = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        Sum += max;
    }
    return Sum;
}

