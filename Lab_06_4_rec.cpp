// Lab_06_4_rec.cpp
// Новосад Захарій
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів (рекурсивний спосіб).
// Варіант 16

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування динамічного масиву
void Create(double* a, const int size, const double Low, const double High, int i = 0)
{
    if (i >= size)
        return;
    a[i] = Low + (High - Low) * (rand() / (double)RAND_MAX);
    Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void Print(const double* a, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(8) << fixed << setprecision(2) << a[i];
    Print(a, size, i + 1);
}

// 1.1. Рекурсивне обчислення кількості від’ємних елементів
int CountNegative(const double* a, const int size, int i = 0)
{
    if (i >= size)
        return 0;
    return (a[i] < 0 ? 1 : 0) + CountNegative(a, size, i + 1);
}

// Рекурсивний пошук індексу мінімального за модулем елемента
int MinAbsIndex(const double* a, const int size, int i = 1, int minIdx = 0)
{
    if (i >= size)
        return minIdx;
    if (fabs(a[i]) < fabs(a[minIdx]))
        minIdx = i;
    return MinAbsIndex(a, size, i + 1, minIdx);
}

// 1.2. Рекурсивне обчислення суми модулів після вказаного індексу
double SumAbsFromIndex(const double* a, const int size, int i)
{
    if (i >= size)
        return 0.0;
    return fabs(a[i]) + SumAbsFromIndex(a, size, i + 1);
}

// Рекурсивна заміна від'ємних елементів їх квадратами
void SquareNegatives(double* a, bool* wasNeg, const int size, int i = 0)
{
    if (i >= size)
        return;
    if (a[i] < 0)
    {
        wasNeg[i] = true;
        a[i] = a[i] * a[i];
    }
    else
    {
        wasNeg[i] = false;
    }
    SquareNegatives(a, wasNeg, size, i + 1);
}

// Внутрішня рекурсія для сортування (пошук мінімального серед відповідних елементів)
void SortInner(double* a, const bool* wasNeg, const int size, const int i, int j)
{
    if (j >= size)
        return;
    if (wasNeg[j] && a[i] > a[j])
    {
        double tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    SortInner(a, wasNeg, size, i, j + 1);
}

// Зовнішня рекурсія для проходу по масиву
void SortOuter(double* a, const bool* wasNeg, const int size, int i = 0)
{
    if (i >= size - 1)
        return;
    if (wasNeg[i])
        SortInner(a, wasNeg, size, i, i + 1);
    SortOuter(a, wasNeg, size, i + 1);
}

// 2. Головна функція заміни та сортування (рекурсивна)
void TransformAndSort(double* a, const int size)
{
    bool* wasNeg = new bool[size];
    SquareNegatives(a, wasNeg, size, 0);
    SortOuter(a, wasNeg, size, 0);
    delete[] wasNeg;
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "Enter array size n (recursive): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: size must be positive!" << endl;
        return 1;
    }

    double* a = new double[n];

    const double Low = -10.0;
    const double High = 10.0;

    cout << "\nInitial dynamic array:" << endl;
    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int countNeg = CountNegative(a, n, 0);
    int minIdx = MinAbsIndex(a, n, 1, 0);
    double sumAbs = SumAbsFromIndex(a, n, minIdx + 1);

    cout << "\nResults:" << endl;
    cout << "1.1. Count of negative elements          = " << countNeg << endl;
    cout << "     Min abs element index               = " << minIdx << " (value = " << a[minIdx] << ")" << endl;
    cout << "1.2. Sum of modules after min abs element = " << sumAbs << endl;

    TransformAndSort(a, n);

    cout << "\n2. Modified dynamic array (negatives squared & sorted):" << endl;
    Print(a, n, 0);

    delete[] a;

    return 0;
}
#endif

