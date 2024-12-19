#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    int val;
    result.push_back({});
    result[0].push_back(1);
    for (int i = 1; i < numRows; i++)
    {
        int k = 0;
        result.push_back({});
        result[i].push_back(1);
        for (int j = 1; j < i; j++)
        {
            val = result[i-1][k] + result[i-1][k+1];
            k++;
            result[i].push_back(val);
        }
        result[i].push_back(1);
    }

    return result ;
}

int main()
{
    vector<vector <int>> nums;
    nums = generate(5);
    for(vector i : nums){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}