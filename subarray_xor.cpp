#include <bits/stdc++.h>

using namespace std;

int subarraysWithXOR(vector<int> &nums, int b) {
    int ctr = 0, same = 0;
    int xr = nums[0];
    unordered_map<int, int> m{};
    m.insert(make_pair(0, xr));
    for(int i = 1; i < nums.size(); i++){
        if(nums[i]== b) same++;
        xr ^= nums[i];
        if(m.find(xr) != m.end()) xr = 0; 
        m.insert(make_pair(i, xr));
    }

    for(auto pair : m){
        if(pair.second == b) ctr++;
    }
    ctr += same;

    return ctr;
}

int main()
{
    vector<int> nums{1, 3, 3, 3, 5};

    cout << subarraysWithXOR(nums, 6);
}