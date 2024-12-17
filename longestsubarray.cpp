#include <bits/stdc++.h>

using namespace std;

int lenOfLongestSubarr(vector<int> &arr, int k)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                int temp = j - i + 1;
                if (count < temp)
                {
                    count = temp;
                }
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums{94, -33, -13, 40, -82, 94, -33, -13, 40, -82};
    cout << lenOfLongestSubarr(nums, 52);

}