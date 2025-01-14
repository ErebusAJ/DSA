#include <bits/stdc++.h>

using namespace std;

// BRUTE
// int numCommon(vector<int> &a, vector<int> &b)
// {
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     int ctr = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         if (a[i] == b[i])
//             ctr++;
//     }
//     return ctr;
// }

// vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
// {
//     int n = a.size();
//     vector<int> c;

//     for (int i = 1; i <= n; i++)
//     {
//         vector<int> check1(a.begin(), a.begin() + i);
//         vector<int> check2(b.begin(), b.begin() + i);

//         c.push_back(numCommon(check1, check2));
//     }

//     return c;
// }

// OPTIMIZE
int numCommon(vector<int> &a, vector<int> &b)
{
    vector<int> freq(50, 0);

    for (int i : a)
    {
        freq[i] = 1;
    }

    int ctr = 0;
    for (int i : b)
    {
        if (freq[i] == 1)
            ctr++;
    }
    return ctr;
}

vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    vector<int> c;

    for (int i = 1; i <= n; i++)
    {
        vector<int> check1(a.begin(), a.begin() + i);
        vector<int> check2(b.begin(), b.begin() + i);

        c.push_back(numCommon(check1, check2));
    }

    return c;
}

int main()
{
    vector<int> a{2, 3, 1};
    vector<int> b{3, 1, 2};

    for (int i : findThePrefixCommonArray(a, b))
        cout << i << " ";
    cout << endl;
}