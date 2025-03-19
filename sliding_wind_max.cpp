# include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> windowMax;

    for(int i = 0; i < nums.size(); i++){
        q.push_back(nums[i]);
        if(q.size() == k){
            auto it = max_element(q.begin(), q.end());
            windowMax.push_back(*it);
            q.pop_front();
        }
    }

    return windowMax;
}

int main(){
    vector<int> nums{1,3,-1,-3,5,3,6,7};

    for(auto i : maxSlidingWindow(nums, 3)) cout << i << " ";
    cout << endl;
}