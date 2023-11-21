#include <iostream>

using namespace std;

int check_occurence(int arr[], int n, int key)
{
    int first = -1;
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            first = mid;
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return first;
}

int left_occr(int arr[], int n, int key)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 5, 6, 6, 6, 9};
    int n = sizeof(arr) + sizeof(int);
    int key;
    cout << "Key";
    cin >> key;
    cout << "First: " << check_occurence(arr, n, key) << endl
         << "Last occur: " << left_occr(arr, n, key);
}
