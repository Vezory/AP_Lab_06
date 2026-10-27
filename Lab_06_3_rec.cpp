// Lab_06_3_rec.cpp
// Новосад Захарій
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (рекурсивний спосіб).
// «Перевертання» (реверс) елементів масиву.
// Варіант 16

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 1. Звичайна рекурсивна функція виведення для масиву int
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

// 1. Звичайна рекурсивна функція реверсу масиву цілих чисел
void Reverse(int* a, const int size, int i = 0)
{
    // Базовий випадок: дійшли до середини масиву
    if (i >= size / 2)
        return;

    // Обмін i-го елемента з (size - 1 - i)-м
    int tmp = a[i];
    a[i] = a[size - 1 - i];
    a[size - 1 - i] = tmp;

    // Рекурсивний виклик для наступної пари
    Reverse(a, size, i + 1);
}

// 2. Шаблон рекурсивної функції виведення
template <typename T>
void PrintTemplate(const T* a, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(7) << a[i];
    PrintTemplate(a, size, i + 1);
}

// 2. Шаблон рекурсивної функції для універсального реверсу
template <typename T>
void ReverseTemplate(T* a, const int size, int i = 0)
{
    if (i >= size / 2)
        return;

    T tmp = a[i];
    a[i] = a[size - 1 - i];
    a[size - 1 - i] = tmp;

    ReverseTemplate(a, size, i + 1);
}

#ifndef UNIT_TEST
int main()
{
    const int n = 6;

    // --- Демонстрація звичайної рекурсивної функції (тип int) ---
    int a[n] = { 10, 20, 30, 40, 50, 60 };
    cout << "Original int array (recursive):" << endl;
    Print(a, n, 0);

    Reverse(a, n, 0);
    cout << "Reversed int array (regular recursive function):" << endl;
    Print(a, n, 0);

    cout << "\n--------------------------------------------------" << endl;

    // --- Демонстрація шаблону рекурсивної функції (тип double) ---
    double b[n] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5 };
    cout << "Original double array (recursive):" << endl;
    PrintTemplate(b, n, 0);

    ReverseTemplate(b, n, 0);
    cout << "Reversed double array (template recursive):" << endl;
    PrintTemplate(b, n, 0);

    cout << "\n--------------------------------------------------" << endl;

    // --- Демонстрація шаблону рекурсивної функції (тип string) ---
    string c[n] = { "one", "two", "three", "four", "five", "six" };
    cout << "Original string array (recursive):" << endl;
    PrintTemplate(c, n, 0);

    ReverseTemplate(c, n, 0);
    cout << "Reversed string array (template recursive):" << endl;
    PrintTemplate(c, n, 0);

    return 0;
}
#endif

