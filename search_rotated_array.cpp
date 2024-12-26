#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int s1 = 0, e1 = -1, s2 = -1, e2 = n - 1;
    int j = 1;
    while (j < n)
    {
        if (nums[j - 1] < nums[j])
        {
            j++;
        }
        else
        {
            e1 = j - 1;
            s2 = j;
            break;
        }
    }
    if (e1 == -1)
    {
        e1 = e2;
        s2 = s1;
    }
    int mid = s1 + (e1 - s1) / 2;
    while (s1 <= e1)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            e1 = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s1 = mid + 1;
        }
        mid = s1 + (e1 - s1) / 2;
    }

    mid = s2 + (e2 - s2) / 2;
    while (s2 <= e2)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            e2 = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s2 = mid + 1;
        }
        mid = s2 + (e2 - s2) / 2;
    }

    return -1;
}

int main()
{
    vector<int> nums{1};
    cout << search(nums, 0);
}