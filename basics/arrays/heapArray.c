#include <stdio.h>
#include <stdlib.h>
#include "../printArray.h"


int main() {
    int a[5] = {2,4,6,8,10};

    int *p;
    p = (int *)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 4;
    p[2] = 8;
    p[3] = 5;
    p[4] = 9;

    printArray(a, 5);
    printArray(p, 5);
}