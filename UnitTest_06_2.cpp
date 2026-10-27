// UnitTest_06_2.cpp
// Тестування функцій лабораторної роботи 6.2 (Варіант 16*)
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../LAB06/Lab_06_2_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest062
{
    TEST_CLASS(UnitTest062)
    {
    public:
        TEST_METHOD(TestMethod_MinEven_Standard)
        {
            // Парні: 12, -4, 8, -6. Найменший серед них = -6
            const int testSize = 8;
            int testArr[testSize] = { 7, -3, 12, -4, 5, 8, -6, 1 };

            bool found = false;
            int minVal = MinEven(testArr, testSize, found);

            Assert::IsTrue(found);
            Assert::AreEqual(-6, minVal);
        }

        TEST_METHOD(TestMethod_MinEven_NoEven)
        {
            // Жодного парного елемента немає
            const int testSize = 4;
            int testArr[testSize] = { 1, 3, 5, 7 };

            bool found = false;
            MinEven(testArr, testSize, found);

            Assert::IsFalse(found);
        }
    };
}

