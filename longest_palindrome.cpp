#include <bits/stdc++.h>

using namespace std;

// APNA VAHI BRUTE WALA

// bool checkPalindrome(string s)
// {
//     int n = s.size();
//     int mid = n / 2;
//     string check;
//     if (n % 2 == 0)
//     {
//         check = s.substr(mid, mid);
//         reverse(check.begin(), check.end());
//         if (s.substr(0, mid) == check)
//             return true;
//         return false;
//     }
//     else
//     {
//         check = s.substr(mid + 1, mid);
//         reverse(check.begin(), check.end());
//         if (s.substr(0, mid) == check)
//             return true;
//         return false;
//     }

//     return false;
// }

// string longestPalindrome(string s)
// {
//     int n = s.size();
//     string maxi = "";

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = n - 1; j >= i; j--)
//         {
//             if (checkPalindrome(s.substr(i, (j - i + 1))))
//             {
//                 string sub = s.substr(i, (j - i + 1));
//                 if (maxi.size() < sub.size())
//                     maxi = sub;
//             }
//         }
//     }

//     return maxi;
// }

int expandAroundCenter(string s, int left, int right){
    while((left >= 0 && right < s.size()) && s[left] == s[right]){
        left--;
        right++;
    }   

    return right - left - 1;
}

string longestPalindrome(string s){
    if(s.empty()) return s;

    if(s.size() == 0) return s;

    int n = s.size();
    int start = 0, end = 0;

    for(int i = 0; i < n; i++){
        int even = expandAroundCenter(s, i, i);
        int odd = expandAroundCenter(s, i, i + 1);
        int maxLen = max(odd, even);

        if(maxLen > end - start){
            start = i - (maxLen - 1) / 2;
            end = i + (maxLen)/2;
        }
           
    }

    return s.substr(start, end-start+1);  
}


int main()
{
    string s = "babad";
    cout << longestPalindrome(s);
}