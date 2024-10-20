#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab07_1it/Lab07_1it.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
    // Тест для функції Create
    TEST_CLASS(CreateTests)
    {
    public:

        TEST_METHOD(Create_PopulatesArrayWithValuesWithinRange)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int Low = -10, High = 10;


            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];


            Create(a, rowCount, colCount, Low, High);
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };

    TEST_CLASS(Part1CountTests)
    {
    public:

        TEST_METHOD(Part1_Count_ReturnsTrueIfZeroExists)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int count = 0;


            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount] {1, 2, 0}; 
 
            bool result = Part1_Count(a, rowCount, colCount, count);

            Assert::IsTrue(result);
            Assert::AreEqual(1, count);

        
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(Part1_Count_ReturnsFalseIfNoZero)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int count = 0;

     
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount] {1, 2, 3};

        
            bool result = Part1_Count(a, rowCount, colCount, count);

            Assert::IsFalse(result);
            Assert::AreEqual(0, count);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };

  
    TEST_CLASS(RowCharacteristicTests)
    {
    public:

        TEST_METHOD(RowCharacteristic_CalculatesSumOfPositiveEvenNumbers)
        {
            int row[] = { 2, -4, 3, 8, 5, 6 };
            int cols = sizeof(row) / sizeof(row[0]);

            int result = rowCharacteristic(row, cols);

            Assert::AreEqual(16, result);
        }

        TEST_METHOD(RowCharacteristic_ReturnsZeroIfNoPositiveEvenNumbers)
        {
            int row[] = { -2, -4, -6, -8 };
            int cols = sizeof(row) / sizeof(row[0]);

            int result = rowCharacteristic(row, cols);

            Assert::AreEqual(0, result);
        }
    };

    TEST_CLASS(SortRowsByCharacteristicTests)
    {
    public:

        TEST_METHOD(SortRowsByCharacteristic_SortsRowsBySumOfPositiveEvenNumbers)
        {
            const int rowCount = 3;
            const int colCount = 3;

            int** a = new int* [rowCount];
            a[0] = new int[colCount] {2, 4, 6}; 
            a[1] = new int[colCount] {1, 3, 5};  
            a[2] = new int[colCount] {8, 0, -2}; 

            sortRowsByCharacteristic(a, rowCount, colCount);

            Assert::AreEqual(1, a[0][0]);
            Assert::AreEqual(8, a[1][0]);
            Assert::AreEqual(2, a[2][0]);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
