#include <stdio.h>

int factorial(int n);

int main() {
    int res = factorial(5);
    printf("%d", res);
    return 0;
}

int factorial(int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return factorial(n-1)*n;
    }
}