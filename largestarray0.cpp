#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    int count = 0;
    while (i < j)
    {
        int sum = accumulate(arr.begin() + i, arr.begin() + j, 0);
        if (sum == 0)
        {
            count = j - i;
            break;
        }
        else if (sum > 0)
        {
            if (arr[i] > arr[j])
                i++;
            else
                j--;
        }
        else
        {
            if (arr[i] < arr[j])
                i++;
            else
                j--;
        }
    }
    return count;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    auto it = find(nums.begin(), nums.end(), 0);
    if (it == nums.end()){
        cout << 1;
    }
    // cout << val;
}