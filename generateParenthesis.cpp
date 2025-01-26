#include <bits/stdc++.h>

using namespace std;

void dfs(int openP, int closeP, string str, int n, vector<string> &result)
{
    if (openP == closeP && openP + closeP == n * 2)
    {
        result.push_back(str);
        return;
    }

    if (openP < n)
    {
        dfs(openP + 1, closeP, str + "(", n, result);
    }

    if (closeP < openP)
    {
        dfs(openP, closeP + 1, str + ")", n, result);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    dfs(0, 0, "", n, result);
    return result;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis(n);

    for (auto i : result)
        cout << i << " ";

    cout << endl;
}