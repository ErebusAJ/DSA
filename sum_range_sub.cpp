#include <bits/stdc++.h>

using namespace std;

vector<int> nextSmallElem(vector<int> nums)
{
    vector<int> result(nums.size(), 0);
    stack<int> st;

    int i = nums.size() - 1;
    while (i >= 0)
    {
        while (!st.empty() && nums[i] <= nums[st.top()])
            st.pop();
        result[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
        i--;
    }

    return result;
}

vector<int> nextGreatElem(vector<int> nums)
{
    vector<int> result(nums.size(), 0);
    stack<int> st;

    int i = nums.size() - 1;
    while (i >= 0)
    {
        while (!st.empty() && nums[i] >= nums[st.top()])
            st.pop();
        result[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
        i--;
    }

    return result;
}

vector<int> prevSmallElem(vector<int> nums)
{
    vector<int> result(nums.size(), 0);
    stack<int> st;

    int i = 0;
    while (i < nums.size())
    {
        while (!st.empty() && nums[i] < nums[st.top()])
            st.pop();
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
        i++;
    }

    return result;
}

vector<int> prevGreatElem(vector<int> nums)
{
    vector<int> result(nums.size(), 0);
    stack<int> st;

    int i = 0;
    while (i < nums.size())
    {
        while (!st.empty() && nums[i] > nums[st.top()])
            st.pop();
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
        i++;
    }

    return result;
}

long long subArrayRanges(vector<int> &nums)
{
    vector<int> nse = nextSmallElem(nums);
    vector<int> pse = prevSmallElem(nums);
    vector<int> nge = nextGreatElem(nums);
    vector<int> pge = prevGreatElem(nums);

    long long ssum = 0, lsum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int sleft = i - pse[i];
        int sright = nse[i] - i;
        ssum = (ssum + (1LL * sleft * sright * nums[i]));

        int lleft = i - pge[i];
        int lright = nge[i] - i;
        lsum = (lsum + (1LL * lleft * lright * nums[i]));
    }

    return lsum - ssum;
}

int main() {
    vector<int> nums{1, 3, 3};
    cout << subArrayRanges(nums);
}