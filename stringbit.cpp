# include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    int plus = 0, minus = 0;

    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        if(s == "X++" || s == "++X" || s == "+X+") plus++;
        else if(s == "X--" || s == "--X" || s == "-X-") minus++;
    }

    cout << plus - minus;
    
}