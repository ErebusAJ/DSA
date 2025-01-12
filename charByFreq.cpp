#include <bits/stdc++.h>

using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) != m.end())
            m[s[i]]++;
        else
            m.insert(make_pair(s[i], 1));
    }

    // vector<pair<int, char>> nums;
    // for(auto i : m){
    //     nums.push_back({i.second, i.first});
    // }

    // sort(nums.begin(), nums.end(), greater());

    // string r = "";
    // for (auto p : nums)
    // {
    //     for (int i = 1; i <= p.first; i++)
    //         r += p.second;
    // }

    priority_queue<pair<int, char>> pq;
    for(auto i : m){
        pq.push({i.second, i.first});
    }

    string r = "";
    for (int i = 0; i < s.size(); i++){
        if(!pq.empty()){
            auto p = pq.top();
            for(int j = 1; j <= p.first; j++){
                r += p.second;
            }
            pq.pop();
        }else break;
    }
    

    return r;
}

int main()
{
    string s = "ggghii";
    cout << frequencySort(s) << endl;
}