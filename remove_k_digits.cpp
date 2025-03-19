#include <bits/stdc++.h>

using namespace std;

string removeKdigits(string nums, int k)
{
    int n = nums.size();

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && k > 0 && ((st.top() - '0') > (nums[i] - '0')))
        {
            st.pop();
            k--;
        }
        st.push(nums[i]);
    }

    while (k != 0)
    {
        st.pop();
        k--;
    }

    if (st.empty())
        return "0";
    string s;

    while (!st.empty())
    {
        s.push_back(st.top());
        st.pop();
    }

    while (s.size() != 0 && s.back() == '0')
    {
        s.pop_back();
    }

    reverse(s.begin(), s.end());

    if (s.empty())
        return "0";
    return s;
}

int main()
{
    string nums = "1432219";

    cout << removeKdigits(nums, 3);
}