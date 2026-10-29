// PR_6.1.rec.cpp
// Варіант 8 (рекурсивний спосіб)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(b, size, Low, High, i + 1);
}

void Print(const int* b, const int size, int i)
{
    cout << setw(4) << b[i];
    if (i < size - 1)
        Print(b, size, i + 1);
    else
        cout << endl;
}

int Count(const int* b, const int size, int i)
{
    if (i >= size)
        return 0;
    if (b[i] % 2 == 0 && b[i] <= 0)
        return 1 + Count(b, size, i + 1);
    else
        return Count(b, size, i + 1);
}

int Sum(const int* b, const int size, int i)
{
    if (i >= size)
        return 0;
    if (b[i] % 2 == 0 && b[i] <= 0)
        return b[i] + Sum(b, size, i + 1);
    else
        return Sum(b, size, i + 1);
}

void Replace(int* b, const int size, int i)
{
    if (i >= size)
        return;
    if (b[i] % 2 == 0 && b[i] <= 0)
        b[i] = 0;
    Replace(b, size, i + 1);
}

#if !defined(_WINDLL)
int main()
{
    srand((unsigned)time(NULL));
    const int n = 24;
    int b[n];
    const int Low = -15;
    const int High = 75;

    Create(b, n, Low, High, 0);
    cout << "Initial array b:" << endl;
    Print(b, n, 0);

    int count = Count(b, n, 0);
    int sum = Sum(b, n, 0);
    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    Replace(b, n, 0);
    cout << "Modified array b:" << endl;
    Print(b, n, 0);

    return 0;
}
#endif
