# include<bits/stdc++.h>

using namespace std;

bool solver(int n){
	if(n == 1) return true;

	if(n & 1 == 0) return true;
	return false;
}

int binaryToInt(string s){
	int p2 = 1;
	int result = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		if(s[i] == '1') result += p2;
		p2 *= 2;
	}

	return result;
}

bool checkKBit(int n, int k){
	if(k == 0){
		if(n & 1 == 1) return true;
		return false;
	}

	int temp = n;
	for(int i = 0; i < k; i++){
		temp = temp >> 1;
	}
	if(temp & 1 == 1) return true;
	return false;
}


int main(){
	int n = 16;
	cout << solver(n) << endl;
	string s = "1011";
	cout << binaryToInt(s) << endl;

	cout << "K bit: " << checkKBit(975, 10) << endl;

	cout << "Swap two number: " << endl;	
	int a = 10;
	int b = 22;
	cout << "num1: " << a << "num2: " << b << endl;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << "num1: " << a << "num2: " << b << endl;

}
