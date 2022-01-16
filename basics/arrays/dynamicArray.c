#include <stdio.h>
#include <stdlib.h>
#include "../printArray.h"

int main()
{

    int *p, *q;

    p = (int *)malloc(4 * sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 8;
    p[3] = 4;

    printArray(p, 4);

    q = (int *)malloc(8 * sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;
    printArray(p, 8);

    return 0;
}