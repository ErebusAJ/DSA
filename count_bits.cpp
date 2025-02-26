# include<bits/stdc++.h>

using namespace std;

int countBits(int n){
	int ctr = 0;
	int x = n;
	for(int i = 0; x != 0; i++, x = x >> 1){
		int pTwo = 1 << i;
		int groups = (n+1)/pTwo;
		ctr += (groups/2)*pTwo;
		ctr += ((n >> i) & 1) * (groups % pTwo);
	}

	return ctr;
}

int main(){
	int a;
	cin >> a;

	cout << countBits(a);

}
