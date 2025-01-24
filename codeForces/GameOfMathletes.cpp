#include <bits/stdc++.h>

using namespace std;


int getScore(vector<int> nums, int n, int k)
{
    unordered_map<int, int> mp;
    for (int i : nums)
        mp[i]++;

    sort(nums.begin(), nums.end());
    int max = nums[n - 1];
    int alice, bob;
    int index = 0;
    int score = 0;
    for (int i = 0; i < n / 2; i++)
    {
        alice = nums[index];
        mp[alice]--;
        int check = k - alice;
        if(mp.find(check) != mp.end() && mp[check] != 0){
            bob = check;
            mp[bob]--;
            index++;
        }else{
            bob = nums[index + 1];
            index += 2;
        }

        if(bob+alice == k) score++;
    }

    return score;
}

int main()
{
    vector<vector <int>> nums;
    int t_c = 0;
    cin >> t_c;
    for(int i = 0; i < t_c; i++){
        int n, k;
        cin >> n >> k;
        vector<int> sub;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            sub.push_back(val);
        }
        nums.push_back(sub);
        sub.clear();
        cout << getScore(nums[i], n, k) << endl;
    }
}

// TEST CASE
// 4
// 4 4
// 1 2 3 2
// 8 15
// 1 2 3 4 5 6 7 8
// 6 1
// 1 1 1 1 1 1
// 16 9
// 3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3
