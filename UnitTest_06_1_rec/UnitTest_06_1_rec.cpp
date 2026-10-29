#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6.1_rec/PR_6.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest061rec
{
    TEST_CLASS(UnitTest061rec)
    {
    public:
        TEST_METHOD(TestCountAndSumRec)
        {
            int testArr[] = { -14, -10, -5, 0, 3, 4, -2 };
            const int n = 7;
            Assert::AreEqual(4, Count(testArr, n, 0));
            Assert::AreEqual(-26, Sum(testArr, n, 0));

            Replace(testArr, n, 0);
            Assert::AreEqual(0, testArr[0]);
            Assert::AreEqual(0, testArr[1]);
            Assert::AreEqual(-5, testArr[2]);
            Assert::AreEqual(0, testArr[3]);
            Assert::AreEqual(3, testArr[4]);
            Assert::AreEqual(4, testArr[5]);
            Assert::AreEqual(0, testArr[6]);
        }
    };
}
