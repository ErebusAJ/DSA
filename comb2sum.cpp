#include <bits/stdc++.h>

using namespace std;

void combCheck(set<vector<int>> &result, vector<int> &curr, int i, vector<int> &nums, int target)
{
    if (i == nums.size())
    {
        if (target == 0)
        {
            vector
            sort(curr.begin(), curr.end());
            result.insert(curr);
            return;
        }
        else
            return;
    }

    if (nums[i] <= target)
    {
        curr.push_back(nums[i]);
        combCheck(result, curr, i + 1, nums, target - nums[i]);
        curr.pop_back();
    }

    combCheck(result, curr, i + 1, nums, target);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    set<vector<int>> temp;
    vector<int> curr;
    vector<vector<int>> result;

    combCheck(temp, curr, 0, candidates, target);

    for (auto i : temp)
    {
        result.push_back(i);
    }

    return result;
}

int main()
{
    vector<int> nums{2, 5, 2, 1, 2};
    vector<vector <int>> result = combinationSum2(nums, 5);

    for(auto i : result){
        cout << "[ ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << "]" << endl;
    }
}