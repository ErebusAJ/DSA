#include <bits/stdc++.h>

using namespace std;

// int countSubstr(string &s, int k)
// {
//     int n = s.size();
//     int l = k;
//     int ctr = 0;

//     while(l != n)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             string temp = s.substr(j, l);
//             set<char> unq(temp.begin(), temp.end());
//             if (temp.size() >= l && unq.size() == k)
//                 ctr++;
//         }
//         l++;
//     }
//     return ctr;
// }

int atMostK(string& s, int k){
    unordered_map<char, int> chars;
    int start = 0, result = 0;

    for(int end = 0; end < s.size(); end++){
        chars[s[end]]++;

        while(chars.size() > k){
            chars[s[start]]--;
            if(chars[s[start]] == 0) chars.erase(s[start]);
            start++;
        }

        result += (end - start + 1);
    }

    return result;
}

int countSubstr(string &s, int k){
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main()
{
    string s = "aba";
    cout << countSubstr(s, 2) << endl;
}