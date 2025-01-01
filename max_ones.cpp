#include <bits/stdc++.h>

using namespace std;

int rowWithMax1s(vector<vector<int>> &nums)
{
    int rowSize = nums[0].size();
    int l = 0, h = rowSize - 1;
    int mid;
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        int firstIndex = rowSize, count = 0;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (nums[i][mid] == 1)
            {
                firstIndex = mid;
                h = mid - 1;
            }
            else if (nums[i][mid] < 1)
            {
                l = mid + 1;
            }
        }
        l = 0;
        h = rowSize - 1;
        count = rowSize - firstIndex;
        m.insert(make_pair(i, count));
    }
    int maxVal = INT_MIN;
    for (auto &pair : m)
    {
        maxVal = max(maxVal, pair.second);
    }
    int row = -1;
    for (auto &pair : m)
    {
        if (pair.second == maxVal)
        {
            row = pair.first;
            break;
        }
    }

    return row;
}

int main()
{
    vector<vector<int>> nums{{0, 0, 0, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1, 1}};
    cout << rowWithMax1s(nums);
}