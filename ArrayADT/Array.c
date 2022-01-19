#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *x, int *y);
void display(struct Array arr);
void add(struct Array *arr, int x);
void insert(struct Array *arr, int index, int x);
int delete (struct Array *arr, int index);
int linearSearch(struct Array arr, int x);
int linearSearchImproved(struct Array *arr, int x);
int binarySearch(struct Array arr, int x);
int binarySearchRecursive(int arr[], int low, int high, int x);
int get(struct Array arr, int index);
void set(struct Array arr, int index, int x);
int max(struct Array arr);
int min(struct Array arr);
int sum(struct Array arr);
void reverse(struct Array arr);
void leftShift(struct Array arr);
void leftRotation(struct Array arr);
void rightShift(struct Array arr);
void rightRotation(struct Array arr);
void insertSort(struct Array *arr, int x); // Insert value in a sorted array
int isSorted(struct Array arr);
void rearrange(struct Array *arr); // separate negative elements and positive elements
struct Array *mergeArrays(struct Array *a, struct Array *b);
struct Array *unionArrays(struct Array *a, struct Array *b);
struct Array *intersectionArrays(struct Array *a, struct Array *b);
struct Array *differenceArrays(struct Array *a, struct Array *b);

int main()
{
    struct Array arr;
    int n;
    int key;
    int x, index;
    char ch;

    printf("Enter array size: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of values: ");
    scanf("%d", &n);

    // if (n <= arr.size)
    // {
    //     printf("Enter values: ");
    //     for (int i = 0; i < n; i++)
    //         scanf("%d", &arr.A[i]);
    //     arr.length = n;
    //     display(arr);
    // }
    // else
    // {
    //     printf("Size exceeded");
    // }

    do
    {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Add\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. LinearSearch\n");
        printf("6. Exit\n");

        printf("Select your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(arr);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &x);
            add(&arr, x);
            display(arr);
            break;

        case 3:
            printf("Enter index and value: ");
            scanf("%d %d", &index, &x);
            insert(&arr, index, x);
            display(arr);
            break;
        case 4:
            printf("Enter index: ");
            scanf("%d", &index);
            delete (&arr, index);
            display(arr);
            break;
        case 5:
            printf("Enter key: ");
            scanf("%d", &x);
            printf("\nKey found at: %d\n", linearSearch(arr, x));
            display(arr);
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (ch < 6);
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

int binarySearch(struct Array arr, int x)
{
    // Array must be sorted for this to work
    int low = 0;
    int high = arr.length;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr.A[mid] == x)
            return mid;
        else if (arr.A[mid] < x)
            low = mid;
        else if (arr.A[mid] > x)
            high = mid;
        return -1;
    }
}

int binarySearchRecursive(int arr[], int low, int high, int x)
{
    // recursive binary search
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (x == arr[mid])
            return mid;
        else if (x < arr[mid])
            return binarySearchRecursive(arr, low, mid - 1, x);
        else
            return binarySearchRecursive(arr, mid + 1, high, x);
    }
    return -1;
}

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array arr, int index, int x)
{
    if (index >= 0 && index < arr.length)
        arr.A[index] = x;
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
        if (max < arr.A[i])
            max = arr.A[i];
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
        if (min >= arr.A[i])
            min = arr.A[i];
    return min;
}

int sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

void reverse(struct Array arr)
{
    for (int i = 0; i < arr.length / 2; i++)
        swap(arr.A[i], arr.A[arr.length - 1]);
}

void leftShift(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
        arr.A[i] = arr.A[i + 1];
    arr.A[arr.length] = 0;
}

void leftRotation(struct Array arr)
{
    int temp = arr.A[0];
    for (int i = 0; i < arr.length - 1; i++)
        arr.A[i] = arr.A[i + 1];
    arr.A[arr.length] = temp;
}

void rightShift(struct Array arr)
{
    for (int i = arr.length; i > 0; i++)
        arr.A[i] = arr.A[i - 1];
    arr.A[0] = 0;
}

void rightRotation(struct Array arr)
{
    int temp = arr.A[arr.length];
    for (int i = arr.length; i > 0; i++)
        arr.A[i] = arr.A[i - 1];
    arr.A[0] = temp;
}

void insertSort(struct Array *arr, int x)
{
    if (arr->length == arr->size)
        return;

    int i = arr->length - 1;
    while (arr->A[i] > x && i >= 0)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    return 1;
}

void rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[i] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *mergeArrays(struct Array *a, struct Array *b)
{
    struct Array *res = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
            res->A[k++] = a->A[i++];
        else
            res->A[k++] = b->A[j++];
    }

    for (; i < a->length; i++)
        res->A[k++] = a->A[i];
    for (; j < b->length; j++)
        res->A[k++] = b->A[j];
    res->length = a->length + b->length;

    return res;
}

struct Array *unionArrays(struct Array *a, struct Array *b)
{
    struct Array *res = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
            res->A[k++] = a->A[i++];
        else if (b->A[j] < a->A[i])
            res->A[k++] = b->A[j++];
        else
            res->A[k++] = b->A[j];
    }

    for (; i < a->length; i++)
        res->A[k++] = a->A[i];
    for (; j < b->length; j++)
        res->A[k++] = b->A[j];
    res->length = k;
    res->size = k;
    return res;
}

struct Array *intersectionArrays(struct Array *a, struct Array *b)
{
    struct Array *res = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
            i++;
        else if (b->A[j] < a->A[i])
            j++;
        else if (a->A[i] == b->A[j])
        {
            res->A[k++] = a->A[i++];
            j++;
        }
    }

    res->length = k;
    res->size = k;
    return res;
}

struct Array *differenceArrays(struct Array *a, struct Array *b)
{
    struct Array *res = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
            res->A[k++] = a->A[i++];
        else if (b->A[j] < a->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < a->length; i++)
        res->A[k++] = a->A[i];

    res->length = k;
    res->size = k;
    return res;
}
