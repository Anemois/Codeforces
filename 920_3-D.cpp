//2024/1/23 difficulty:1100
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
	int n, m;
	cin >> n >> m;
	vector<int> vect(n+1);
	vect[0]=0;
	for(int i=1; i<=n; i++)
		cin >> vect[i];
	vector<int> dq(m+1);
	dq[0]=0;
	for(int i=1; i<=m; i++)
		cin >> dq[i];
	sort(dq.begin()+1, dq.end());
	sort(vect.begin()+1, vect.end());
	for(int i=1; i<=n; i++)
		vect[i] += vect[i-1];
	for(int i=1; i<=m; i++)
		dq[i] += dq[i-1];
	int mx=0;
	for(int i=0; i<=n; i++){
		mx = max(mx, ( (vect[n]-vect[n-i]) - (dq[i]) ) + ( (dq[m]-dq[m-n+i]) - (vect[n-i]) ) );
	}
	return mx;
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