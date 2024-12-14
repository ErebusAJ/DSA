#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

long long findScore(vector<int> &nums)
{
    vector<int> check(nums.size(), 0);
    vector<int> nums2;
    long long score = 0;
    while (accumulate(check.begin(), check.end(), 0) != nums.size())
    {
        int minVal = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (check[i] == 0 && nums[i] < minVal)
            {
                minVal = nums[i];
                minIndex = i;
            }
        }
        score += minVal;

        check[minIndex] = 1;
        if (minIndex > 0)
            check[minIndex - 1] = 0;
        if (minIndex < nums.size() - 1)
            check[minIndex + 1] = 0;
    }

    return score;
}

int main()
{
    vector<int> check{2,1,3,4,5,2};
    cout << findScore(check);
}
