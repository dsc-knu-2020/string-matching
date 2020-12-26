#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx")

#include <bits/stdc++.h>


using namespace std;

vector<int> prefix_function(string &s) {
	int n = (int)s.length();
	vector<int> pf(n);
	
	for (int i = 1; i < n; ++i) {
		int j = pf[i - 1];
		while (j > 0 && s[i] != s[j]){
			j = pf[j - 1];
		}
		if (s[i] == s[j]) ++j;
		pf[i] = j;
	}
	
	return pf;
}

void kmp(string &text, string &str){
	string s = str + "#" + text;
	vector<int> pf = prefix_function(s);
	
	int str_size = str.size(), s_size = s.size();
	
	for (int i = str_size; i < s_size; ++i){
		if (pf[i] == str_size){
			// i - (str_size + 1) - str_size + 1
			cout << i - 2 * str_size << '\n';
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string text, str;
	cin >> text;
	cin >> str;
	
	cerr << "size of text = " << text.size() << endl;
	cerr << "size of str  = " << str.size() << endl;
		
	kmp(text, str);
	
	return 0;
}
