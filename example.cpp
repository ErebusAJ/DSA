#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(vector<int> &nums)
{
    int n = nums.size();
    int mid = n / 2;
    if (n % 2 == 0)
    {
        vector<int> check(nums.begin(), nums.begin() + mid);
        reverse(check.begin(), check.end());
        vector<int> left(nums.begin()+mid, nums.end());
        if(check == left) return true;
        return false;
    }else{
        vector<int> check(nums.begin(), nums.begin() + mid);
        reverse(check.begin(), check.end());
        mid += 1;
        vector<int> left(nums.begin()+mid, nums.end());
        if(check == left) return true;
        return false;
    }
}

int main(){
    vector<int> nums{1,2};
    cout << checkPalindrome(nums);
}