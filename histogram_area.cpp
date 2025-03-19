#include <bits/stdc++.h>

using namespace std;
vector<int> prevSmallElem(vector<int> nums)
{
    stack<int> st;
    vector<int> result(nums.size(), -1);

    int i = 0;
    while (i < nums.size())
    {
        while (!st.empty() && nums[st.top()] > nums[i])
            st.pop();
        if (st.empty())
            result[i] = -1;
        else
            result[i] = st.top();
        st.push(i);
    }

    return result;
}

vector<int> nextSmallElem(vector<int> nums)
{
    stack<int> st;
    vector<int> result(nums.size(), -1);

    int i = nums.size() - 1;
    while (i >= 0)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
            st.pop();
        if (st.empty())
            result[i] = nums.size();
        else
            result[i] = st.top();
        st.push(i);
    }

    return result;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> pse = prevSmallElem(heights);
    vector<int> nse = nextSmallElem(heights);

    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int val = heights[i] * (nse[i] - pse[i] - 1);
        ans = max(ans, val);
    }

    return ans;
}

int main()
{
    vector<int> nums{2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(nums);
}