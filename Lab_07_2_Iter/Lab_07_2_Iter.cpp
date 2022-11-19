#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Min(int** a, int i, const int rowCount)
{
	int min = 70;
	for (int j = 0; j < rowCount; j++)
		if (a[j][i] < min)
			min = a[j][i];
	return min;
}

int Sum(int** a, const int rowCount, const int colCount)
{
	int S = 0;
	for (int i = 1; i < colCount; i += 2)
	{
		S += Min(a, i, rowCount);
	}
	return S;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 62;
	int rowCount = 7;
	int colCount = 6;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	cout << "Сума мінімальних елементів по парних стовпцях матриці: " << Sum(a, rowCount, colCount) << endl;
	return 0;
}