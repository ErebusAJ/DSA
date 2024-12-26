#include <bits/stdc++.h>

using namespace std;
// Using Sets
// vector<int> findTwoElement(vector<int> &arr)
// {
//     set<int> check;
//     int i = 1;
//     int repeat, miss;
//     while (i < arr.size())
//     {
//         check.insert(i);
//         i++;
//     }

//     for (int i = 0; i < arr.size(); i++)
//     {
//         size_t a = check.erase(arr[i]);
//         if (a == 0)
//         {
//             repeat = arr[i];
//         }
//     }
//     miss = *check.begin();
//     return {repeat, miss};
// }

vector<int> findTwoElement(vector<int> &arr)
{
    long long n = arr.size();
    long long sn = (n*(n+1))/2, s2n = (n*(n+1)*(2*n+1))/6;
    long long s = 0, s2 = 0;

    for(int i = 0; i < n; i++){
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    // X - Y
    long long val1 = s - sn;
    // X^2 - Y^2
    long long val2 = s2 - s2n;

    // X + Y = val2 / X - Y
    int value = val2/val1;
    int miss = (value - val1)/2;
    int repeat = value - miss;

    return {repeat, miss};

}

int main()
{
    vector<int> nums{3,1,2,2};
    vector<int> result = findTwoElement(nums);
    for (int i : result)
    {
        cout << i << " ";
    }
}