#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return mid;
}

int main()
{
    vector<int> nums{1,3, 5, 6,5,6};
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    cout << mid << endl;
    cout << searchInsert(nums, 5);
}