#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int lo = 0, hi = n - 1;

    int mid = lo + (hi - lo) / 2;

    while (lo <= hi)
    {
        if (nums[mid] == target)
            return mid;

        if (nums[lo] <= nums[mid])
        {
            if (nums[lo] <= target && nums[mid] >= target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[hi] >= target)
            {
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        mid = lo + (hi - lo) / 2;
    }

    return -1;
}

int main()
{
    vector<int> nums{1};
    cout << search(nums, 0);
}