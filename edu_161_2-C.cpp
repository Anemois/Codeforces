//2024/1/22
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
	int n;
	cin >> n;
	vector<int> vect(n), lr(n), rl(n);
	for(int i=0; i<n; i++){
		cin >> vect[i];
	}
	
	lr[0] = 0;
	lr[1] = 1;
	for(int i=1; i<n-1; i++){
		if(vect[i+1] - vect[i] < vect[i] - vect[i-1])
			lr[i+1] = lr[i]+1;
		else
			lr[i+1] = lr[i]+abs(vect[i] - vect[i+1]);
	}
	rl[n-1] = 0;
	rl[n-2] = 1;
	for(int i=n-2; i>=1; i--){
		if(vect[i+1] - vect[i] > vect[i] - vect[i-1])
			rl[i-1] = rl[i]+1;
		else
			rl[i-1] = rl[i]+abs(vect[i] - vect[i-1]);
	}

	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if(a<b)
			cout << lr[b] - lr[a];
		else
			cout << rl[b] - rl[a];
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
/*
int overflow
array bounds special cases (n=1?) 
do smth instead of nothing and stay organized
WRITE STUFF DOWN DON'T GET STUCK ON ONE APPROACH
you should actually read the stuff at the bottom
*/