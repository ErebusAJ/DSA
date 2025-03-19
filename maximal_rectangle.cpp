#include <bits/stdc++.h>

using namespace std;

int rectArea(vector<int> nums)
{
    stack<int> st;
    int maxi = INT_MIN;
    int n = nums.size();
    int i = 0;

    while (i < n)
    {
        while (!st.empty() && nums[i] < nums[st.top()])
        {
            int elem = nums[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, (elem * (i - pse - 1)));
        }
        st.push(i);
        i++;
    }

    while (!st.empty())
    {
        int elem = nums[st.top()];
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxi = max(maxi, (elem * (n - pse - 1)));
    }

    return maxi;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> prefix(row, vector<int>(col, 0));

    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        sum = 0;
        for (int j = 0; j < row; j++)
        {
            if (j == row - 1 && matrix[j][i] == '0')
                continue;
            if (matrix[j][i] == '1')
            {
                sum += 1;
                prefix[j][i] = sum;
            }
            else
                prefix[j][i] = sum;
        }
    }

    for (auto i : prefix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    int ans = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        ans = max(ans, rectArea(prefix[i]));
    }

    return ans;
}

int main()
{
    vector<vector<char>> nums{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(nums);
}