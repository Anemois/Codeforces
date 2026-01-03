//2023/12/30 difficulty:1800 https://codeforces.com/contest/1898/problem/D
#include <bits/stdc++.h>

#define HAS_T true
#define INT

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
	int a, b;
};

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
	vector<P> vect(n);
	int base=0;

	for(int i=0; i<n; i++){
		cin >> vect[i].a;
	}
	for(int i=0; i<n; i++){
		cin >> vect[i].b;
		if(vect[i].a > vect[i].b)
			swap(vect[i].a, vect[i].b);
		base += vect[i].b - vect[i].a;
	}
	int mx = vect[0].a, mn = vect[0].b;
	for(int i=0; i<n; i++){
		mx = max(vect[i].a, mx);
		mn = min(vect[i].b, mn);
	}
	return base + max(0LL, (mx-mn)*2);
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
