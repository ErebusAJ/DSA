#include <bits/stdc++.h>

using namespace std;

vector<int> transformArray(vector<int>& nums) {
    int n = nums.size();
    
    for(int i = 0; i < nums.size(); i++){
        if(n & 1) nums[i] = 1;
        else nums[i] = 0;
    }
    
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    
    return nums;
}

int main(){
    vector<int> nums{4,3,2,1};
    for( auto i : transformArray(nums)){
        cout << i << " ";
    }
    
}