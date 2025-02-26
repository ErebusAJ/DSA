# include<bits/stdc++.h>

using namespace std;

string solver(string s){
	string temp;
	for(int i = s.size() - 1; i >= 0; i--){
		char c = s[i];
		if(s[i] == '(') temp += ')';
		else if(s[i] == ')') temp += '(';
		else temp += s[i];
	}

	map<char, int> p = {
		{'^', 3},
		{'*', 2},
		{'/', 2},
		{'+', 1},
		{'-', 1},
		{'(', 0}
	};

	s = temp;
	stack<char> st;
	string result;
	int i = 0;
	while(i < s.size()){
		if( (s[i] >= 'A' && s[i] <= 'Z') ||
		    (s[i] >= 'a' && s[i] <= 'z') ||
		    (s[i] >= '0' && s[i] <= '9')) result += s[i];
		else if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				result += st.top();
				st.pop();
			}
			st.pop();
		}else{
			while(!st.empty() && p[s[i]] <= p[st.top()]){
				result += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		i++;
	}

	while(!st.empty()){
		result += st.top();
		st.pop();
	}

	reverse(result.begin(), result.end());

	return result;
}

int main(){
	int t;
	cin >> t;
	vector<string> expr;
	for(int i = 0; i < t; i++){
		string s;
		cin >> s;
		expr.push_back(s);
	}

	vector<string> result;
	for(int i = 0; i < t; i++){
		result.push_back(solver(expr[i]));
	}

	for(auto i : result) cout << i << " " << endl;

	
	// A+B*C
	// (A+B)*(C-D)
	// A*(B+C)-D
	// A+(B-C*D)/E
	// ((A+B)*C)-D
	// A/(B+C)*(D-E)
	// A+B*C-D/E
	// A+B/C-D*E
	// (A+B)*(C+D)-E/F
	// A*B+C*D


}
