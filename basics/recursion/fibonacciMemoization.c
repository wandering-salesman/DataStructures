#include <stdio.h>
#include "../printArray.h"

int F[10];
int fibonacci(int n);

int main()
{
    printArr(F, 10);

    int res = fibonacci(6);
    printf("%d", res);
    return 0;
}

int fibonacci(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    if (F[n] != 0)
        return F[n];
    else
    {
        F[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return F[n];
    }
}