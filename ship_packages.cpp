# include<bits/stdc++.h>

using namespace std;

int daysTook(vector<int>& weights, int capacity){
    int i = 0, days = 0, sum = 0;
    while(i < weights.size()){
        sum += weights[i];
        if(sum > capacity){
            i--;
            days++;
            sum = 0;
        }
        i++;
    }

    return days + 1;
}

int shipWithinDays(vector<int>& weights, int days){
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = INT_MAX;
    while(low <=high){
        int mid = low + (high - low)/2;
        int temp_days = daysTook(weights, mid);
        if(days >= temp_days){
            ans = min(ans, mid);
            high = mid - 1;
        }
        else if(days < temp_days) low = mid + 1; 
    }

    return ans;
}


int main(){
    // vector<int> weights{1, 2, 3, 1, 1};
    // vector<int> weights{3,2,2,4,1,4};
    vector<int> weights{1,2,3,4,5,6,7,8,9,10};
    cout << shipWithinDays(weights, 5) << endl; 
}