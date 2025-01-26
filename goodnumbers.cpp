#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
long long power(long long b, long long e, long long ans)
{
    if (e == 0)
        return ans;
    if (e % 2)
        return power((b * b) % MOD, e / 2, ans);
    else
        return power(b, e - 1, (ans * b) % MOD);
}

int countGoodNumbers(long long n)
{
    long long ans = power(20, n / 2, 1);
    return (n % 2) ? (ans * 5) % MOD : ans;
}

int main()
{
    cout << countGoodNumbers(4) << endl;
}