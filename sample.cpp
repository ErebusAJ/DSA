#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int row = mat.size();
    int column = mat[0].size();
    int count = 0, index = 0;
    for (int i = 0; i < row; i++)
    {
        int temp = 0;
        for (int j = 0; j < column; j++)
        {
            if (mat[i][j] == 1)
            {
                temp++;
            }
        }
        if (count == temp)
        {
            continue;
        }
        if (count < temp)
        {
            count = temp;
            index = i;
        }
    }

    return {index, count};
}

int main()
{
    vector<vector<int>> num{{0, 1}, {1, 0}};
    auto result = rowAndMaximumOnes(num);
    for(int i : result){
        cout << i << " ";
    }
}