#include <bits/stdc++.h>

using namespace std;

int subarraysWithSumK(vector<int> a, int b)
{
    int count = 0;
    int val = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        for(int j = i + 1; j < a.size() ; j++){
            val ^= a[j];
            if(val == b){
                count++;
            }
            if(val == 0){
                
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums{1,3,3,3,5};
    cout << subarraysWithSumK(nums, 6);
}