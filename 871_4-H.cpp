//2024/1/3 difficulty:1700 https://codeforces.com/contest/1829/problem/H
#include <bits/stdc++.h>

#define HAS_T true
#define INT

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 1000000007;

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
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> dp(2, vector<int>(64, 0));
	while(n--){
		int x;
		cin >> x;
		for(int i=0; i<64; i++){
			dp[1][i] += dp[0][i];
			dp[1][i&x] += dp[0][i];
		}
		for(int i=0; i<64; i++){
			dp[0][i] = dp[1][i]%MOD;
			dp[1][i] = 0;
		}
		dp[0][x]++;
	}
	int ans=0;
	for(int i=0; i<64; i++){
		if(__builtin_popcount(i) == k)
			ans = (ans+dp[0][i])%MOD;
	}
	return ans;
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