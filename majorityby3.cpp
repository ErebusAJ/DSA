# include<bits/stdc++.h>

using namespace std;

vector<int> majorityElements(vector<int>& nums){
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        int count = 0;
        if(nums[i] == -1){
            continue;
        }
        for(int j = i; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if(count > nums.size()/3){
            result.push_back(nums[i]);
        }
        int val = nums[i];
        replace(nums.begin(), nums.end(), val, -1);
    }

    return result;
}

int main(){
    vector<int> nums{1,2,2,3,2};
    vector<int> result;
    result = majorityElements(nums);
    for(int i : result){
        cout << i << " ";
    }
}