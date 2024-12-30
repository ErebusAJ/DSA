#include <bits/stdc++.h>

using namespace std;

vector<int> findFloorCeil(int x, vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int mid = low + (high - low) / 2;
    int floor = -1, ceil = -1;

    if (arr.size() == 0 && x == arr[0])
        return {-1, -1};

    sort(arr.begin(), arr.end());

    while (low <= high)
    {
        if (arr[mid] == x)
        {
            return {arr[mid], arr[mid]};
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }

        mid = low + (high - low) / 2;
    }

    if (mid == arr.size())
    {
        return {arr[mid - 1], -1};
    }
    else if (mid == 0)
    {
        return {-1, arr[mid]};
    }
    else
    {
        return {arr[mid - 1], arr[mid]};
    }

    return {-1, -1};
}

int main()
{
    vector<int> nums{15, 28};
    vector<int> result = findFloorCeil(37, nums);

    for (int i : result)
    {
        cout << i << " ";
    }
}