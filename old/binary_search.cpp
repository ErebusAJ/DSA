#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int key)
{

    int start = 0;
    int end = arr.size() - 1;
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
    vector<int> arr{1};
    // int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter no: ";
    cin >> key;

    cout << binary_search(arr, key);
}