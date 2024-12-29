#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int mid = low + (high - low) / 2;
    if (nums.size() == 1)
    {
        return nums[0];
    }

    while (low <= high)
    {
        if (mid > 0 && nums[mid - 1] == nums[mid])
        {
            if ((mid - 1) % 2 != 0)
            {
                high = mid - 2;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (mid < nums.size() && nums[mid + 1] == nums[mid])
        {
            if (mid % 2 != 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            return nums[mid];
        }

        mid = low + (high - low) / 2;
    }

    return -1;
}

int main()
{
    vector<int> nums{3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(nums);
}