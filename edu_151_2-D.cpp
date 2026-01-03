//2023/12/30 difficulty:1800 https://codeforces.com/problemset/problem/1845/D
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
	int n;
	cin >> n;
	vector<int> vect(n+1);
	vect[0] = 0;
	for(int i=1; i<=n; i++){
		cin >> vect[i];
		vect[i] += vect[i-1];
	}
	int mx=0, mn=INT64_MAX;
	int ans=0;
	for(int i=n; i>=0; i--){
		mn = min(mn, vect[i]);
		if(vect[i] - mn > mx){
			ans = vect[i];
			mx = vect[i]-mn;
		}
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
