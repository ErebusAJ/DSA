#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 1, j = nums.size() - 1;
    while (i >= 0 && nums[i - 1] > nums[i])
    {
        i--;
    }

    if (i > 0)
    {
        while (nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i - 1], nums[j]);
    }
    reverse(nums.begin() + i, nums.end());
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    nextPermutation(nums);
    for(int i : nums){
        cout << i << " ";
    }
}