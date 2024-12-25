#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int firstIndex = -1, lastIndex = -1;
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            lastIndex = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target){
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }

    start = 0;
    end = lastIndex;
    mid = start + (end - start)/2;
    
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            firstIndex = mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target){
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return {firstIndex, lastIndex};
}

int main()
{
    vector<int> nums{5, 7, 7, 7, 8, 8, 10};
    vector<int> result = searchRange(nums, 7);

    for(int i : result){
        cout << i << " ";
    }

}