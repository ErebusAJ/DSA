#include <bits/stdc++.h>

using namespace std;

// bool rotateString(string s, string goal){
//     int m = s.size(), n = goal.size();

//         if(m != n) return false;

//         for(int i = m - 1; i >= 0; i--){
//             char c = s[m - 1];
//             s = c + s.substr(0,m - 1);
//             if(s == goal) return true;
//         }

//         return false;
// }

bool rotateString(string s, string goal){
    int m = s.size(), n = goal.size();

    s += s;
    return s.find(goal) != string::npos;

}

// VALID ANAGRAM
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s == t) return true;
    return false;
}

int main()
{
    string s = "anagram", goal = "nagram";



    cout << rotateString(s, goal) << endl;
}