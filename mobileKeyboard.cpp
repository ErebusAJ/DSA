#include <bits/stdc++.h>

using namespace std;

void letterComb(vector<string> &result, string curr, int i, int j,
                vector<string> &check, int len)
{
    if (i == len || j == check[i].size())
    {
        if (curr.size() == len)
            result.push_back(curr);
        return;
    }

    curr.push_back(check[i][j]);
    letterComb(result, curr, i + 1, 0, check, len);
    curr.pop_back();

    letterComb(result, curr, i, j + 1, check, len);
}

vector<string> letterCombinations(string digits)
{
    vector<string> result;
    if (digits.size() == 0)
        return result;
    vector<string> letters{"", "", "abc", "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> check;
    for (int i = 0; i < digits.size(); i++)
    {
        int ind = digits[i] - '0';
        check.push_back(letters[ind]);
    }

    string curr;

    letterComb(result, curr, 0, 0, check, digits.size());

    return result;
}

int main()
{
    string digits = "123";

    letterCombinations(digits);
}
