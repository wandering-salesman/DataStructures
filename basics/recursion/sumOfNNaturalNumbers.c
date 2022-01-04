#include <stdio.h>

int sumOfN(int n);

int main()
{
    int r = sumOfN(5);
    printf("%d", r);
    return 0;
}

int sumOfN(int n)
{
    if (n == 0)
    {
        return 0;
    }

    else
    {
        return sumOfN(n - 1) + n;
    }
}