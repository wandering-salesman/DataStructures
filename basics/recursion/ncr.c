#include <stdio.h>

int ncr(int n, int r);

int main()
{
    int res = ncr(5, 3);
    printf("%d", res);
    return 0;
}

int ncr(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}