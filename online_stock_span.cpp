# include<bits/stdc++.h>

using namespace std;

vector<int> stockSpanner(vector<int> &nums){
	vector<int> result;
	stack<int> st;
	queue<int> temp;

	int i = 0;
	while(i < nums.size()){
		while(!st.empty() && st.top() <= nums[i]){
			temp.push(st.top());
			st.pop();
		}
		temp.push(nums[i]);
		result.push_back(temp.size());
		while(!temp.empty()){
			st.push(temp.front());
			temp.pop();
		}
		i++;
	}

	return result;
}

int main(){
	vector<int> nums{100, 80, 60, 70, 60, 75, 85};

	for(auto i : stockSpanner(nums)) cout << i << " ";

}
