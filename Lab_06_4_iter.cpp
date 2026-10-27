// Lab_06_4_iter.cpp
// Новосад Захарій
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів (ітераційний спосіб).
// Варіант 16

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування динамічного масиву випадковими дійсними числами
void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
    {
        // Генерація випадкового числа з двома знаками після коми
        a[i] = Low + (High - Low) * (rand() / (double)RAND_MAX);
    }
}

// Форматне виведення масиву
void Print(const double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << fixed << setprecision(2) << a[i];
    cout << endl;
}

// 1.1. Кількість від’ємних елементів масиву
int CountNegative(const double* a, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
            count++;
    }
    return count;
}

// Пошук індексу мінімального за модулем елемента масиву
int MinAbsIndex(const double* a, const int size)
{
    int minIdx = 0;
    double minVal = fabs(a[0]);
    for (int i = 1; i < size; i++)
    {
        if (fabs(a[i]) < minVal)
        {
            minVal = fabs(a[i]);
            minIdx = i;
        }
    }
    return minIdx;
}

// 1.2. Сума модулів елементів, розташованих після мінімального за модулем елемента
double SumAbsAfterMin(const double* a, const int size)
{
    int minIdx = MinAbsIndex(a, size);
    double sum = 0.0;
    for (int i = minIdx + 1; i < size; i++)
    {
        sum += fabs(a[i]);
    }
    return sum;
}

// 2. Заміна від'ємних їх квадратами та сортування цих елементів за зростанням
void TransformAndSort(double* a, const int size)
{
    // Масив прапорців, щоб пам'ятати позиції початково від'ємних елементів
    bool* wasNegative = new bool[size];
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            wasNegative[i] = true;
            a[i] = a[i] * a[i]; // Заміна квадратом
        }
        else
        {
            wasNegative[i] = false;
        }
    }

    // Сортування методом вибору (або бульбашкою) лише тих елементів, де wasNegative == true
    for (int i = 0; i < size - 1; i++)
    {
        if (!wasNegative[i])
            continue;

        for (int j = i + 1; j < size; j++)
        {
            if (!wasNegative[j])
                continue;

            // Сортування за зростанням
            if (a[i] > a[j])
            {
                double tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    delete[] wasNegative;
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "Enter array size n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: size must be positive!" << endl;
        return 1;
    }

    // Динамічне виділення пам'яті
    double* a = new double[n];

    const double Low = -10.0;
    const double High = 10.0;

    cout << "\nInitial dynamic array:" << endl;
    Create(a, n, Low, High);
    Print(a, n);

    int countNeg = CountNegative(a, n);
    int minIdx = MinAbsIndex(a, n);
    double sumAbs = SumAbsAfterMin(a, n);

    cout << "\nResults:" << endl;
    cout << "1.1. Count of negative elements          = " << countNeg << endl;
    cout << "     Min abs element index               = " << minIdx << " (value = " << a[minIdx] << ")" << endl;
    cout << "1.2. Sum of modules after min abs element = " << sumAbs << endl;

    TransformAndSort(a, n);

    cout << "\n2. Modified dynamic array (negatives squared & sorted):" << endl;
    Print(a, n);

    // Звільнення динамічної пам'яті
    delete[] a;

    return 0;
}
#endif

