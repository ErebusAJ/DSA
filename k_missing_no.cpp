#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    int mid = low + (high - low) / 2;
    int miss = 0;

    while (low <= high)
    {
        int check = arr[mid] - (mid + 1);
        if (check == 0)
        {
            low = mid + 1;
            miss = arr[mid] + k;
        }
        else if (check < k)
        {
            miss = arr[mid] + (k - check);
            low = mid + 1;
        }
        else if (check >= k)
        {
            miss = arr[mid] - (check - k + 1);
            high = mid - 1;
        }

        mid = low + (high - low) / 2;
    }

    return miss;
}

int main()
{
    vector<int> nums{2};
    cout << findKthPositive(nums, 1);
}