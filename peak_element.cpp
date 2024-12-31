#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (mid == 0)
        {
            if (nums[mid] < nums[mid + 1]) return mid + 1;
            else return mid;
            break;
        }
        else if (mid == n - 1)
        {
            if (nums[mid] > nums[mid - 1])
                return mid;
            break;
        }
        else if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
        else if(nums[mid - 1] > nums[mid]) high = mid - 1;
        else if(nums[mid] < nums[mid + 1]) low = mid + 1;

        mid = low + (high - low) / 2;
    }

    return -1;
}

int main()
{
    vector<int> nums{2, 1};
    cout << findPeakElement(nums);
}