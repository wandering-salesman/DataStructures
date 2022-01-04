#include <stdio.h>

int exponent(int n, int p);
int fastExponent(int n, int p);

int main()
{   
    int n = 16;
    int p = 2;
    int res = exponent(n, p);
    printf("exponent: %d", res);
    res = fastExponent(n, p);
    printf("\nfast exponent: %d", res);
    return 0;
}

int exponent(int n, int p)
{
    if (n == 1 || p == 0)
    {
        return 1;
    }
    else
    {
        return n * exponent(n, p - 1);
    }
}

int fastExponent(int n, int p)
{
    if (n == 1 || p == 0)
    {
        return 1;
    }
    else
    {
        if (p % 2 == 0)
        {
            return fastExponent(n*n, p / 2);
        }
        else
        {
            return n * fastExponent(n*n, p / 2);
        }
    }
}