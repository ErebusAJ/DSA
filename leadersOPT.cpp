#include <bits/stdc++.h>

using namespace std;

vector<int> leaders(vector<int> &arr)
{
    vector<int> result;
    int max = 0, index;
    while (max < arr.size())
    {
        auto lead = max_element(arr.begin() + max, arr.end());
        int i = distance(arr.begin() + max, lead);
        auto index = find(arr.begin(), arr.end(), lead);
        max = i;
        result.push_back(arr[i]);
    }
    return result;
}

int main()
{
    vector<int> nums{16,17,4,3,5,2};
    vector<int> result;
    result = leaders(nums);
    for(int i : result){
        cout << i << " " ;
    }
}