#include <bits/stdc++.h>

using namespace std;

int equillibrium(vector<int> &nums)
{
    int size = nums.size();
    int count = 0;
    vector<int> prefix1(nums.size(), 0);
    vector<int> prefix2(nums.size(), 0);
    prefix1[0] = nums[0];
    prefix2[size-1] = nums[size-1];
    for(int i = 1; i < size; i++){
        prefix1[i] = prefix1[i-1] + nums[i];
    }
    for(int i = size - 2; i >= 0; i--){
        prefix2[i] = prefix2[i+1] + nums[i];
    }
    for(int i = 0; i < nums.size(); i++){
        if(prefix1[i] == prefix2[i]){
            count = i;
        }
    }

    return count;
}

int main()
{
    vector<int> nums{25, 10, 7, 8, 40, 2} ;
    // vector<int> prefix(nums.size(), 0);

    cout << equillibrium(nums);
}