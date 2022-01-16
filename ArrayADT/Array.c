#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr);
void add(struct Array *arr, int x);
void insert(struct Array *arr, int index, int x);
int delete (struct Array *arr, int index);
int linearSearch(struct Array arr, int x);
int linearSearchImproved(struct Array *arr, int x);
int binarySearch(struct Array arr, int x);
int get(struct Array arr, int index);
void set(struct Array arr, int index, int x);
int max(struct Array arr);
int min(struct Array arr);
int reverse(struct Array arr);
void swap(int *x, int *y);

int main()
{
    struct Array arr;
    int n;
    int key;
    printf("Enter array size: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of values: ");
    scanf("%d", &n);

    if (n <= arr.size)
    {
        printf("Enter values: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr.A[i]);
        arr.length = n;
        display(arr);
    }
    else
    {
        printf("Size exceeded");
    }
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    printf("\n%d is at index %d", key, linearSearchImproved(&arr, key));
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(struct Array arr)
{
    printf("Elements are: \n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void add(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int delete (struct Array *arr, int index)
{
    int x;
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            x = arr->A[index];
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return -1;
}

int linearSearch(struct Array arr, int x)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (x == arr.A[i])
            return i;
    }
    return -1;
}

int linearSearchImproved(struct Array *arr, int x)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (x == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

// int binarySearch(struct Array arr, int x)
// {
// }

// int get(struct Array arr, int index)
// {
//     return arr.A[index];
// }

// void set(struct Array arr, int index, int x)
// {
//     arr.A[index] = x;
// }

// int max(struct Array arr)
// {
// }

// int min(struct Array arr)
// {
//     int min = arr.A[0];
//     for (int i = 0; i < arr.length; i++)
//         if (min >= arr.A[i])
//             min = arr.A[i];
//     return min;
// }

// int reverse(struct Array arr)
// {
// }