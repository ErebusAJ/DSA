#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
        int i = 0, count = 1;
        int j = 1;
        while(j < nums.size()){
            if(nums[i] == nums[j] || nums[i] > nums[j]){
                j++;
            }else{
                swap(nums[i+1], nums[j]);
                i++;
                count++;
            }
        }
        return count;
    }

int main()
{
    vector<int> arr{1,2,3,4,0,0,0};
    cout << count(arr.begin(), arr.end(), 0);
}