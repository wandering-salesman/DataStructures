#include <iostream>
#include <vector>

using namespace std;

int oneMissing(int arr[]);
vector<int> multipleMissing(int arr[]);
void printVect(vector<int>);

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};  //one element missing
    int arr2[] = {1, 2, 3, 5, 6, 7, 9, 11, 12}; //mulitple elements missing
    cout << "\nOne element missing: " << oneMissing(arr1);
    cout << "\nMultiple element missing: ";
    printVect(multipleMissing(arr2));

    return 0;
}

int oneMissing(int arr[])
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int total = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum - total;
}

vector<int> multipleMissing(int arr[])
{
    int diff = arr[0] - 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res;
    for (int i = 0; i < n; i++)
        if (arr[i] - i != diff)
            while (diff < arr[i] - i)
                res.push_back(i+diff++);    
    return res;
}

void printVect(vector<int> vec) {
    for(auto i : vec) {
        cout << i << " first";
    }
}