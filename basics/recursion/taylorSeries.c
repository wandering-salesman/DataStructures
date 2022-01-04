#include <stdio.h>

double e(int x, int n);

int main() {
    printf("%lf\n", e(1, 10));
    return 0;
}

// double e(int x, int n) {
//     static double p = 1;
//     static double f = 1;
//     double r;

//     if(n == 0) {
//         return 1;
//     }
//     r = e(x, n-1);
//     p = p*x;
//     f = f*n;
//     return r + p/f;
// }


// more efficient method to do so:
//
// double e(int x, int n) {
//     static double s = 1;
//     if(n == 0) {
//         return s;
//     }
//     s = 1 + x * s/n;
//     return e(x, n-1);
// }