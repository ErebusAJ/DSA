#include <bits/stdc++.h>

using namespace std;

// My Brute Code
// void powerSet(vector<vector<int>> &result, vector<int> curr, vector<int> &nums, int i, int n)
// {
//     result.push_back(curr);

//     if (i == n)
//         return;

//     while(i < n)
//     {
//         curr.push_back(nums[i]);
//         i++;
//         powerSet(result, curr, nums, i, n);
//         curr.pop_back();
//     }
// }

// vector<vector<int>> subsets(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<vector<int>> result;
//     result.push_back({});
//     if (n == 1)
//     {
//         result.push_back(nums);
//         return result;
//     }
//     vector<int> curr;
//     int i = 0;
//     while (i < n)
//     {
//         curr.push_back(nums[i]);
//         powerSet(result, curr, nums, i + 1, n);
//         curr.pop_back();
//         i++;
//     }

//     return result;
// }
void powerSet(vector<vector <int>> &result, vector<int> &curr, int i, vector<int> nums){
    if(i == nums.size()){
        result.push_back(curr);
        return;
    }
    
    curr.push_back(nums[i]);
    powerSet(result, curr, i + 1, nums);
    curr.pop_back();

    powerSet(result, curr, i + 1, nums);
}

vector<vector <int>> subsets(vector<int> nums){
    vector<int> curr;
    vector<vector <int>> result;
    powerSet(result, curr, 0, nums);

    return result;
}

int main()
{   
    vector<int> nums{2, 5, 2, 1, 2};

    vector<vector<int>> result = subsets(nums);

    for(vector i : result){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    set<vector <int>> s;
    s.insert({12,3});
}