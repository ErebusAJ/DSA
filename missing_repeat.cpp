#include <bits/stdc++.h>

using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    vector<int> result(2, 0);
    sort(arr.begin(), arr.end());
    int j = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != j)
        {
            if (arr[i] == arr[i - 1])
            {
                result[0] = arr[i];
            }
            result[1] = j;
        }
        j++;
    }
    return result;
}

int main()
{
    vector<int> num{4,3,6,2,1,1};
    vector<int> result = findTwoElement(num);
    for (int i : result)
        cout << i << " ";
}