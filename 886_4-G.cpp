//2023/12/30 difficulty:1500 https://codeforces.com/problemset/problem/1850/G
#include <bits/stdc++.h>

#define HAS_T true
#define INT

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
	map<int, int> X, Y, xpy, xmy;
	int ans=0;
	int n;
	cin >> n;
	for(int t=0; t<n; t++){
		int x, y;
		cin >> x >> y;
		ans += (X[x]++) + (Y[y]++) + (xpy[x+y]++) + (xmy[x-y]++);
	}
	return ans*2;
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
