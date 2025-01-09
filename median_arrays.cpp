# include<bits/stdc++.h>

using namespace std;

// BRUTE FORCE SOLUTION

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
//     int m = nums1.size(), n = nums2.size();

//     vector<int> nums;
//     int j = 0, k = 0;
//     while(j < m && k < n){
//         if(nums1[j] <= nums2[k]){
//             nums.push_back(nums1[j]);
//             j++;
//         }else{
//             nums.push_back(nums2[k]);
//             k++;
//         }
//     }

//     for(int i = j; i < m; i++){
//         nums.push_back(nums1[i]);
//     }

//     for(int i = k; i < n; i++){
//         nums.push_back(nums2[i]);
//     }

//     int len = nums.size();
//     int low = 0, high = len - 1;
//     int mid = low + high / 2;
//     double median = 0;
//     if(len % 2 != 0) median = (double)nums[mid];
//     else{
//         median = ((double)nums[mid] + (double)nums[mid + 1])/2.00;
//     }

//     return median;

// }

// OPTIMAL APPROACH

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();

    if(m > n) return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = m;
    int left = (m + n + 1)/2;
    int len = m + n;
    while(low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < m) r1 = nums1[mid1];
        if(mid2 < n) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            if(len % 2 == 1) return max(l1, l2);
            return (double)(((double)max(l1,l2) + (double)min(r1,r2))/2.00);
        }else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0.0;
}





int main(){
    vector<int> nums1{2};
    vector<int> nums2{1,3};

    cout << findMedianSortedArrays(nums1, nums2);

}