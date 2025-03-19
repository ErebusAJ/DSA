# include<bits/stdc++.h>

using namespace std;

int main(){
    map<int, int> mp;
    mp[1] = 2;
    mp[2] = 3;
    mp.erase(2);
    cout << mp[2];
}