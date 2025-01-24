# include<bits/stdc++.h>

using namespace std;

string createDiverseTeam(vector<int> &ratings, int n, int k){
    set<int> st;

    for(int i : ratings){
        st.insert(i);
    }

    if(st.size() >= k) return "YES";
    
    return "NO";
}   

int main(){
    vector<int> nums;
    int n, k;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cout << createDiverseTeam(nums, n, k) << endl;

}