// Lab_06_2_iter.cpp
// Новосад Захарій
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційним способом.
// Пошук найменшого парного елемента масиву.
// Варіант 16*

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення елементів масиву в рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// Пошук індексу першого парного елемента (для стартової ініціалізації)
int FirstEvenIndex(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        // Умова парності: число ділиться на 2 без залишку
        if (a[i] % 2 == 0)
            return i;
    }
    return -1; // Якщо жодного парного елемента не знайдено
}

// Пошук найменшого парного елемента (ітераційний спосіб)
int MinEven(const int* a, const int size, bool& found)
{
    int firstIdx = FirstEvenIndex(a, size);
    if (firstIdx == -1)
    {
        found = false;
        return 0;
    }

    found = true;
    int minEven = a[firstIdx];

    for (int i = firstIdx + 1; i < size; i++)
    {
        // Якщо поточний елемент парний і менший за поточний мінімум
        if (a[i] % 2 == 0 && a[i] < minEven)
        {
            minEven = a[i];
        }
    }
    return minEven;
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    const int Low = -30;
    const int High = 30;

    cout << "Array a (" << n << " elements):" << endl;
    Create(a, n, Low, High);
    Print(a, n);

    bool found = false;
    int minEven = MinEven(a, n, found);

    cout << "\nResult:" << endl;
    if (found)
        cout << "Smallest even element = " << minEven << endl;
    else
        cout << "There are no even elements in the array!" << endl;

    return 0;
}
#endif

