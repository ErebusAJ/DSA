# include<bits/stdc++.h>

using namespace std;


vector<int> findTwoElement(vector<int> nums){
    int n = nums.size();
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr ^= nums[i];
        xr ^= (i + 1);
    }

    //Differentiating bit
    int bitN = 0;
    while(1){
        if((xr & (1 << bitN)) != 0){
            break;
        }else{
            bitN++;
        }
    }

    //Group array in 1's & 0's
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++){
        if((nums[i] & (1<<bitN)) != 0){
            ones = ones ^ nums[i];
        }else{
            zeros = zeros ^ nums[i];
        }
    }

    for(int i = 1; i <= n; i++){
        if((i & (1<<bitN)) != 0){
            ones = ones ^ i;
        }else{
            zeros = zeros ^ i;
        }
    }

    //Traverse array
    int count = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == zeros){
            count++;
        }
    }

    if(count == 2) return{zeros, ones};
    return {ones, zeros};
}


int main(){
    vector<int> nums{4, 3, 6, 2, 1, 1};
    vector<int> result = findTwoElement(nums);

    for(int i : result){
        cout << i << " ";
    }
}