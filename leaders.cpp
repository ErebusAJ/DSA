#include <bits/stdc++.h>

using namespace std;

vector<int> leaders(vector<int> &arr)
{
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        bool check = true;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                check = false;
            }
        }
        if (check)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main()
{
}