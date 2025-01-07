# include<bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int> &piles, int h){
    int max = *max_element(piles.begin(), piles.end());
    int low = 1, speed = INT_MAX;
    if(piles.size() == 1){
        double val = ceil(double(piles[0]) / double(h));
        return val;
    }
    while(low <= max){
        int mid = low + (max - low)/2;
        float ans = 0;
        for(int j = 0; j < piles.size(); j++){
            ans += ceil(double(piles[j]) / double(mid));
        }
        if(ans <= h){
            speed = min(mid, speed);
            max = mid - 1;
        }else if(ans > h) low = mid + 1;
    }

    return speed;
}

int main(){
    vector<int> nums{312884470};
    cout << minEatingSpeed(nums, 312884469) << endl;
}