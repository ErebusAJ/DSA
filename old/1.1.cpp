#include <iostream>
using namespace std;

void insert(int arr[], int &size, int key, int pos)
{
    for (int i = size; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = key;
    size++;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void deletion(int arr[], int &size, int pos)
{
    arr[pos] = arr[pos + 1];
    for (int i = pos + 1; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main()
{
    int arr[10] = {1, 32, 42, 52, 3};
    int size = 5;
    insert(arr, size, 30, 2);
    display(arr, size);
    deletion(arr, size, 1);
    display(arr, size);

    return 0;
}