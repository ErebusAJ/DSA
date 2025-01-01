#include <bits/stdc++.h>

using namespace std;

string largestOddNumber(string num)
{
    int i = num.size() - 1;
    int l = 0;
    string result;
    while (i >= 0)
    {
        if (num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9')
        {
            l = i + 1;
            break;
        }
        i--;
    }
    if (l > 0)
        result = num.substr(0, l);

    return result;
}

int main()
{
    string s = "3252537";
    cout << largestOddNumber(s);
}