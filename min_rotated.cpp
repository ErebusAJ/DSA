#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{
    int mini = INT_MAX;
    int low = 0, high = nums.size() - 1;

    int mid = low + (high - low)/2;

    while(low <= high){
        if(nums[low] <= nums[mid]){
            mini = min(nums[low], mini);
            low = mid + 1;
        }else{
            mini = min(nums[mid], mini);
            high = mid - 1;
        }
        mid = low + (high - low)/2;
    }

    return mini;
}

int main()
{
    vector<int> nums{3,1,2};
    cout << findMin(nums);
}