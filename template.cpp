//2023/12/25 difficulty:1600
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define HAS_T true
#define MAIN void
using namespace std;

MAIN solve(){
	
}

signed main(){
	Anemoi
	int t;
	#if HAS_T == true
	cin >> t;
	#endif
	while(t--){
		#if MAIN == void
		solve();
		#elif MAIN == bool
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
