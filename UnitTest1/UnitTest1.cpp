#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2,rek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(Test)
        {
            int N = 5;
            int Low = 1, High = 10;

            int* row = new int[N];
            CreateRow(&row, 0, N, Low, High, 0);

            for (int i = 0; i < N; i++)
            {
                Assert::IsTrue(row[i] >= Low && row[i] <= High);
            }

            delete[] row;
        }
    };
}
