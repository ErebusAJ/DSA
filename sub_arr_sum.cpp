# include<bits/stdc++.h>

using namespace std;

vector<int> nextSmallElem(vector<int> nums){
    vector<int> result(nums.size(), 0);
    stack<int> st;
    int i = nums.size() - 1;
    while(i >= 0){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        result[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
        i--;
    }

    return result;
}

vector<int> prevSmallElem(vector<int> nums){
    vector<int> result(nums.size(), 0);
    stack<int> st;
    int i = 0;
    while(i < nums.size()){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
        i++;
    }

    return result;
}

int sumSubarrayMins(vector<int>& nums){
    vector<int> pse = prevSmallElem(nums);
    vector<int> nse = nextSmallElem(nums);
    int sum = 0;
    const int MOD = 1e9+7;

    for(int i = 0; i < nums.size(); i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        sum += (left * right * nums[i]) % MOD;
    }

    return sum;
}

int main(){
    vector<int> nums{1, 1};

    // for(auto i : prevSmallElem(nums)) cout << i << " ";
    cout << sumSubarrayMins(nums);
}