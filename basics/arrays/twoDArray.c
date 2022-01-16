#include <stdio.h>
#include <stdlib.h>
#include "../printArray.h"

int main()
{

    int a[3][2] = {{1, 3}, {2, 4}, {5, 6}};
    //assigned as single dimension array
    //which we can access as a 2d array
    /*
    
        in memory as
        [][][][][][][]
        but shown as
        [][]
        [][]
        [][]
    
    */

    int *b[3];
    int **c;

    b[0] = (int *)malloc(4 * sizeof(int));
    b[1] = (int *)malloc(4 * sizeof(int));
    b[2] = (int *)malloc(4 * sizeof(int));

    c = (int **)malloc(4 * sizeof(int *));
    c[0] = (int *)malloc(5 * sizeof(int));
    c[1] = (int *)malloc(5 * sizeof(int));
    c[2] = (int *)malloc(5 * sizeof(int));
    c[3] = (int *)malloc(5 * sizeof(int));

    printf("#2D arrays:\n\n");
    printf("Array A[3][2], completely on stack:\n");
    print2DArray(3, 2, a);
    printf("\n");

    printf("Array B[2][3], rows on stack, columns on heap:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Array C[3][4], completely on heap:\n");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}