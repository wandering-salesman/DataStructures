#include <stdio.h>

int main() {

    char a[5];
    char b[5] = {'L', 'a', 'm', 'a', 'r', '\0'};
    char c[5] = {'h', 'i', '\0'}; //rest values are garbage
    char e[] = {'L', 'a', 'm', 'a', 'r', '\0'}; //assigns size of 6 automatically

    char *f = "Lamar"; // creates on heap, and RHS adds '\0' automatically
    
    printf("%s", b); //print using printf
    scanf("%s", a); //scans and adds '\0' automatically, but can only read until spaces

    // To read until enter is pressed we use gets()
    gets(a);
}