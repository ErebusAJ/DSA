#include <bits/stdc++.h>

using namespace std;

//Brute Force  O(n.log(m))

// bool searchMatrix(vector<vector<int>> &matrix, int target){
//     int n = matrix.size();
//     bool check = false;
//     for(int i = 0; i < n; i++){
//         int l = 0, h = matrix[0].size() - 1;
//         while(l <= h){
//             int mid = l + (h - l)/2;
//             if(matrix[i][mid] == target){
//                 check = true; break;
//             }else if(matrix[i][mid] > target) h = mid - 1;
//             else if(matrix[i][mid] < target) l = mid + 1;
//         }
//         if(check) break;
//     }

//     return check;
// }

// Optimized O(log n)

bool searchMatrix(vector<vector <int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int row = n - 1, col = 0;

    while(row >= 0 && col < m){
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) row--;
        else if(matrix[row][col] < target) col++;
    }

    return false;
}


int main()
{
    vector<vector <int>> matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    cout << searchMatrix(matrix, 15);

}