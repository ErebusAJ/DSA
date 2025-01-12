#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s)
{
    int n = s.length();
    string ans = "";
    int c = 0, z = 0;
    char sign;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == '-' || s[i] == '+') && c == 0)
        {
            sign = s[i];
            c = 1;
        }
        else if (isdigit(s[i]))
        {
            ans += s[i];
            z = 1;
            c = 1;
        }
        else if (s[i] == '0' && z != 0)
        {
            ans += s[i];
        }
        else if (s[i] == ' ' && c == 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if (ans == "")
    {
        return 0;
    }

    long long num = 0;
    for (char ch : ans)
    {
        num = num * 10 + (ch - '0');
        if (sign == '-' && -num < INT_MIN)
        {
            return INT_MIN;
        }
        if (sign != '-' && num > INT_MAX)
        {
            return INT_MAX;
        }
    }

    if (sign == '-')
    {
        return -1 * num;
    }
    return num;
}

int main()
{
    string s = "-005601awa2012";
    cout << myAtoi(s);
}