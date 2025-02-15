#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    if (s.size() == 0)
        return false;
    int mid = s.size() / 2;
    if (s.size() % 2)
    {
        string check = s.substr(0, mid);
        reverse(check.begin(), check.end());
        if (check == s.substr(mid + 1, mid))
            return true;
        else
            return false;
    }
    else
    {
        string check = s.substr(0, mid);
        reverse(check.begin(), check.end());
        if (check == s.substr(mid, mid))
            return true;
        else
            return false;
    }

    return false;
}

void palindromePart(vector<vector<string>> &result, vector<string> &temp, string curr, int i, string s)
{
    if (curr != "")
    {
        if (isPalindrome(curr))
        {
            temp.push_back(curr);
            curr = "";
        }
        else
        {
            return;
        }
    }

    if (i == s.size())
    {
        result.push_back(temp);
        return;
    }

    curr += s[i];
    palindromePart(result, temp, curr, i + 1, s);
    curr.pop_back();

    palindromePart(result, temp, curr, i + 1, s);
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> curr;
    palindromePart(result, curr, "", 0, s);
    return result;
}

int main()
{
    string s = "aab";
    vector<vector<string>> result = partition(s);

    for (auto i : result)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]";
        cout << endl;
    }
}