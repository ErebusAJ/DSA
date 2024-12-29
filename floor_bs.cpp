#include <bits/stdc++.h>

using namespace std;

int findFloor(vector<int> &arr, int k)
{

    int low = 0, high = arr.size() - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {

        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }

    return mid - 1;
}
int main()
{
    vector<int> nums{1, 2, 8, 10, 11, 12, 19};

    cout << findFloor(nums, 5);
}