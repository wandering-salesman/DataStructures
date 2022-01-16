#include <stdio.h>

int fibonacci(int n);

int main() {
    int res = fibonacci(9);
    // 0, 1, 2, 3, 4, 5, 6, 7,  8,  9
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
    printf("%d", res);
    return 0;
}

// int fibonacci(int n) {
//     if(n <= 1) {
//         return n;
//     }
//     else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }