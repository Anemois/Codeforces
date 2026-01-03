//2024/1/22
#include <bits/stdc++.h>

#define HAS_T true
#define BOOL

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
	string a, b, c;
	cin >> a >> b >> c;
	bool can = false;
	for(int i=0; i<n; i++){
		if((a[i] == b[i] && c[i] != a[i]) || (a[i] != b[i] && (c[i] != a[i] && c[i] != b[i]))){
			can = true;
		}
	}
	return can;
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