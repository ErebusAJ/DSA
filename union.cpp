#include <bits/stdc++.h>

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    vector<int> result;
    result = a;
    for (int i = 0; i < b.size(); i++)
    {
        b.push_back(b[i]);
    }
    sort(result.begin(), result.end());
    auto it = unique(result.begin(), result.end());
    result.erase(it, result.end());

    return result;
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{1, 2, 3};
    vector<int> result;
    result = findUnion(a, b);
    for (int i : result)
    {
        cout << i << " ";
    }
}