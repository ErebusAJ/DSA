# include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<pair<int, int>> edges, vector<int> color, int k, int i){
	int first = edges[k].first;
	int second = edges[k].second;
	if(first < color.size() && first == color[first]) return false;
	if(second < color.size() && second == color[second]) return false;

	return true;
}

bool solver(vector<pair<int,int>> edges, int i,int m, vector<int> color, int v){
	if(color.size() == v) return true;

	for(int k = m; k > 0; k--){
		if(isSafe(edges, color, k, i)){
			color.push_back(k);
			if(solver(edges, i + 1, m, color, v)) return true;
   			color.pop_back();			
		}
	}

	return false;
}

bool graphColoring(int v, vector<pair<int,int>> &edges, int m){
	vector<int> color;
	return solver(edges, 0, m, color, v);  
}

int main(){
	vector<pair<int,int>> edges{make_pair(0,1),
		make_pair(0,0)};
	int v = 2;
	int m = 1;
	cout << graphColoring(v, edges, m);
}
