# include<bits/stdc++.h>

using namespace std;

vector<int> nge(vector<int> nums){
	vector<int> result;
	stack<int> st;

	int i = nums.size() - 1;
	while(i >= 0){
		if(st.empty()) {
			result.push_back(-1);
		}else{
			while(!st.empty() && st.top() < nums[i]){
				st.pop();
			}
			if(st.empty()) result.push_back(-1);
			else result.push_back(st.top());
		}
		st.push(nums[i]);
		i--;
		
	}

	reverse(result.begin(), result.end());

	return result;
}

int main(){
	vector<int> nums{4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
	vector<int> result = nge(nums);
	for(auto i : result) cout << i << " ";
}
