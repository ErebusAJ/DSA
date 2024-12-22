#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    int j = 1;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (result[j - 1][1] >= intervals[i][0])
        {
            result[j - 1][1] = max(intervals[i][1], result[j - 1][1]);
        }
        else
        {
            result.push_back(intervals[i]);
            j++;
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> nums{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result;
    result = merge(nums);

    for (vector i : result)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
    }
}