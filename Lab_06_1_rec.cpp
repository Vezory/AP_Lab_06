// Lab_06_1_rec.cpp
// Новосад Захарій
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву рекурсивним способом.
// Варіант 16

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву випадковими числами в діапазоні [Low, High]
void Create(int* r, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size)
        return;
    r[i] = Low + rand() % (High - Low + 1);
    Create(r, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void Print(const int* r, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << r[i];
    Print(r, size, i + 1);
}

// Критерій: всі додатні, крім кратних 4 (буквальне виконання умови: додатні && !(кратні 4))
bool Criterion(int element)
{
    return element > 0 && !(element % 4 == 0);
}

// Рекурсивне обчислення кількості елементів
int Count(const int* r, const int size, int i = 0)
{
    if (i >= size)
        return 0;
    return (Criterion(r[i]) ? 1 : 0) + Count(r, size, i + 1);
}

// Рекурсивне обчислення суми елементів
int Sum(const int* r, const int size, int i = 0)
{
    if (i >= size)
        return 0;
    return (Criterion(r[i]) ? r[i] : 0) + Sum(r, size, i + 1);
}

// Рекурсивна заміна нулями елементів
void Replace(int* r, const int size, int i = 0)
{
    if (i >= size)
        return;
    if (Criterion(r[i]))
        r[i] = 0;
    Replace(r, size, i + 1);
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int r[n];

    const int Low = -19;
    const int High = 25;

    cout << "Initial array r (recursive):" << endl;
    Create(r, n, Low, High, 0);
    Print(r, n, 0);

    int count = Count(r, n, 0);
    int sum = Sum(r, n, 0);

    Replace(r, n, 0);

    cout << "\nResults:" << endl;
    cout << "Count of elements matching criterion = " << count << endl;
    cout << "Sum of elements matching criterion   = " << sum << endl;

    cout << "\nModified array r (with zeroes):" << endl;
    Print(r, n, 0);

    return 0;
}
#endif
