# include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector <int>> mat{{1,2,3},{4,5,6},{7,8,9}};

    for(int i = 0; i < mat.size(); i++){
        for(int j = i; j < mat.size(); j++){
            swap(mat[j][i],mat[i][j]);
        }
        reverse(mat[i].begin(), mat[i].end());
    }

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat.size(); j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}