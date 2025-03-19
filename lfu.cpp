# include<bits/stdc++.h>

using namespace std;

struct CompareSecond{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> pq;

    pq.push({1, 3});
    pq.push({2, 1});
 
    pq.pop();

    cout << pq.top().first;

    set<int> r{1,2,3,4,5};
    r.erase(3);
    
    
}