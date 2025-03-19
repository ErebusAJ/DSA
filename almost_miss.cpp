#include <bits/stdc++.h>

using namespace std;

// int largestInteger(vector<int> &nums, int k)
// {
//     unordered_map<int, int> checks;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i + k <= nums.size())
//         {
//             for (int j = i; j < i + k; j++)
//             {
//                 if (j >= nums.size())
//                     break;
//                 checks[nums[j]]++;
//             }
//         }
//     }

//     int maxMiss = -1;
//     for (auto p : checks)
//     {
//         if (p.second == 1)
//             maxMiss = max(maxMiss, p.first);
//     }

//     return maxMiss;
// }

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int findLargestAlmostMissingInteger(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return -1;

    std::unordered_map<int, std::unordered_set<int>> numToSubarrays;
    
    for (int i = 0; i <= n - k; i++) {
        std::unordered_set<int> currentSubarray;
        for (int j = i; j < i + k; j++) {
            currentSubarray.insert(nums[j]);
        }
        
        for (int num : currentSubarray) {
            numToSubarrays[num].insert(i);
        }
    }
    
    int largestAlmostMissing = -1;
    
    for (const auto& pair : numToSubarrays) {
        int num = pair.first;
        const auto& subarrays = pair.second;
        
        if (subarrays.size() == 1) {
            largestAlmostMissing = std::max(largestAlmostMissing, num);
        }
    }
    
    return largestAlmostMissing;
}©leetcode

int main()
{
    vector<int> nums{0,0};
    int k = 2;

    cout << largestInteger(nums, k);
}
