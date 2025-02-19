#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<char>> &board, int i, int j, char c){
	// check vertical
	for(int a = 0; a < 9; a++){
		if(board[a][j] == c) return false;
	}

	// check horizontal
	for(int a = 0; a < 9; a++){
		if(board[i][a] == c) return false;
	}

	// check for its own 3x3
	if(i >= 0 && i <= 2){
		if(j >= 0 && j <= 2){
			for(int a = 0; a < 3; a++){
				for(int b = 0; b < 3; b++){
					if(board[a][b] == c) return false;
				}
			}
		}else if(j >= 3 && j <= 5){
			for(int a = 0; a < 3; a++){
				for(int b = 3; b < 6; b++){
					if(board[a][b] == c) return false;
				}
			}
		}else if(j >= 6 && j <= 8){
			for(int a = 0; a < 3; a++){
				for(int b = 6; b < 9; b++){
					if(board[a][b] == c) return false;
				}
			}
		}
	}else if(i >= 3 && i <= 5){
		if(j >= 0 && j <= 2){
			for(int a = 3; a < 6; a++){
				for(int b = 0; b < 3; b++){
					if(board[a][b] == c) return false;
				}
			}
		}else if(j >= 3 && j <= 5){
			for(int a = 3; a < 6; a++){
				for(int b = 3; b < 6; b++){
					if(board[a][b] == c) return false;
				}
			}
		}else if(j >= 6 && j <= 8){
			for(int a = 3; a < 6; a++){
				for(int b = 6; b < 9; b++){
					if(board[a][b] == c) return false;
				}
			}
		}
	}else if(i >= 6 && i <= 8){
		if(j >= 0 && j <= 2){
			for(int a = 6; a < 9; a++){
				for(int b = 0; b < 3; b++){
					if(board[a][b] == c) return false;
				}
			}
		}else if(j >= 3 && j <= 5){
			for(int a = 6; a < 9; a++){
				for(int b = 3; b < 6; b++){
					if(board[a][b] == c) return false;
				}
			}
		}else if(j >= 6 && j <= 8){
			for(int a = 6; a < 9; a++){
				for(int b = 6; b < 9; b++){
					if(board[a][b] == c) return false;
				}
			}
		}
	}

	return true;
}

// bool isSafe(vector<vector<char>> &board, int row, int col, char c)
// {
// 	for (int x = 0; x < 9; x++)
// 	{
// 		if (board[x][col] == c)
// 			return false;

// 		if (board[row][x] == c)
// 			return false;

// 		if (board[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == c)
// 			return false;
// 	}

// 	return true;
// }

bool solver(vector<vector<char>> &board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == '.')
			{

				for (char c = '1'; c <= '9'; c++)
				{
					if (isSafe(board, i, j, c))
					{
						board[i][j] = c;
						if (solver(board)) return true;
						board[i][j] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}


void solveSudoku(vector<vector<char>> &board)
{
	solver(board);
}

int main()
{
	vector<vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
							   {'.', '9', '.', '.', '1', '.', '.', '3', '.'},
							   {'.', '.', '6', '.', '2', '.', '7', '.', '.'},
							   {'.', '.', '.', '3', '.', '4', '.', '.', '.'},
							   {'2', '1', '.', '.', '.', '.', '.', '9', '8'},
							   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
							   {'.', '.', '2', '5', '.', '6', '4', '.', '.'},
							   {'.', '8', '.', '.', '.', '.', '.', '1', '.'},
							   {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};

	solveSudoku(board);

	for (auto i : board)
	{
		cout << "{";
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << "}" << endl;
	}
}1