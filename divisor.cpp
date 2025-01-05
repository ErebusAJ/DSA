#include <bits/stdc++.h>

using namespace std;

// int smallestDivisor(vector<int> &nums, int threshold){
    // int i = 1;
    // while(true){   
        // int ans = 0; 
        // for(int j = 0; j < nums.size(); j++){
            // ans += ceil(float(nums[j]) / float(i));
        // }
        // if(ans <= threshold){
            // return i;
        // }
        // i++;
    // }
// }

int smallestDivisor(vector<int> &nums, int threshold){
    int i = 0;
    auto it = *max_element(nums.begin(), nums.end());
    int low = 1;
    int divisor = INT_MAX;
    while(low <= it){
        int mid = low + (it - low)/2;
        int ans = 0;
        for(int j = 0; j < nums.size(); j++){
            ans += ceil(float(nums[j]) / float(mid));
        }
        if(ans <= threshold){
            divisor = min(divisor,mid);
            it = mid - 1;
        }else if(ans > threshold){
            low = mid + 1;
        }
    }

    return divisor;
}

int main()
{
    vector<int> nums{20};
    cout << smallestDivisor(nums, 1);
}