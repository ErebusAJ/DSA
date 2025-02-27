# include<bits/stdc++.h>

using namespace std;

string preToPost(string s) {
    stack<string> st;
    reverse(s.begin(), s.end());

    int i = 0;
    while(i < s.size()){
        if( (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')
        ) {
            string a;
            st.push(a+s[i]);
        }
        else{
            string a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            string c = a+b+s[i];
            st.push(c);
        }
        i++;
    }
    
    return st.top();
}

int main(){
    string s = "*-A/BC-/AKL";

    cout << preToPost(s);
}