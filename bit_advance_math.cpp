#include <bits/stdc++.h>

using namespace std;


vector<int> countDivisors(int n){
    vector<int> divs;
    // int x = n;
    for(int i = 1; i * i <= n; i++){
        if((n % i) == 0){
            divs.push_back(i);
            int d = n / i;
            if(d != i) divs.push_back(d);
        }
    }

    return divs;
}

bool checkPrime(int n){
    int ctr = 0;
    
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ctr++;
            int d = n / i;
            if(d != i) ctr++;
        }
        if(ctr > 2) return false;
    }

    return true;
}


vector<int> printPrimeFactors(int n){
    vector<int> facts;
    int x = n;

    for(int i = 2; i * i <= n; i++){
        if((x % i) == 0){
            x /= i;
            facts.push_back(i);
            while(x % i == 0) x /= i;
        }
    }

    if(x != 1) facts.push_back(x);

    return facts;
}

vector<int> queriesPrime(vector<pair<int, int>> queries){
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < queries.size(); i++){
        if(queries[i].first < low ) low = queries[i].first;
        if(queries[i].second > high) high = queries[i].second;
    }

    // SIEVE OF ERATOSTHENES
    vector<int> prime(high + 1, 1);
    for(int i = 2; i * i <= high; i++){
        if(prime[i] == 1){
            for(int j = i * i; j <= high; j+=i) prime[j] = 0;
        }
    }
    prime[0] = 0;
    prime[1] = 0;

    vector<int> store(high + 1, 0);
    int ctr = 0;
    for(int i = 0; i <= high; i++){
        if(prime[i] == 1) ctr++;
        store[i] = ctr;
    }

    vector<int> result;
    for(int i = 0; i < queries.size(); i++){
        int l = queries[i].first;
        int h = queries[i].second;
        if(l < 0) l = 0; 
        int val;
        if(prime[l] == 1) val = store[h] - store[l] + 1;
        else val = store[h] - store[l];
        result.push_back(val);
    }

    return result;
}


int main()
{
    int a;
    cin >> a;

    // for(auto i : countDivisors(a)) cout << i << " ";

    // cout << checkPrime(a);

    // for(auto i : printPrimeFactors(a)) cout << i << " ";

    // vector<int> prime(5, 1);
    // for(auto i : prime) cout << i << " ";

    vector<pair<int, int>> queries;
    for(int i = 0; i < a; i++){
        int b,c;
        cin >> b >> c;
        queries.push_back(make_pair(b,c));
    }

    vector<int> result = queriesPrime(queries);
    for(auto i : result) cout << i << " ";
    

    cout << endl;
}