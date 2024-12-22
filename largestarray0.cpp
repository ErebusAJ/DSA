#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int> &nums)
{
    int maxi = 0, sum = 0;
    unordered_map<int, int> sumMap;
    for(int i = 1; i < nums.size(); i++){
        sum += nums[i];
        if(sum == 0){
            maxi = i + 1;
        }else{
            if(sumMap.find(sum) != sumMap.end()){
                maxi = max(maxi, i - sumMap[sum]);
            }else{
                sumMap[sum] = i;
            }
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums{-21, 6, 7, 22, 22, -29, 27, -42};
    cout << maxLen(nums);
}