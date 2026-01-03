//2024/1/1 difficulty:1600 https://codeforces.com/problemset/problem/1833/E
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
	int n;
	cin >> n;
	vector<int> loop(n+1);
	vector<set<int>> vect(n+1);
	for(int i=1; i<=n; i++){
		cin >> loop[i];
		vect[i].insert(loop[i]);
		vect[loop[i]].insert(i);
	}
	int one=0, full=0;
	for(int i=1; i<=n; i++){
		if(vect[i].size() == 1)
			one++;
	}
	for(int i=1; i<=n; i++){
		if(loop[i] != -1 && i != loop[loop[i]]){
			int p = loop[i];
			loop[i] = -1;
			while(p != i && p!=-1){
				int nxt = loop[p];
				loop[p] = -1;
				p = nxt;
			}
			if(p == i)
				full++;
		}
	}
	cout << full + (one!=0) << " " << full + (one/2) << "\n";
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