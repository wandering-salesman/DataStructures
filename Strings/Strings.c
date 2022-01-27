#include <stdio.h>

int lengthOf(char *str);
void toUpper(char *str);
void toLower(char *str);
void toggleCase(char *str);
void reverseString(char *str);

int main()
{
    char str[32];
    printf("Enter a string: ");
    gets(str);
    printf("\nEntered string is: %s", str);

    reverseString(str);
    printf("\nreversed: %s", str);
}

int lengthOf(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
}

void toLower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
}

void toggleCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
        else if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
    }
}

void reverseString(char *str)
{
    int len, i;
    char *start, *end, temp;
    len = lengthOf(str);
    start = str;
    end = str;
    for (i = 0; i < len - 1; i++)
        end++;
    for (i = 0; i < len / 2; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
}
