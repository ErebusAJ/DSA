#include <iostream>

using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // j = i + 1 as we already considered i as smallest
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[] = {121, 12, 23, 124, 53, 75};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}