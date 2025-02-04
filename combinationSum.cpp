#include <bits/stdc++.h>

using namespace std;

void combCheck(vector<vector<int>> &result, vector<int> &curr, int i, int sum, vector<int> &nums, int target)
{
    if (sum == target)
    {
        result.push_back(curr);
        return;
    }
    if (sum > target)
        return;
    if (i == nums.size())
        i = 0;
    curr.push_back(nums[i]);
    sum += nums[i];

    combCheck(result, curr, i + 1, sum, nums, target);
    curr.pop_back();
    sum -= nums[i];

    combCheck(result, curr, i + 1, sum, nums, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> curr;

    combCheck(result, curr, 0, 0, candidates, target);

    return result;
}

int main()
{
    vector<int> nums{2, 3, 6, 7};
    vector<vector <int>> result = combinationSum(nums, 7);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}