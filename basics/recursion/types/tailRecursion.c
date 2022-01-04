#include<stdio.h>

void fun(int n);

void main() {
    fun(5);
}

void fun(int n) {
    if(n>0) {
        printf("%d ", n);
        fun(n-1);
    }
}