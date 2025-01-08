#include <bits/stdc++.h>

using namespace std;

int canSplit(vector<int> &nums, int threshold)
{
    int ctr = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((sum + nums[i]) <= threshold)
        {
            sum += nums[i];
        }
        else
        {
            ctr++;
            sum = nums[i];
        }
    }

    return ctr + 1;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0);

    if (k == 1)
        return high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int check = canSplit(nums, mid);

        if (check == k)
        {
            high = mid - 1;
        }
        else if (check > k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    // vector<int> nums{7, 2, 5, 10, 8};
    // int k = 2;

    vector<int> nums{1, 2, 3, 4, 5};
    int k = 2;

    cout << splitArray(nums, k) << endl;
}