//2024/1/1 difficulty:1600 https://codeforces.com/problemset/problem/1840/E
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

#if defined(VOID)
void
#elif defined(INT)
int
#elif defined(BOOL)
bool
#elif defined(STRING)
string
#endif
solve(){
	string strs[3];
	cin >> strs[1] >> strs[2];
	strs[1] = "0" + strs[1];
	strs[2] = "0" + strs[2];
	int T, q;
	cin >> T >> q;
	vector<vector<int>> blocks(q+T+5);
	unordered_set<int> bad;
	int LEN = strs[1].length();
	for(int i=1; i<=LEN; i++)
		if(strs[1][i] != strs[2][i])
			bad.insert(i);
	
	for(int t=0; t<q; t++){
		int op;
		cin >> op;
		// cout << strs[1] << " " << strs[2] << "\n";
		// for(auto& i : bad)
		// 	cout << i << " ";
		// cout << "\n";
		for(auto& j : blocks[t])
			bad.insert(j);
		if(op == 3){
			if(bad.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if(op == 2){
			int s1, i, s2, j;
			cin >> s1 >> i >> s2 >> j;
			swap(strs[s1][i], strs[s2][j]);
			if(strs[1][i] == strs[2][i]){
				bad.erase(i);
				//cout << ":)";
			}
			else{
				bad.insert(i);
				//cout << ":DDDD";
			}
			if(strs[1][j] == strs[2][j]){
				bad.erase(j);
				//cout << ":)";
			}
			else{
				bad.insert(j);
				//cout << ":DDDD";
			}
		}
		else{
			int i;
			cin >> i;
			if(strs[1][i] != strs[2][i])
				blocks[t+T].push_back(i);
			bad.erase(i);
		}
	}
}

signed main(){
	Anemoi
	int t=1;
	#if HAS_T == true
	cin >> t;
	#endif
	while(t--){
		#if defined(VOID)
		solve();
		#elif defined(BOOL)
		if(solve())
			cout << "YES\n";
		else
			cout << "NO\n";
		#else
		cout << solve() << "\n";
		#endif
	}
		
	return 0;
}
/*
int overflow
array bounds special cases (n=1?) 
do smth instead of nothing and stay organized
WRITE STUFF DOWN DON'T GET STUCK ON ONE APPROACH
you should actually read the stuff at the bottom
*/