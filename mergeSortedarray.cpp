#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int j = 0;
    for (int i = m; i < nums1.size(); i++)
    {
        nums1[i] = nums2[j];
        j++;
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{   
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    merge(nums1, 3, nums2, 3);

    for(int i : nums1){
        cout << i << " ";
    }
}