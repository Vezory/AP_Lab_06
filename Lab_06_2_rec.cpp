// Lab_06_2_rec.cpp
// Новосад Захарій
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів рекурсивним способом.
// Пошук найменшого парного елемента масиву.
// Варіант 16*

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву
void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size)
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення елементів масиву
void Print(const int* a, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(5) << a[i];
    Print(a, size, i + 1);
}

// Рекурсивний пошук індексу першого парного елемента
int FirstEvenIndex(const int* a, const int size, int i = 0)
{
    if (i >= size)
        return -1; // Дійшли до кінця, парних немає
    if (a[i] % 2 == 0)
        return i;  // Знайшли перший парний
    return FirstEvenIndex(a, size, i + 1); // Перевіряємо наступний
}

// Рекурсивний пошук найменшого серед парних елементів
int MinEven(const int* a, const int size, int i, int minEven)
{
    // Базовий випадок (вихід з рекурсії)
    if (i >= size)
        return minEven;

    // Якщо поточний елемент парний і менший за поточний мінімум
    if (a[i] % 2 == 0 && a[i] < minEven)
        minEven = a[i];

    // Рекурсивний крок для наступного індексу
    return MinEven(a, size, i + 1, minEven);
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    const int Low = -30;
    const int High = 30;

    cout << "Array a (recursive):" << endl;
    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int firstIdx = FirstEvenIndex(a, n, 0);

    cout << "\nResult:" << endl;
    if (firstIdx != -1)
    {
        int minEven = MinEven(a, n, firstIdx + 1, a[firstIdx]);
        cout << "Smallest even element = " << minEven << endl;
    }
    else
    {
        cout << "There are no even elements in the array!" << endl;
    }

    return 0;
}
#endif

