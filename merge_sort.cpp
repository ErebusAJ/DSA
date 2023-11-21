#include <iostream>

using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len_l = mid - s + 1; // Length of left arr
    int len_r = e - mid;     // Length of right arr

    int *left = new int[len_l];
    int *right = new int[len_r];

    int arr_index = s;

    for (int i = 0; i < len_l; i++)
    {
        left[i] = arr[s++];
    }

    arr_index = mid + 1;
    for (int i = 0; i < len_r; i++)
    {
        right[i] = arr[s++];
    }

    int index1 = 0;
    int index2 = 0;
    arr_index = 0;

    while (index1 < len_l && index2 < len_r)
    {
        if (left[index1] < right[index2])
            arr[arr_index++] = left[index1++];
        else
            arr[arr_index++] = right[index2++];
    }

    while (index1 < len_l)
        arr[arr_index++] = left[index1++];

    while (index2 < len_r)
        arr[arr_index++] = right[index2++];
}

void merge_sort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    // Right part of sub array
    merge_sort(arr, mid + 1, e);
    // Left part of sub array
    merge_sort(arr, s, mid);

    merge(arr, s, e);
}

int main()
{
    int arr[5] = {15, 2, 12, 3, 85};
    int n = 5;

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}