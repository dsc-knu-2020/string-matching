#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx")

#include <bits/stdc++.h>


using namespace std;


bool compare_from_begin(string &str, string &text, int &start){
	for (int i = 0; i < (int)str.size(); ++i){
		if (str[i] != text[i + start]){
			return false;
		}
	}
	return true;
}


void brute_force(string &text, string &str){
	for (int i = 0; i + str.size() - 1 < text.size(); ++i){
		if (compare_from_begin(str, text, i)){
			cout << i << endl;
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
		
	brute_force(text, str);
		
	return 0;
}
