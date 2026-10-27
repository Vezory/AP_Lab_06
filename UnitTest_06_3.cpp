// UnitTest_06_3.cpp
// Тестування функцій лабораторної роботи 6.3 (Варіант 16)
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../LAB06/Lab_06_3_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest063
{
    TEST_CLASS(UnitTest063)
    {
    public:
        TEST_METHOD(TestMethod_Reverse_Int)
        {
            const int testSize = 5;
            int testArr[testSize] = { 1, 2, 3, 4, 5 };

            Reverse(testArr, testSize);

            Assert::AreEqual(5, testArr[0]);
            Assert::AreEqual(4, testArr[1]);
            Assert::AreEqual(3, testArr[2]);
            Assert::AreEqual(2, testArr[3]);
            Assert::AreEqual(1, testArr[4]);
        }

        TEST_METHOD(TestMethod_ReverseTemplate_Double)
        {
            const int testSize = 4;
            double testArr[testSize] = { 10.5, 20.5, 30.5, 40.5 };

            ReverseTemplate(testArr, testSize);

            Assert::AreEqual(40.5, testArr[0]);
            Assert::AreEqual(30.5, testArr[1]);
            Assert::AreEqual(20.5, testArr[2]);
            Assert::AreEqual(10.5, testArr[3]);
        }
    };
}

