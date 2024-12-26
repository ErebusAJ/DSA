#include <bits/stdc++.h>

using namespace std;

int reversePairs(vector<int> &nums)
{
    int count = 0;
    for (int j = nums.size() - 1; j >= 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            long double val = 2 * static_cast<long long>(nums[j]);
            if (nums[i] > val)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    cout << reversePairs(nums);
}