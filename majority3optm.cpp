# include<bits/stdc++.h>

using namespace std;

vector<int> majorityElements(vector<int>& nums){
    int candidate1 = 0, candidate2 = 0, current = 0;
    int count1 = 0, count2 = 0;
    int i = 0;
    while(i < nums.size()){
        if(count1 == 0 && nums[i] != candidate2){
            count1 = 1;
            candidate1 = nums[i];
        }
        if(count2 == 0 && nums[i] != candidate1){
            count2 = 1;
            candidate2 = nums[i];
        }else if(nums[i] == candidate1){
            count1++;
        }else if(nums[i] == candidate2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
        i++;
    }

    vector<int> result;
    int threshold = nums.size()/3;
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == candidate1){
            count1++;
        }else if(nums[i] == candidate2){
            count2++;
        }
    }

    if(count1 > threshold)
        result.push_back(candidate1);
    if(count2 > threshold)
        result.push_back(candidate2);

    return result;
}

int main(){
    vector<int> nums{1, 2};
    vector<int> result;
    result = majorityElements(nums);
    for(int i : result){
        cout << i << " ";
    }
}