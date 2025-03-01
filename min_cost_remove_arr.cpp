# include<bits/stdc++.h>

using namespace std;

void solver(int &result, vector<int> nums, int ind, int n, int cost){
    if(n <= 0){
        if(result > cost) result = cost;
        return;
    }
    

    // for(int i = 0, j = 0; i < 3; j++){
    //     while(nums[ind] == 0 || nums[j] == 0){
    //         if(nums[ind] == 0) ind++;
    //         if(nums[j] == 0) j++;
    //     } 
    //         int a = nums[ind];
    //         int b = nums[j];
    //         nums[ind] = 0;
    //         nums[j] = 0;
    //         solver(result, nums, ind + 1, n-2, cost += max(a,b));
    //         nums[ind] = a;
    //         nums[j] = b;
    //         i++;
    // }

    for(int i = 0, j = 0; i < 3; j++){
        
    }
    
}

int minCost(vector<int>& nums){
    int n = nums.size();
    int result = INT_MAX;

    solver(result, nums, 0, n, 0);

    return result;
}

int main(){
    vector<int> nums{6, 2, 8, 4};

    cout << minCost(nums);
}