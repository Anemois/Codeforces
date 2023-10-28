//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

bool solve(){
	vector<int> vect(26, 0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(auto& c : s){
		vect[c-'a']++;
	}
	int cnt=0;
	for(int i=0; i<26; i++){
		if(vect[i] % 2 == 1)
			cnt++;
	}
	return k >= cnt-1;
}

int main()
{
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		if(solve())
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}
	return 0;
}
