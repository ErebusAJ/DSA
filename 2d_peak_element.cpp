# include<bits/stdc++.h>

using namespace std;


// MY OPTIMAL SOLUTION O(max(m,n))


int safeAcess(vector<vector <int>>& mat, int m, int n){
    if(m < mat.size() && n < mat[0].size()){
        return mat[m][n];
    }else return -1;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int i = m/2, j = n/2;

    while(true){
        int val = safeAcess(mat, i, j);
        int top = safeAcess(mat, i - 1, j);
        int bottom = safeAcess(mat, i + 1, j);
        int left = safeAcess(mat, i, j - 1);
        int right = safeAcess(mat, i, j + 1);
        
        if(val > top && val > bottom && val > left && val > right) return {i,j};
        else if(top == max({top, bottom, left, right}))i--;
        else if(bottom == max({top, bottom, left, right})) i++;
        else if(left == max({top, bottom, left, right})) j--;
        else if(right == max({top, bottom, left, right})) j++;

    } 

    return {};
}

int main(){
    vector<vector <int>> mat{{1, 2, 2},{2, 2, 2},{2, 2, 4}};

    for(int i : findPeakGrid(mat))
        cout << i << " ";
}