#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n)
{
    if (n == 1 || n == -1)
        return x;
    double result = 1;
    if (n < 0)
    {
        x = 1 / x;
        result = x * myPow(x, n + 1);
    }
    else
    {
        result = x * myPow(x, n - 1);
    }
    return result;
}

int main()
{
    double n = 3;
    cout << myPow(2.00000,-2);
}