#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &nums)
{
    vector<int> result;
    int i = nums.size() - 1;
    stack<int> st;
    while (i >= 0)
    {
        while (!st.empty() && abs(st.top()) < nums[i])
            st.pop();
        if (st.empty())
        {
            if (nums[i] > 0)
            {
                result.push_back(nums[i]);
                i--;
                continue;
            }
        }
        else
        {
            if (nums[i] > 0)
            {
                if (nums[i] > abs(st.top()))
                    result.push_back(nums[i]);
                else if (nums[i] == abs(st.top()))
                {
                    st.pop();
                    i--;
                    continue;
                }else{
                    i--;
                    cont
                }
            }
        }
        st.push(nums[i]);
        i--;
    }

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> nums{8, -8};

    for (auto i : asteroidCollision(nums))
        cout << i << " ";
}