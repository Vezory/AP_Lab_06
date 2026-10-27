// UnitTest_06_4.cpp
// Тестування функцій лабораторної роботи 6.4 (Варіант 16)
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../LAB06/Lab_06_4_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest064
{
    TEST_CLASS(UnitTest064)
    {
    public:
        TEST_METHOD(TestMethod_Count_and_SumAbs)
        {
            // Масив: { 3.0, -4.0, 0.5, -2.0, 1.0 }
            // Від'ємні: -4.0, -2.0 -> кількість = 2
            // Модулі: { 3.0, 4.0, 0.5, 2.0, 1.0 } -> мінімальний за модулем = 0.5 на індексі 2
            // Елементи після індексу 2: { -2.0, 1.0 } -> сума їх модулів = |-2.0| + |1.0| = 3.0
            const int testSize = 5;
            double testArr[testSize] = { 3.0, -4.0, 0.5, -2.0, 1.0 };

            int cNeg = CountNegative(testArr, testSize);
            int minIdx = MinAbsIndex(testArr, testSize);
            double sumAbs = SumAbsAfterMin(testArr, testSize);

            Assert::AreEqual(2, cNeg);
            Assert::AreEqual(2, minIdx);
            Assert::AreEqual(3.0, sumAbs, 1e-5);
        }

        TEST_METHOD(TestMethod_TransformAndSort)
        {
            // Початковий: { 5.0, -4.0, 2.0, -1.0, 9.0, -3.0 }
            // Від'ємні на позиціях 1, 3, 5: {-4.0, -1.0, -3.0}
            // Їх квадрати: {16.0, 1.0, 9.0}
            // Сортування квадратів за зростанням: 1.0, 9.0, 16.0
            // Очікуваний результат:
            // index 0: 5.0 (незмінний)
            // index 1: 1.0
            // index 2: 2.0 (незмінний)
            // index 3: 9.0
            // index 4: 9.0 (незмінний)
            // index 5: 16.0
            const int testSize = 6;
            double testArr[testSize] = { 5.0, -4.0, 2.0, -1.0, 9.0, -3.0 };

            TransformAndSort(testArr, testSize);

            Assert::AreEqual(5.0, testArr[0], 1e-5);
            Assert::AreEqual(1.0, testArr[1], 1e-5);
            Assert::AreEqual(2.0, testArr[2], 1e-5);
            Assert::AreEqual(9.0, testArr[3], 1e-5);
            Assert::AreEqual(9.0, testArr[4], 1e-5);
            Assert::AreEqual(16.0, testArr[5], 1e-5);
        }
    };
}

