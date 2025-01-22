# include<bits/stdc++.h>

using namespace std;



int main(){
    vector<pair<int, int>> nums;
    nums.push_back({1,2});

    for(auto i : nums){
        cout << i.first << " " << i.second;
    }
}