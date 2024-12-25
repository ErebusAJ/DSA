#include <bits/stdc++.h>

using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    set<int> check;
    int i = 1;
    int repeat, miss;
    while (i < arr.size())
    {
        check.insert(i);
        i++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        size_t a = check.erase(arr[i]);
        if (a == 0)
        {
            repeat = arr[i];
        }
    }
    miss = *check.begin();
    return {repeat, miss};
}

int main()
{
    vector<int> nums{2, 2};
    vector<int> result = findTwoElement(nums);
    for (int i : result)
    {
        cout << i << " ";
    }
}