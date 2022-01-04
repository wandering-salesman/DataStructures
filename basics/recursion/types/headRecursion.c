#include<stdio.h>

// Head recursion can be (relatively) easily converted into a loop
void fun(int n);

void main() {
    fun(5);
}

void fun(int n) {
    if(n>0) {
        fun(n-1);
        printf("%d ", n);
    }
}