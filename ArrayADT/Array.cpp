#include <iostream>
#include <stdlib.h>

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int &x, int &y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void display();
    void add(int x);
    void insert(int index, int x);
    int deleteElement(int index);
    int linearSearch(int key);
    int linearSearchImproved(int key);
    int binarySearch(int key);
    int binarySearchRecursive(int arr[], int low, int high, int key);
    int get(int index);
    void set(int index, int x);
    int max();
    int min();
    int sum();
    void reverse();
    void leftShift();
    void leftRotation();
    void rightShift();
    void rightRotation();
    void insertSort(int x); // Insert value in a sorted array
    bool isSorted();
    void rearrange(); // separate negative elements and positive elements
    Array *mergeArrays(Array b);
};

int main()
{
    Array arr;
    Array brr;
    arr.add(1);
    arr.add(2);
    arr.add(3);
    // brr.add(1);
    brr.add(2);
    brr.add(3);
    brr.add(4);
    brr.add(5);
    std::cout << "\nmerged a & b: ";
    arr.mergeArrays(brr);
    return 0;
}

void Array::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void Array::display()
{
    for (int i = 0; i < length; i++)
        std::cout << A[i] << " ";
    std::cout << '\n';
}

void Array::add(int x)
{
    if (length < size)
    {
        A[length] = x;
        length++;
    }
    else
        std::cout << "\nSize exceeded\n";
    display();
}

void Array::insert(int index, int x)
{
    if (length < size && index >= 0 && index <= size)
    {
        for (int i = length; i >= index; i--)
            A[i + 1] = A[i];
        length++;
        A[index] = x;
    }
    else
        std::cout << "\nSize exceeded\n";
    display();
}

int Array::deleteElement(int index)
{
    int x = A[index];
    for (int i = index; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    length--;
    display();
    return x;
}

int Array::linearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
            return i;
    }
    return -1;
}

int Array::linearSearchImproved(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(A[i], A[0]);
            return i;
        }
    }
    return -1;
}

int Array::binarySearch(int key)
{
    // Array must be sorted
    // check if sorted
    if (isSorted())
    {
        int low = 0;
        int high = length;
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (key == A[mid])
            {
                return mid;
            }
            else if (key > mid)
                low = mid;
            else
                high = mid;
        }
        return -1;
    }
    std::cout << "\nArray is not sorted\n";
    return -1;
}

int Array::binarySearchRecursive(int arr[], int low, int high, int x)
{
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

int Array::get(int index)
{
    if (0 <= index && index <= length)
        return A[index];
    else
        std::cout << "\nInvalid index\n";
    return -1;
}

void Array::set(int index, int x)
{
    if (0 <= index && index <= length)
        A[index] = x;
    else
        std::cout << "\nInvalid index\n";
    display();
}

int Array::max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
        if (max < A[i])
            max = A[i];
    return max;
}

int Array::min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
        if (min > A[i])
            min = A[i];
    return min;
}

int Array::sum()
{
    int s = 0;
    for (int i = 0; i < length; i++)
        s += A[i];
    return s;
}

void Array::reverse()
{
    for (int i = 0; i < length / 2; i++)
        swap(A[i], A[length - 1]);
    display();
}

void Array::leftShift()
{
    for (int i = 0; i < length - 1; i++)
        A[i] = A[i + 1];
    A[length - 1] = 0;
}

void Array::leftRotation()
{
    int temp = A[0];
    for (int i = 0; i < length - 1; i++)
        A[i] = A[i + 1];
    A[length - 1] = temp;
}

void Array::rightShift()
{
    if (length < size)
        for (int i = length; i > 0; i--)
            A[i] = A[i - 1];
    A[0] = 0;
}

void Array::rightRotation()
{
    int temp = A[length - 1];
    if (length < size)
        for (int i = length; i > 0; i--)
            A[i] = A[i - 1];
    A[0] = temp;
}

void Array::insertSort(int x)
{
    // Insert value in a sorted array
    if (length < size)
    {
        int i = length - 1;
        while (A[i] > x && i >= 0)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
    else
        std::cout << "\nSize exceeded\n";
    display();
}

bool Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

void Array::rearrange()
{
    // separate negative elements and positive elements
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(A[i], A[j]);
    }
    display();
}

Array *Array::mergeArrays(Array b)
{
    Array *res = new Array();
    res->size = size + b.size;
    res->length = length + b.length;
    int i, j, k;
    i = j = k = 0;

    while (i < length && j < b.length)
    {
        if (A[i] < b.A[j])
            res->A[k++] = A[i++];
        else
            res->A[k++] = b.A[j++];
    }

    for (; i < length; i++)
        res->A[k++] = A[i];
    for (; j < b.length; j++)
        res->A[k++] = b.A[j];
    res->display();
    return res;
}