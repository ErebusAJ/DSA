# include<bits/stdc++.h>

using namespace std;

int countBits(int n){
	if((n & (n - 1)) == 0) return 1;
	int ctr = 0;
	while(n != 0){
		if((n & 1) == 1) ctr++;
		n = n >> 1;
	}

	return ctr;
}

int main(){
	int n = 975;
	cout << countBits(n);

	cout << __builtin_popcount(n);	
}
