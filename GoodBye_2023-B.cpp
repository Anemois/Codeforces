//2023/12/30 https://codeforces.com/contest/1916/problem/B
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
	int a, b;
	cin >> a >> b;
	if(a == 1)
		return b*b;
	else if(a == 2)
		return b*2;
	int lcm = (a*b)/(__gcd(a, b));
	if(lcm != b){
		return lcm;
	}
	else
		return b*(b/a);
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
