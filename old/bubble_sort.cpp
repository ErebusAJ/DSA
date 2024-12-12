#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n)
{
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                c++;
            }
        }
    }
    cout << c << endl;
}

int main()
{
    int arr[] = {8, 22, 7, 9, 31, 5, 13};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
