#include <bits/stdc++.h>

using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    vector<int> result(2, 0);
    sort(arr.begin(), arr.end());
    int j = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != j)
        {
            if (arr[i] == arr[i - 1])
            {
                result[0] = arr[i];
            }
            result[1] = j;
        }
        j++;
    }
    return result;
}

int main()
{
    vector<int> nums{4,6,3,1,2,1};
    vector<int> result = findTwoElement(nums);
    int val = nums[0];
    for (int i = 1; i < nums.size(); i++){
        val ^= nums[i];
    }

    cout << val << endl;
}