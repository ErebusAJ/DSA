# include<bits/stdc++.h>

using namespace std;

int findKRotation(vector<int> &nums){
    int low = 0, high = nums.size() - 1;
    int mid = low + (high - low)/2;
    if(nums.size() == 1) return 0;
    while(low <= high){
        if(mid == nums.size() - 1) return 0;
        if(nums[mid] > nums[mid + 1]) return mid + 1;
        else if(nums[mid] >= nums[low]) low = mid + 1;
        else if(nums[mid] < nums[high]) high = mid - 1;

        mid = low + (high - low)/2;
    }

    return 0;
}

int main(){
    // vector<int> nums{8, 10, 21, 31, 43, 45};
    vector<int> nums{38, 40, 43, 44, 4, 9, 12, 21, 32, 34};
    cout << findKRotation(nums);
}