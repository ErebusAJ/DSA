#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        int l = nums.size() - 1;
        int k = l - 1;
        while (j < l)
        {
            j = i + 1;
            k = l - 1;
            while (j < k)
            {
                try
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        j++;
                        k--;
                    }
                    else if (sum > target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
                catch (exception e)
                {
                    return {{0},{2}};
                }
            }
            l--;
        }
    }

    vector<vector<int>> result;
    for (vector i : s)
    {
        result.push_back(i);
    }
    return result;
}

int main()
{
    vector<int> nums{1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> result = fourSum(nums, 4);

    for (vector i : result)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}