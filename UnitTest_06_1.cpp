// UnitTest_06_1.cpp
// Тестування функцій лабораторної роботи 6.1 (Варіант 16)
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../LAB06/Lab_06_1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest061
{
    TEST_CLASS(UnitTest061)
    {
    public:
        TEST_METHOD(TestMethod_Count_and_Sum)
        {
            // Тестовий масив:
            // Критерій: всі додатні, крім кратних 4 (> 0 && % 4 != 0)
            // Елементи:
            // 5  (підходить, +5)
            // 8  (кратне 4, ні)
            // -3 (від'ємне, ні)
            // 7  (підходить, +7)
            // 0  (не додатне, ні)
            // 4  (кратне 4, ні)
            // 2  (підходить, +2)
            // Разом підходять: 5, 7, 2 -> Кількість = 3, Сума = 14
            const int testSize = 7;
            int testArr[testSize] = { 5, 8, -3, 7, 0, 4, 2 };

            int c = Count(testArr, testSize);
            int s = Sum(testArr, testSize);

            Assert::AreEqual(3, c);
            Assert::AreEqual(14, s);

            Replace(testArr, testSize);

            // Перевіряємо, що підходящі замінені на 0
            Assert::AreEqual(0, testArr[0]);  // було 5 -> стало 0
            Assert::AreEqual(8, testArr[1]);  // 8 лишилося
            Assert::AreEqual(-3, testArr[2]); // -3 лишилося
            Assert::AreEqual(0, testArr[3]);  // було 7 -> стало 0
            Assert::AreEqual(0, testArr[4]);  // 0 лишилося
            Assert::AreEqual(4, testArr[5]);  // 4 лишилося
            Assert::AreEqual(0, testArr[6]);  // було 2 -> стало 0
        }
    };
}

