# include<bits/stdc++.h>

using namespace std;

bool solver(string s, int i, vector<string> words){
	if(i >= s.size()) return true;

	for(int j = 0; j < words.size(); j++){
		int len = words[j].size();
		if(s.substr(i, len) == words[j]){
			if(solver(s, i + len, words)) return true;
		}
	}

	return false;
}


bool wordBreak(string s, vector<string> words){
	reverse(words.begin(), words.end());
	return solver(s, 0, words);
}

int main(){
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> words{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

	cout << wordBreak(s, words);

}
