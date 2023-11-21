#include <iostream>

using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (key < arr[j])
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {1, 21, 12, 31, 43};
    int n = sizeof(arr) / sizeof(n);
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}