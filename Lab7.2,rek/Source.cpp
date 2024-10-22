#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#define RED "\033[31m"
#define RESET "\033[0m"
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

int MIN(int* row, const int N, int colNo)
{
    int MinEl = row[colNo];
    if (colNo < N - 1)
        MinEl = min(MinEl, MIN(row, N, colNo + 1));
    return MinEl;
}

void PrintRow(int** a, const int rowNo, const int N, int colNo, int min)
{
    if (a[rowNo][colNo] == min && rowNo % 2 != 0) 
        cout << RED << setw(4) << a[rowNo][colNo] << RESET;
    else
        cout << setw(4) << a[rowNo][colNo];

    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1, min);
    else
        cout << endl;
}

void PrintRows(int** a, const int K, const int N, int rowNo)
{
    int minInRow = (rowNo % 2 != 0) ? MIN(a[rowNo], N, 0) : INT_MAX;
    PrintRow(a, rowNo, N, 0, minInRow);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}

int SumMinOddRows(int** a, const int K, const int N, int rowNo)
{
    if (rowNo >= K) return 0;

    int sum = 0;
    if (rowNo % 2 != 0)
    {
        int minInRow = MIN(a[rowNo], N, 0);
        sum += minInRow;
    }

    return sum + SumMinOddRows(a, K, N, rowNo + 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));

    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;
    cout << endl;

    int Low = -99, High = 99;

    int** a = new int* [K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];

    CreateRows(a, K, N, Low, High, 0);
    PrintRows(a, K, N, 0);

    int sumMinOddRows = SumMinOddRows(a, K, N, 0);
    cout << "Сума мінімальних елементів по непарних рядках = " << sumMinOddRows << endl;

    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
