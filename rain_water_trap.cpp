# include<bits/stdc++.h>

using namespace std;

// int trap(vector<int> nums){
// 	int result;
// 	vector<int> collect(nums.size(), 0);
// 	stack<pair<int, int>> st;

// 	int i = nums.size() - 1;
// 	while(i >= 0){
// 		while(!st.empty() && nums[i] > st.top().first) st.pop();
// 		if(st.empty()) collect[i] = 0;
// 		else{
// 			// width = (j - i - 1) * i(height)
// 			int w = st.top().second	- i - 1;
// 			if(w == 0) collect[i] = 0;
// 			else{
// 				int val = w * nums[i];
// 				for(int k = i + 1; k < st.top().second; k++){
// 					collect[k] = 0;
// 					val -= nums[k];
// 				}
// 				collect[i] = val;
// 			}
// 		}
// 		st.push(make_pair(nums[i], i));
// 		i--;
// 	}

// 	result = accumulate(collect.begin(), collect.end(), 0);
	
// 	return result;
// }

int trap(vector<int> nums){
	int lmax = 0, rmax = 0;
	int l = 0, r = nums.size() - 1;
	int total = 0;

	while(l < r){
		if(nums[l] <= nums[r]){
			if(lmax > nums[l]) total += lmax - nums[l];
			else lmax = nums[l];
			l++;
		}else{
			if(rmax > nums[r]) total += rmax - nums[r];
			else rmax = nums[r];
			r--;
		}
	}

	return total;
}

int main(){
	// vector<int> height{4,2,3};
	vector<int> height{4,2,0,3,2,5};

	cout << trap(height) << endl;
}
