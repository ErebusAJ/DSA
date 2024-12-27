#include <bits/stdc++.h>

using namespace std;

int reverseCount(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int ctr = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2 * (long long)nums[right]) right++;
            ctr += (right - (mid + 1));
        }

        return ctr;
    }

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int ctr = 0;
        if (low >= high)
            return ctr;
        int mid = (low + high) / 2;
        ctr += mergeSort(nums, low, mid);
        ctr += mergeSort(nums, mid + 1, high);
        ctr += reverseCount(nums, low, mid, high);
        merge(nums, low, mid, high);

        return ctr;
    }

    int reversePairs(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ctr = mergeSort(nums, low, high);

        return ctr;
    }

int main()
{
    vector<int> nums{3, 2, 4, 1, 3};
    mergeSort(nums, 0, 4);

    for (int i : nums)
    {
        cout << i << " ";
    }
}