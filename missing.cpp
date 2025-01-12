# include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = nums[0];
        int high = nums[n - 1];
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low);
            if(nums[mid] == mid) low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
            if(mid == n) return mid + 1;
        }

        return ans;
    }

int main(){
    vector<int> nums{0,1};
    cout << missingNumber(nums);
}