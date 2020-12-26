#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx")

#include <bits/stdc++.h>


using namespace std;

bool compare_from_end(string &str, string &text, int &start){
	for (int i = (int)str.size() - 1; i >= 0; --i){
		if (str[i] != text[i + start]){
			return false;
		}
	}
	return true;
}

void bmh(string &text, string &str){
	int str_size = str.size(), text_size = text.size();
	vector<int> shift(256, str_size);
	for (int i = 0; i + 1 < str_size; ++i){
		shift[str[i]] = str_size - i - 1;
	}
	
	int i = 0;
	while (i + str_size - 1 < text_size){
		if (compare_from_end(str, text, i)){
			cout << i << '\n';
		}
		// shift on shift[last element] from compared part in TEXT
		char last_ch = text[i + str_size - 1];
		i += shift[last_ch];
	}
}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string text, str;
	cin >> text;
	cin >> str;
	
	cerr << "size of text = " << text.size() << endl;
	cerr << "size of str  = " << str.size() << endl;
		
	bmh(text, str);
		
	return 0;
}
