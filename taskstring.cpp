# include<bits/stdc++.h>

using namespace std;

string solver(string s){
    string str;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y' && s[i] != 'Y' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'){
            str.push_back('.');
            str.push_back(tolower(s[i]));
        }
    }

    return str;
}

int main(){
    string s;
    cin >> s;
    cout << solver(s);
}