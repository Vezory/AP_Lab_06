// Lab_06_1_iter.cpp
// Новосад Захарій
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним способом.
// Варіант 16

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву випадковими числами в діапазоні [Low, High]
void Create(int* r, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        r[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву в консоль
void Print(const int* r, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i];
    cout << endl;
}

// Критерій: всі додатні, крім кратних 4 (буквальне виконання умови: додатні && !(кратні 4))
bool Criterion(int element)
{
    return element > 0 && !(element % 4 == 0);
}

// Обчислення кількості елементів, що задовольняють критерію
int Count(const int* r, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (Criterion(r[i]))
            count++;
    }
    return count;
}

// Обчислення суми елементів, що задовольняють критерію
int Sum(const int* r, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (Criterion(r[i]))
            sum += r[i];
    }
    return sum;
}

// Заміна нулями елементів, що задовольняють критерію
void Replace(int* r, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (Criterion(r[i]))
            r[i] = 0;
    }
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int r[n];

    const int Low = -19;
    const int High = 25;

    cout << "Initial array r:" << endl;
    Create(r, n, Low, High);
    Print(r, n);

    int count = Count(r, n);
    int sum = Sum(r, n);

    Replace(r, n);

    cout << "\nResults:" << endl;
    cout << "Count of elements matching criterion = " << count << endl;
    cout << "Sum of elements matching criterion   = " << sum << endl;

    cout << "\nModified array r (with zeroes):" << endl;
    Print(r, n);

    return 0;
}
#endif
