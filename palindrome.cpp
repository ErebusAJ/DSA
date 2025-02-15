# include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    if(s.size() == 0) return false;
    if(s.size() == 1) return true;
    int mid = s.size() / 2;
    if(s.size() % 2){
        string check = s.substr(0, mid);
        reverse(check.begin(), check.end());
        if(check == s.substr(mid + 1, mid)) return true;
        else return false;
    }else{
        string check = s.substr(0, mid);
        reverse(check.begin(), check.end());
        if(check == s.substr(mid, mid)) return true;
        else return false;
    }

    return false;
}

int main(){
    string s = "a";
    cout << isPalindrome(s);
}