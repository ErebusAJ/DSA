# include<bits/stdc++.h>

using namespace std;

//OPTIMAL SOLUTION
int numberOfGasStations(vector<int> &arr, long double mid){
    int ctr = 0;
    for(int i = 1; i < arr.size(); i++){
        int numBetween = (arr[i] - arr[i - 1]) / mid;
        if(((arr[i] - arr[i - 1]) / mid) == numBetween * mid) numBetween--;
        ctr += numBetween;
    }

    return ctr;
}

double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for(int i = 0; i < n - 1; i++){
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high)/2.00;
        int check = numberOfGasStations(arr, mid);
        if(check > k) low = mid;
        else high = mid;
    }

    return high;
}


int main(){
    vector<int> nums{1,2,3,4,5};
    int k = 4;

    // vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    // int k = 1;

    cout << minimiseMaxDistance(nums, k) << endl ;

}