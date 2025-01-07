# include<bits/stdc++.h>

using namespace std;

bool checkBouquet(vector<int> &bloomDay, long long d, int k, int m){
    int check_k = 0, check_m = 0;
    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= d){
            check_k++;
            if(check_k == k){
                check_m++;
                check_k = 0;
            }
        }else check_k = 0;
    }
    if(check_m >= m) return true;
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k){
    if(bloomDay.size() < (m * k)) return -1;

    long long low = *min_element(bloomDay.begin(), bloomDay.end());
    long long high = *max_element(bloomDay.begin(), bloomDay.end());
    long long ans = LONG_LONG_MAX;

    while(low <= high){
        long long mid = low + (high - low)/2;
        bool check = checkBouquet(bloomDay, mid, k, m);
        if(check){
            ans = min(ans, mid);
            high = mid - 1;        
        }else low = mid + 1;
    }

    return ans;
}

int main(){
    vector<int> nums{1,10,3,10,2};
    int m = 3, k = 1;

    // vector<int> nums{1,13,4,6,4};
    // int m = 3, k = 2;

    // vector<int> nums{7,7,7,7,12,7,7};
    // int m = 2, k = 3;

    // vector<int> nums{1000000000,1000000000};
    // int m = 1, k = 1;

    cout << minDays(nums, m, k);
}