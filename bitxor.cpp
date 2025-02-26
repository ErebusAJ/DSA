# include<bits/stdc++.h>

using namespace std;

int main(){
	int l = 5;
	int h = 11;
	int xr = 0;
	for(int i = l; i <= h; i++){
		xr ^= i;
	}

	return xr;
}
