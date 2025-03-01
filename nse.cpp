# include<bits/stdc++.h>

using namespace std;

vector<int> nse(vector<int> nums){
	vector<int> result;
	stack<int> st;

	int i = 0;
	while(i < nums.size()){
		while(!st.empty() && nums[i] < st.top()) st.pop();
		if(st.empty()) result.push_back(-1);
		else result.push_back(st.top());
		st.push(nums[i]);
		i++;
	}

	return result;
}

int main(){
	vector<int> nums{3, 2, 1};

	for(auto i : nse(nums)) cout << i << " ";
}
