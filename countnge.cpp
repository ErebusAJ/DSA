# include<bits/stdc++.h>

using namespace std;

vector<int> count_NGE(int n, vector<int> &nums, int queries, vector<int> &indices){
    //write your code here
   int i = n - 1;
   int j = queries - 1;
   stack<int> minst;
   stack<int> maxst;
   
   vector<int> result;
   int c1 = 0, c2 = 0;
   while(i >= 0){
        while(!maxst.empty() && nums[i] > maxst.top()){
            minst.push(maxst.top());
            maxst.pop();
            c2++;
            c1--;
        }
        vector<int> temp;
        while(!minst.empty() && nums[i] > minst.top()){
            temp.push_back(minst.top());
            minst.pop();
            c2--;
        }
        if(!minst.empty() && minst.top() > nums[i]){
            result.push_back(c1 + c2);
        }else{
            if(!maxst.empty()) result.push_back(c1);
            else result.push_back(0);
        }
        for(int i = 0; i < temp.size(); i++){
            minst.push(temp[i]);
            c2++;
        }
        maxst.push(nums[i]);
        c1++;
        i--;
   }
   
   reverse(result.begin(), result.end());

   vector<int> final;
   for(int i = 0; i < queries; i++){
       int ind = indices[i];
       int val = result[ind];
       final.push_back(val);
   }
   
   return final;
}

int main(){
    vector<int> arr{3,4,2,7,5,8,10,6};
    vector<int> indices{0,3,5};
    
    for(auto i : count_NGE(arr.size(), arr, indices.size(), indices)) cout << i << " "; 
}