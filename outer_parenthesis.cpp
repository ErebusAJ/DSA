#include <bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string S)
{
    string res;
    int opened = 0;
    for (char c : S)
    {
        if (c == '(' && opened++ > 0)
            res += c;
        if (c == ')' && opened-- > 1)
            res += c;
    }
    return res;
}

int main()
{
    string s = "(()())((()))";
    cout << removeOuterParentheses(s);
}