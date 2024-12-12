# include<iostream>
# include<vector>
# include<algorithm>

using namespace std;


int mySqrt(int x) {
    int end = x;
    int start = 1;
    int result;
    int mid = start+ (end-start)/2;
    while(start <= end){
        result = mid * mid;
        if(result == x){
            return mid;
        }
        else if(result > x){
            end = mid - 1;
        }
        else if(result < x){
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int x = 9;
    cout << mySqrt(x) << endl;
}