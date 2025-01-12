# include<bits/stdc++.h>

using namespace std;

bool checkRepeat(int n){
        int num = n;
        unordered_map<int, int> m;
        while(num > 0){
            int val = num % 10;
            if(m.find(val) != m.end()){
                m[val]++;
            }else{
                m.insert(make_pair(val,1));
            }
            num /= 10;
        }

        for(auto p : m){
            if(p.second > 1)
                return true;
        }

        return false;
    }

    int numDupDigitsAtMostN(int n) {
        int ctr = -1;
        for(int i = 11; i <= n; i++){
            if(checkRepeat(i)) ctr++;
        }

        return ctr;
    }

int main(){
    cout << numDupDigitsAtMostN(738935);
}