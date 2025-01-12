# include<bits/stdc++.h>

using namespace std;

// int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int low = nums[0];
//         int high = nums[n - 1];
//         int ans = 0;
//         while(low <= high){
//             int mid = low + (high - low);
//             if(nums[mid] == mid) low = mid + 1;
//             else{
//                 ans = mid;
//                 high = mid - 1;
//             }
//             if(mid == n) return mid + 1;
//         }

//         return ans;
//     }

int missingNumber(vector<int>& nums){
        int xrn = 0;
        int xr = 0;
        int n = nums.size();
        if(n == 1){
            if(nums[0] == 1) return 0;
            return 1;
        }
        for(int i = 0; i < n; i++) 
            xr ^= nums[i];
        
        for(int i = 1; i <= n; i++) 
            xrn ^= i;

        if(xrn == xr) return n + 1;
        return xrn^xr; 
}

int main(){
    vector<int> nums{1,2};
    cout << missingNumber(nums);
}