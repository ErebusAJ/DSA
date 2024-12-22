# include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums{1,2,5,10,20,5};
    vector<int> prefix;
    prefix.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        int val = prefix[i-1] + nums[i];
        prefix.push_back(val);
    }

    for(int i : prefix){
        cout << i << " ";
    }

}