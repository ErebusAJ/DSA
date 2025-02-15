#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> mat, int i, int j, int max)
{
    if (mat.size() == 0)
        return true;
    int a = i, b = j;

    // check left upper diagonal
    while (a >= 0 && b >= 0)
    {
        if (mat[a][b] == 'Q')
            return false;
        a--;
        b--;
    }

    // chek left lower daigonal
    a = i, b = j;
    while ((a >= 0 && a < max) && b >= 0)
    {
        if (mat[a][b] == 'Q')
            return false;
        a++;
        b--;
    }

    // check left row
    a = i;
    b = j;
    while (b >= 0)
    {
        if (mat[a][b] == 'Q')
            return false;
        b--;
    }

    return true;
}

void solver(vector<vector<string>> &result, vector<string> mat, int i, int j, int n, int max)
{
    if(i == max || j == max){
        if(n == 0) result.push_back(mat);
        return;
    }
    if (n == 0)
    {
        result.push_back(mat);
        return;
    }

    for (int index = 0; index < max; index++)
    {
        if(isSafe(mat, index, j, max)){
            mat[index][j] = 'Q';  
            solver(result, mat, index, j+1, n-1, max);
            mat[index][j] = '.'; 
        }
        
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    string s;
    for(int i = 1; i <= n; i++){
        s +=".";
    }
    vector<string> board(n, s);
    solver(result, board, 0, 0, n, n);

    return result;
}

int main()
{
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);

    for (auto i : result)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << "[";
            for(auto k : j){
                cout << k << " ";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }
}