#include <stdio.h>
#include <stdlib.h>
#include "../printArray.h"


int main() {

    //size is decided at compile time
    //but in C++ it can be done on runtime as well
    //these are stored in stack
    int a[5];
    int b[5] = {2,4,6,8,1};
    int c[5] = {2,4}; //rest values are garbage
    int d[5] = {0}; //all elements become zeroes
    int e[] = {1,2,3,4,5,6,7}; //assigns size of 7 automatically

    printf("%d\n\n", a[0]);

    printArray(a,5);
    printArray(b,5);
    printArray(c,5);
    printArray(d,5);
    printArray(e,7);
    printf("\n");

    for(int i = 0; i < 5; i++) {
        printf("%u \n", &a[i]);
    }
    //values are accessed using the index values



    //create array on heap memory
    int *p;
    p = (int*) malloc(5*sizeof(int));
    //this can be done in C++ by using 'new' keyword
    //p = new int arr[n];
    

    // delete array using
    free(p);
    //or in c with 'delete' keyword as
    // delete []p // brackets come before it.
    
}