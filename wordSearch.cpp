#include <bits/stdc++.h>

using namespace std;

// My Brute Force Solutionr

// bool wordSearch(vector<vector<char>> &mat, string s, int i, int j, int row,
//                 int col, int m, map<pair<int, int>, int> &path)
// {
//     if (m == s.size())
//         return true;

//     if (i + 1 < row)
//     {
//         pair<int, int> search = make_pair(i + 1, j);
//         if (mat[i + 1][j] == s[m] && path.find(search) == path.end())
//         {
//             path[make_pair(i + 1, j)]++;
//             if (wordSearch(mat, s, i + 1, j, row, col, m + 1, path))
//                 return true;
//             path.erase(search);
//         }
//     }

//     if (i - 1 >= 0)
//     {
//         pair<int, int> search = make_pair(i - 1, j);
//         if (mat[i - 1][j] == s[m] && path.find(search) == path.end())
//         {
//             path[make_pair(i - 1, j)]++;
//             if (wordSearch(mat, s, i - 1, j, row, col, m + 1, path))
//                 return true;
//             path.erase(search);
//         }
//     }

//     if (j - 1 >= 0)
//     {
//         pair<int, int> search = make_pair(i, j - 1);
//         if (mat[i][j - 1] == s[m] && path.find(search) == path.end())
//         {
//             path[make_pair(i, j - 1)]++;
//             if (wordSearch(mat, s, i, j - 1, row, col, m + 1, path))
//                 return true;
//             path.erase(search);
//         }
//     }
//     if (j + 1 < col)
//     {
//         pair<int, int> search = make_pair(i, j + 1);
//         if (mat[i][j + 1] == s[m] && path.find(search) == path.end())
//         {
//             path[make_pair(i, j + 1)]++;
//             if (wordSearch(mat, s, i, j + 1, row, col, m + 1, path))
//                 return true;
//             path.erase(search);
//         }
//     }
//     return false;
// }

// bool exist(vector<vector<char>> &board, string word)
// {
//     int row = board.size();
//     int col = board[0].size();
//     bool check;
//     map<pair<int, int>, int> path;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (board[i][j] == word[0])
//             {
//                 path[make_pair(i, j)]++;
//                 check = wordSearch(board, word, i, j, row, col, 1, path);
//                 path.clear();
//             }
//             if (check)
//                 break;
//         }
//         if (check)
//             break;
//     }

//     return check;
// }

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    cout << exist(board, "ABCB");
}