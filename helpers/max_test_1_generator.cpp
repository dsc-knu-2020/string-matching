#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	const int blocks = 10000;
	const int rand_block = rand() % blocks;
	
	string as;
	as.clear();
	for (int i = 0; i + 1 < blocks; ++i){
		as += 'a';
	}
	
	
	for (int i = 0; i < blocks; ++i){
		cout << as;
		if (i == rand_block){
			cout << "a";
		}
		else{
			cout << "b";
		}
	}
	cout << endl;
	cout << as << "b" << endl;
	
	
	return 0;
}
