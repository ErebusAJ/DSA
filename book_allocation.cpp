#include <bits/stdc++.h>

using namespace std;

int countStudents(vector<int> &nums, int pages)
{
    int studentCtr = 1;
    long long studentPages = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((studentPages + nums[i]) <= pages)
        {
            studentPages += nums[i];
        }
        else
        {
            studentCtr++;
            studentPages = nums[i];
        }
    }

    return studentCtr;
}

int findPages(vector<int> &nums, int n, int m)
{
    if(m > n) return -1;

    int low = *max_element(nums.begin(), nums.end());

    if (n == m)
        return low;

    long long high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int check = countStudents(nums, mid);
        if (check > m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    // vector<int> nums{12, 34, 67, 90};
    // int n = 4, m = 2;

    // vector<int> nums{25,46,28,49,24};
    // int n = 5, m = 4;

    vector<int> nums{8, 15, 3};
    int n = 3, m = 2;

    cout << findPages(nums, n, m) << endl;
}