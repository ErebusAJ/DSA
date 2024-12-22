#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = nums.size() - 1; j > i; j--)
        {
            int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
            if (sum == 0)
            {
                if (count < (j - i))
                {
                    count = j - i;
                }
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums{-21, 6, 7, 22, 22, -29, 27, -42};
    cout << maxLen(nums);
}