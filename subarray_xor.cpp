#include <bits/stdc++.h>

using namespace std;

// int subarraysWithXOR(vector<int> &nums, int b) {
//     int ctr = 0, same = 0;
//     int xr = nums[0];
//     unordered_map<int, int> m{};
//     m.insert(make_pair(0, xr));
//     for(int i = 1; i < nums.size(); i++){
//         if(nums[i]== b) same++;
//         xr ^= nums[i];
//         if(m.find(xr) != m.end()) xr = 0;
//         m.insert(make_pair(i, xr));
//     }

//     for(auto pair : m){
//         if(pair.second == b) ctr++;
//     }
//     xr = 0;
//     unordered_map<int, int> m2{};
//     for(int i = nums.size() - 1; i >= 0; i--){
//         xr ^= nums[i];
//         if(m2.find(xr) != m2.end()) xr = 0;
//         m2.insert(make_pair(i, xr));
//     }
//     for(auto pair : m2){
//         if(pair.second == b) ctr++;
//     }
//     return ctr;
// }
int subarraysWithSumK(vector<int> a, int b)
{
    int ctr = 0, same = 0;
    int xr = 0;
    map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        xr ^= a[i];

        int x = xr^b;

        ctr += m[x];

        m[xr] = i; 
    }

    return ctr;
}

int main()
{
    vector<int> nums{1, 3, 3, 3, 5};

    cout << subarraysWithSumK(nums, 6);
}