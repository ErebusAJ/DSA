#include <bits/stdc++.h>

using namespace std;

int ctr = 0;
void powerSet(int target, vector<int> &curr, int i, vector<int> nums, int sum)
{
    if (i == nums.size())
    {
        if (sum == target) ctr++;
        return;
    }

    curr.push_back(nums[i]);
    sum += nums[i];
    if(sum > target) return;
    powerSet(target, curr, i + 1, nums, sum);
    curr.pop_back();
    sum -= nums[i];
    powerSet(target, curr, i + 1, nums, sum);
}

int perfectSum(vector<int> &arr, int target)
{
    vector<int> curr;
    powerSet(target, curr, 0, arr, 0);

    return ctr;
}


int main(){
    vector<int> nums{5, 2, 3, 10 ,6, 8};
    cout << perfectSum(nums, 10);
}