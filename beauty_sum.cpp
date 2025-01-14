#include <bits/stdc++.h>

using namespace std;

// BRUTE BHAIIIII

// int beauty(string s)
// {
//     unordered_map<char, int> m;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (m.find(s[i]) != m.end())
//         {
//             m[s[i]]++;
//         }
//         else
//             m.insert(make_pair(s[i], 1));
//     }

//     priority_queue<int> pq;
//     for (auto p : m)
//         pq.push(p.second);

//     int maxi = pq.top();
//     int mini = 0;
//     while (!pq.empty())
//     {
//         mini = pq.top();
//         pq.pop();
//     }

//     return (maxi - mini);
// }

// int beautySum(string s)
// {
//     int n = s.size();
//     int result = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             result += beauty(s.substr(i, (j - i + 1)));
//         }
//     }

//     return result;
// }

// OPTIMIZE KI KOSHSIH
int beauty(string s)
{
    vector<int> nums(26, 0);
    set<int> indexes;

    for (int i = 0; i < s.size(); i++)
    {
        int index = int(s[i]) - 97;
        nums[index]++;
        indexes.insert(index);
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i : indexes)
    {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
    }

    return (maxi - mini);
}

int beautySum(string s)
{
    int n = s.size();
    long result = 0;
    vector<string> subss;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // result += beauty(s.substr(i, (j - i + 1)));
            subss.push_back(s.substr(i, (j - i + 1)));
        }
    }

    for(int i = 0; i < subss.size(); i++){
        result += beauty(subss[i]);
    }
    return result;
}

int main()
{
    string s = "aabcb";
    cout << beautySum(s);
}