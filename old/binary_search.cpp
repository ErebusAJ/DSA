#include <bits/stdc++.h>

using namespace std;

int binary_search(int arr[], int n, int key)
{

    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 32, 56, 73, 82, 91};
    // int n = sizeof(arr) / sizeof(int);

    int start = 0, end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    cout << mid;

    // int key;
    // cout << "Enter no: ";
    // cin >> key;

    // cout << binary_search(arr, n, key);
}