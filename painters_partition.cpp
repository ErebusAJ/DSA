# include<bits/stdc++.h>

using namespace std;

int canPaint(vector<int>& boards, int threshold){
    int painterCtr = 1, sum = 0;
    for(int i = 0; i < boards.size(); i++){
        if((sum + boards[i]) <= threshold) sum += boards[i];
        else{
            painterCtr++;
            sum = boards[i];
        }
    }

    return painterCtr;
}

int findLargestMinDistance(vector<int>& boards, int k){
    int low = *max_element(boards.begin(), boards.end());

    if(boards.size() == k) return low;

    int high = accumulate(boards.begin(), boards.end(), 0);

    while(low <= high){
        int mid = low + (high - low)/2;
        int check = canPaint(boards, mid);
        if(check == k) high = mid - 1;
        else if(check > k) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int main(){
    // vector<int> nums{10, 20, 30, 40};
    // int k = 2;

    vector<int> nums{48, 90};
    int k = 2;

    cout << findLargestMinDistance(nums, k) << endl;

}