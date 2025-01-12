#include <bits/stdc++.h>

using namespace std;

//NAIVE BRUTE BOHOT ZADA BRUTE
// int romanToInt(string s)
// {
//     unordered_map<char, int> roman;
//     roman['I'] = 1;
//     roman['V'] = 5;
//     roman['X'] = 10;
//     roman['L'] = 50;
//     roman['C'] = 100;
//     roman['D'] = 500;
//     roman['M'] = 1000;

//     int n = s.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == 'I')
//         {
//             if (i < n - 1 && s[i + 1] == 'V')
//             {
//                 ans += 4;
//                 i += 1;
//                 continue;
//             }
//             else if (i < n - 1 && s[i + 1] == 'X')
//             {
//                 ans += 9;
//                 i += 1;
//                 continue;
//             }
//         }
//         else if (s[i] == 'X')
//         {
//             if (i < n - 1 && s[i + 1] == 'L')
//             {
//                 ans += 40;
//                 i += 1;
//                 continue;
//             }
//             else if (i < n - 1 && s[i + 1] == 'C')
//             {
//                 ans += 90;
//                 i += 1;
//                 continue;
//             }
//         }
//         else if (s[i] == 'C')
//         {
//             if (i < n - 1 && s[i + 1] == 'D')
//             {
//                 ans += 400;
//                 i += 1;
//                 continue;
//             }
//             else if (i < n - 1 && s[i + 1] == 'M')
//             {
//                 ans += 900;
//                 i += 1;
//                 continue;
//             }
//         }
//         ans += roman[s[i]];
//     }
//     return ans;
// }

// OPTIMIZE KI KOSHISH

int romanToInt(string s){
    unordered_map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    unordered_map<string, int> roman_exp;
    roman_exp["IV"] = 4;
    roman_exp["IX"] = 9;
    roman_exp["XL"] = 40;
    roman_exp["XC"] = 90;
    roman_exp["CD"] = 400;
    roman_exp["CM"] = 900;

    int n = s.size();
    int ans = 0;
    string left = "";
    for(int i = 0; i < n; i++){
        string sub = s.substr(i, 2);
        if(roman_exp.find(sub) != roman_exp.end()){
            ans += roman_exp[sub];
            i += 1;
        }else{
            left += s[i];
        }
    }

    for(int i = 0; i < left.size(); i++){
        ans += roman[left[i]];
    }

    return ans;
}

int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s);
}
