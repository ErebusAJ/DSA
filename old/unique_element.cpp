#include <iostream>
#include <algorithm>

using namespace std;

int find_unique(int arr[], int n)
{
    int ans = 0;
    // for (int i = 0; i < n; i++)    **THIS METHOD HAS TIME COMPLEXITY OF O(N^2) SO XOR IS BETTER
    // {
    //     for (int j = (i + 1); j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //             return arr[i];
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans ^= i;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << "Element: " << find_unique(arr, n);
}