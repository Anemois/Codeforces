//2024/1/23 difficulty:800
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
	vector<int> x(4), y(4);
	for(int i=0; i<4; i++)
		cin >> x[i] >> y[i];
	for(int i=1; i<4; i++){
		if(x[i] == x[0])
			return (y[i] - y[0]) * (y[i] - y[0]);
	}
	return -1;
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