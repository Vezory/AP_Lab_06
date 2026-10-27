// Lab_06_3_iter.cpp
// Новосад Захарій
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (ітераційний спосіб).
// «Перевертання» (реверс) елементів масиву.
// Варіант 16

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 1. Звичайна функція виведення для масиву int
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// 1. Звичайна функція реверсу масиву цілих чисел
void Reverse(int* a, const int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int tmp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = tmp;
    }
}

// 2. Шаблон функції виведення масиву будь-якого типу
template <typename T>
void PrintTemplate(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(7) << a[i];
    cout << endl;
}

// 2. Шаблон функції для універсального «перевертання» масиву
template <typename T>
void ReverseTemplate(T* a, const int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        T tmp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = tmp;
    }
}

#ifndef UNIT_TEST
int main()
{
    const int n = 6;

    // --- Демонстрація звичайної функції (тип int) ---
    int a[n] = { 10, 20, 30, 40, 50, 60 };
    cout << "Original int array:" << endl;
    Print(a, n);

    Reverse(a, n);
    cout << "Reversed int array (regular function):" << endl;
    Print(a, n);

    cout << "\n--------------------------------------------------" << endl;

    // --- Демонстрація шаблону функції (тип double) ---
    double b[n] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5 };
    cout << "Original double array:" << endl;
    PrintTemplate(b, n);

    ReverseTemplate(b, n);
    cout << "Reversed double array (template):" << endl;
    PrintTemplate(b, n);

    cout << "\n--------------------------------------------------" << endl;

    // --- Демонстрація шаблону функції (тип string) ---
    string c[n] = { "one", "two", "three", "four", "five", "six" };
    cout << "Original string array:" << endl;
    PrintTemplate(c, n);

    ReverseTemplate(c, n);
    cout << "Reversed string array (template):" << endl;
    PrintTemplate(c, n);

    return 0;
}
#endif

