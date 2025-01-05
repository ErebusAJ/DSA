#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l1 = 0, h1 = matrix.size() - 1;
    int mid1, mid2;
    while(l1 <= h1){
        mid1 = l1 + (h1 - l1)/2;
        int l2 = 0, h2 = matrix[0].size() - 1;
        while(l2 <= h2){
            mid2 = l2 + (h2 - l2)/2;

            if(matrix[mid1][mid2] == target) return true;
            else if(matrix[mid1][mid2] > target) h2 = mid2 - 1;
            else if(matrix[mid1][mid2] < target) l2 = mid2 + 1;
        }
        if(matrix[mid1][mid2] == target) return true;
        else if(matrix[mid1][mid2] > target) h1 = mid1 - 1;
        else if(matrix[mid1][mid2] < target) l1 = mid1 + 1;
    }

    return false;

}

int main()
{
    vector<vector <int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    cout << searchMatrix(matrix, 80);
}