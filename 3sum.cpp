#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
                j++;
        }
    }
    for (vector i : s)
    {
        result.push_back(i);
    }
    return result;
}

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    for (vector i : result)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}