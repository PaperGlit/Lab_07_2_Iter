#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_Iter/Lab_07_2_Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int TestMinSum(int** a, const int rowCount, const int colCount)
{
	int S = 0;
	for (int i = 1; i < colCount; i += 2)
	{
		int Min = 70;
		for (int j = 0; j < rowCount; j++)
			if (a[j][i] < Min)
				Min = a[j][i];
		S += Min;
	}
	return S;
}

namespace UnitTestLab072Iter
{
	TEST_CLASS(UnitTestLab072Iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			srand((unsigned)time(NULL));
			int Low = 7;
			int High = 62;
			int rowCount = 7;
			int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			Create(a, rowCount, colCount, Low, High);
			int** b = a;
			Assert::AreEqual(TestMinSum(a, rowCount, colCount), Sum(b, rowCount, colCount));
		}
	};
}
