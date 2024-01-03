//2024/1/2 difficulty:1700 https://codeforces.com/problemset/problem/1826/D
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
	vector<int> vect(n);
	for(int i=0; i<n; i++)
		cin >> vect[i];
	vector<int> l(n), r(n);
	int t1 = INT64_MIN, t2 = INT64_MIN;
	for(int i=0; i<n; i++){
		l[i] = t1;
		t1 = max(t1, vect[i] + i);
		
		r[n-i-1] = t2;
		t2 = max(t2, vect[n-i-1] - (n-i-1));
	}
//	for(auto& i : l)
//		cout << i << " ";
//	cout << "\n";
//	for(auto& i : r)
//		cout << i << " ";
//	cout << "\n";
	int mx=0;
	for(int i=1; i<n-1; i++){
		mx = max(mx, l[i] + r[i] + vect[i]);
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