#include <iostream>

using namespace std;

void max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << "Max value: " << max << endl;
}

void min(int arr[], int n)
{
    int mini = INT8_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        // if (arr[i] < mini)
        //     mini = arr[i];
    }
    cout << "mini value: " << mini << endl;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {1, 53, 89, 34, 67, 39, 54, 80};
    int n = sizeof(arr) / sizeof(int);
    int start = 0;
    int end = 1;

    for (int i = 0; i < n / 2; i++) // Swaping alternate elements
    {
        if (n % 2 == 0)
        {
            swap(arr[start], arr[end]);
            start += 2;
            end += 2;
        }
        else
        {
            if (arr[-1])
            {
                break;
            }
            else
            {
                swap(arr[start], arr[end]);
                start += 2;
                end += 2;
            }
        }
    }

    print_array(arr, n);
}