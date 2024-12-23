#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int j = m - 1, k = nums1.size() - 1;
    int l = nums2.size() - 1;
    while(l >= 0){
        if(nums1[j] <= nums2[l]){
            nums1[j+1] = nums2[l];
            l--;
            j++;
        }else if(nums1[j] > nums2[l]){
            swap(nums1[j],nums1[k]);
            k--;
            j--;
        }
    }

    // while (l >= 0)
    // {
    //     if (j >= 0 && nums1[j] > nums2[l])
    //     {
    //         nums1[k] = nums1[j];
    //         j--;
    //     }
    //     else
    //     {
    //         nums1[k] = nums2[l];
    //         l--;
    //     }
    //     k--;
    // }
}

int main()
{
    vector<int> nums1{0}; // 1 2 4 5 6 8 10 0 0 0
    vector<int> nums2{1}; // 3 7 9
    merge(nums1, 0, nums2, 3);
    for (int i : nums1)
    {
        cout << i << " ";
    }
}