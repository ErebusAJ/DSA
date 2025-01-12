#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int> row, int n, int k){
    int low = 0, high = n - 1, ans = n;

    while(low <= high){
        int mid = (low + high)/2;
        if(row[mid] > k){
            ans = mid;
            high = mid - 1;
        }else low = mid + 1;
    }

    return ans;
}

int countSmallEqual(vector<vector <int>>& mat, int m, int n, int k){
    int ctr = 0;
    for(int i = 0; i < m; i++){
        ctr += upperBound(mat[i], n, k);
    }

    return ctr;
}

int median(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < m; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][n - 1]);
    }

    int thresh = (n*m)/2;
    while(low <= high){
        int mid = low + (high - low)/2;
        int smallEqual = countSmallEqual(mat, m, n, mid);
        if(smallEqual <= thresh) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int main()
{
    vector<vector<int>> nums{{1, 5, 7, 9, 11},{2, 3, 4, 8, 9},{4, 11, 14, 19, 20},{6, 10, 22, 99, 100},{7, 15, 17, 24, 28}};
    cout << median(nums);
}