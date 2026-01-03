//2023/12/4
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MX = 1E6+10;

int solve(){
	#define TRIE trie[p][c-'a']
	int n;
	cin >> n;
	vector<vector<int>> trie(MX, vector<int>(26, 0));
	vector<int> cnt(MX);
	vector<string> vect(n);
	int ans=0;
	int now=1;
	for(int i=0; i<n; i++){
		cin >> vect[i];
		int p = 1;
		ans += vect[i].size();
		for(auto& c : vect[i]){
			if(TRIE == 0)
				TRIE = ++now;
				
			p = TRIE;
			cnt[p]++;
		}
	}
	ans = ans*n*2;
	for(int i=0; i<n; i++){
		reverse(vect[i].begin(), vect[i].end());
		int p = 1;
		for(auto& c : vect[i]){
			if(TRIE == 0)
				break;
				
			p = TRIE;
			ans -= 2*cnt[p];
		}
	}
	return ans;
}

signed main(){
	Anemoi
	int t=1;
	for(int i=0; i<t; i++)
		cout << solve();
}
