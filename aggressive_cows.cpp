#include <bits/stdc++.h>

using namespace std;

bool checkStalls(vector<int> &stalls, int k, int d)
{
    int count = 1;
    int n = stalls.size();
    int last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= d)
        {
            count++;
            last = stalls[i];
        }
        if (count >= k)
            return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (checkStalls(stalls, k, mid)) low = mid + 1;
        else high = mid - 1;
    }

    return high;
}

int main()
{
    // vector<int> nums{1,2,8,4,9};
    // int k = 3;

    // vector<int> nums{0,3,4,7,10,9};
    // int k = 4;

    vector<int> nums{4,2,1,3,6};
    int k = 2;

    // vector<int> nums{18, 27, 44, 77, 69, 19, 35, 83, 9, 64};
    // int k = 4;
    cout << aggressiveCows(nums, k);
}