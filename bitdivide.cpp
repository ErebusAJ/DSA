# include<bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    bool sign = true;
    if(dividend <= 0 && divisor > 0) sign = false;
    else if(dividend >= 0 && divisor < 0) sign = false;

    long n = dividend;
    long d = divisor;
    n = abs(n);
    d = abs(d);
    long ans = 0;

    if(d == 1){
        if(dividend == (1 << 31) && sign) return INT_MAX;
        else if(dividend == (1 << 31) && !sign) return INT_MIN;
    }

    while(n >= d){
        int ctr = 0;
        while(n > (d << (ctr + 1))) ctr++;
        ans += (1 << ctr);
        n = n - (d<< ctr);            
    }

    if(ans == (1 << 31) && sign) return INT_MAX;
    if(ans == (1 << 31) && !sign) return INT_MIN;

    return sign ? ans : -ans;
}

int main(){
    int dividend = -2147483648;
    int divisor = -1;

    cout << divide(dividend, divisor);
}