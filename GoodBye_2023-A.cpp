//2023/12/30 https://codeforces.com/contest/1916/problem/A
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
	int n, k;
	cin >> n >> k;
	int prod=1;
	while(n--){
		int x;
		cin >> x;
		prod *= x;
	}
	if(2023%prod != 0){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
		cout << 2023/prod << " ";
		for(int i=1; i<k; i++)
			cout << "1 ";
		cout << "\n";
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
