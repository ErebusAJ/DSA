# include<bits/stdc++.h>

using namespace std;

void solver(vector<string> &result, string curr, int x, int y, vector<vector<int>> mat, int row, int col){
	if(x >= row - 1 && y >= col - 1){
		result.push_back(curr);
		return;
	}
	
	if(x < 0 || x >= row || y < 0 || y >= col || mat[x][y] != 1) return;

	// Check to go Down
	int temp = mat[x][y];
       	mat[x][y] = -1;	
	solver(result, curr + "D", x + 1, y, mat, row, col);

	solver(result, curr + "R", x, y + 1, mat, row, col);
	
	solver(result, curr + "U", x - 1, y, mat, row, col);
	
	solver(result, curr + "L", x, y - 1, mat, row, col);
	
	mat[x][y] = temp;	
}

vector<string> findPath(vector<vector<int>> &mat){
	vector<string> result;
	int row = mat.size();
	int col = mat[0].size();
	
	solver(result, "", 0, 0, mat, row, col);
	return result;
}

int main(){ 
	vector<vector<int>> mat{{1,0,0},{1,1,0},{1,1,1}};
	vector<string> result = findPath(mat);

	for(auto i : result){
		for(auto j : i){
			cout << i << " ";
		}
		cout << endl;
	}
}
