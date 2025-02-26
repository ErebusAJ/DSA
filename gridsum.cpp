#include <bits/stdc++.h>

using namespace std;

long long result = INT_MIN;

void solver(vector<vector<int>> &grid, vector<int> limits, vector<int> curr, int index, int k)
{
    if (index >= grid.size())
    {
        long long maxSum = accumulate(curr.begin(), curr.end(), 0);
        if (maxSum > result)
            result = maxSum;
        return;
    }

    solver(grid, limits, curr, index + 1, k);

    for (int j = 0; j < grid[0].size(); j++)
    {
        int c = curr.size();
        if (c <= limits[index] && curr.size() <= k)
        {
            curr.push_back(grid[index][j]);
            c++;
            solver(grid, limits, curr, index + 1, k--);
        }
    }
}

long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k)
{
    for(int i = 0; i < grid.size(); i++){
        sort(grid[i].begin(), grid[i].end());
        reverse(grid[i].begin(), grid[i].end());
    }

    vector<int> curr;
    solver(grid, limits, curr, 0, k);

    return result;
}

int main()
{
    vector<vector<int>> grid{{5, 3, 7}, {8, 2, 6}};
    vector<int> limits{2, 2};

    cout << maxSum(grid, limits, 3);
}