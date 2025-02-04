#include <bits/stdc++.h>

using namespace std;

void powerSet(set<vector<char>> &result, vector<char> &curr, int i,string &str)
{
    result.insert(curr);
    for (int j = i; j < str.size(); j++)
    {
        curr.push_back(str[i]);
        powerSet(result, curr, j + 1, str);
        curr.pop_back();
    }
}

string betterString(string str1, string str2)
{
    set<vector<char>> a;
    set<vector<char>> b;
    vector<char> curr;
    powerSet(a, curr, 0, str1);
    powerSet(b, curr, 0, str2);

    return (a.size() >= b.size()) ? str1 : str2;
}


int main()
{
    string s1 = "gfg", s2 = "ggg";
    cout << betterString(s1, s2);
}