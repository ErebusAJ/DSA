#include<bits/stdc++.h>

using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    int i = a[0], index = 0;
    int count = 0;
    while(index < a.size()){
        if(i == a[index]){
            count++;
        }else{
            break;
        }
        index++;
        i++;
    }
    return count;
}

int main(){
    vector<int> nums{147,25,56,168,106,124,137,117,15,45,189,92,74,46,63,20,198,20,78,73,111,90,152,49,6,121,70,158,3,135,148,11,155,166,45,187,83,39,36,14,35,70,142,149,182,96,134,192,105,42,16,118,137,107,50,5,186,101,96,18,166,168,200,28,178,23,53,20,135,23,16,103 
};

    cout << longestSuccessiveElements(nums);
}
