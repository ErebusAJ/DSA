#include <bits/stdc++.h>

using namespace std;

string reverseWords(string a)
{
    string result, val;
    int l = 0, h = -1;
    int i = a.size() - 1;
    while (i >= 0)
    {
        if (a[i] == ' ' && (l == 0 && h == -1))
        {
            i--;
            continue;
        }
        if (a[i] == ' ')
        {
            string sub = a.substr(h, l);
            if (result == "")
                result = sub;
            else
                result = result + " " + sub;
            l = 0;
            h = -1;
        }
        else
        {
            h = i;
            l++;
        }
        i--;
    }
    if (l > 0 && h > -1)
    {
        if(result != "")result += " " + a.substr(h, l);
        else result = a.substr(h,l);
    }

    return result;
}

int main()
{
    string s = "hello";
    // string s = "  hello world  ";
    string result = reverseWords(s);
    cout << result << endl;
    cout << result.size() << endl;
}