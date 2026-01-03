//2023/12/27
#include <bits/stdc++.h>

#define HAS_T false
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
	vector<int> cnt(31, 0);
	while(n--){
		int op, x;
		cin >> op >> x;
		if(op==1){
			cnt[x]++;
			continue;
		}
		
		int has=0;
		for(int i=30; i>=0; i--){
			if((x>>i)&1)
				has++;
			if(has = max(0LL, has - cnt[i]));
			has*=2;
		}
		if(has == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
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
