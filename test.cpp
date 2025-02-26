
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    vector<int> result;
    int p = 0, k = 0;
    for (int i : nums)
    {
        if (i >= 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            result.push_back(pos[p]);
            p++;
        }
        else
        {
            result.push_back(neg[k]);
            k++;
        }
    }
    return result;
}

int main()
{
    vector<int> arr{3, 1, -2, -5, 2, -4};
    vector<int> result;
    result = rearrangeArray(arr);
    for (int i : result)
    {
        cout << i << " ";
    }

    string s;
    int a = 2;
    char c = '0' + a;
    s.push_back(c);
    cout << s;
}
