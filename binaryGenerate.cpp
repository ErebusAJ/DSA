# include<bits/stdc++.h>

using namespace std;

vector<string> binary;

void generateBinary(int n, int digits){
    if(n == 0){
        string s(digits, '0');
        binary.push_back(s);
        return;
    }
    
    generateBinary(n - 1, digits);

    string s = "";
    while(n){
        int i = n % 2;
        char c = '0' + i;
        if(s[s.size() - 1] == '1' && c == '1') return;
        s += c;
        n /= 2;
    }
    while(s.size() != digits){
        s += '0';
    }
    reverse(s.begin(), s.end());

    binary.push_back(s);
}

int calculateN(int n){
    if(n == 1) return n;
    
    int result = 1;
    result += 2 * calculateN(n - 1);

    return result;
}

int main(){
    int n = 5;

    n = calculateN(n);
    
    int digits = static_cast<int>(sqrt(n)) + 1;
    generateBinary(n, digits);

    for(auto i : binary){
        cout << i << " ";
    }

    cout << endl;
}