#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int s1 = 0, e1, s2, e2 = nums.size() - 1;
    int i = 1;
    while (i < nums.size())
    {
        if (nums[i - 1] > nums[i])
        {
            e1 = i - 1;
            s2 = i;
            break;
        }
        i++;
    }

    int mid = s1 + (e1 - s1) / 2;
    while (s1 <= e1)
    {
        if (nums[mid] == target)
        {
            return true;
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
            return true;
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

    return false;
}

int main(){
    vector<int> nums{1,1,1,1,1,1,1,1,1,2,1,1,1};
    cout << search(nums, 2);
}