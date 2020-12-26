#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx")

#include <bits/stdc++.h>


using namespace std;

void rc(string &text, string &str){
	int str_size = str.size(), text_size = text.size();
	
	// prime module
	const long long mod = 1e9 + 7;
	
	// calculate all powers of p
	const int p = 31;
	vector<long long> p_pow(max(str_size, text_size));
	p_pow[0] = 1;
	for (int i = 1; i < (int)p_pow.size(); ++i)
		p_pow[i] = (p_pow[i-1] * p) % mod;

	// calculate hashes from all prefixes of TEXT
	// p_pow[] = [1, p, p^2, p^3, ...] % mod
	vector<long long> pref(text_size);
	for (int i = 0; i < text_size; ++i){
		pref[i] = (text[i] - 'a' + 1) * p_pow[i];
		if (i) pref[i] += pref[i-1];
		pref[i] %= mod;
	}
	// pref[i] = hash(text[0]+...+text[i])

	// calculate hash of STR
	long long str_hash = 0;
	for (int i = 0; i < str_size; ++i){
		str_hash += (str[i] - 'a' + 1) * p_pow[i];
		str_hash %= mod;
	}
	
	// iterate over all substrings TEXT of length |STR| and compare them
	for (int i = 0; i + str_size - 1 < text_size; ++i){
		// compare str and text[i, i + |str| - 1]
		long long cur_hash = pref[i + str_size - 1];
		if (i) cur_hash = (cur_hash - pref[i - 1]) % mod;
		if (cur_hash < 0) cur_hash += mod;
		
		// reduce hashes to one degree and compare
		if (cur_hash == (str_hash * p_pow[i]) % mod)
			cout << i << '\n';
	}	
}




int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string text, str;
	cin >> text;
	cin >> str;
	
	cerr << "size of text = " << text.size() << endl;
	cerr << "size of str  = " << str.size() << endl;
		
	rc(text, str);
		
	return 0;
}
