#include<stdio.h>
int fun(int n);

void main() {
    int r;
    r = fun(95);
    printf("%d\n", r);
}

int fun(int n) {
    if(n > 100) {
        return n-10;
    }
    return(fun(fun(n+11)));
}