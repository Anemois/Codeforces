//2024/1/4 difficulty:1700 https://codeforces.com/problemset/problem/1835/A
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
	int A, B, C, k;
	cin >> A >> B >> C >> k;
	A--;B--;C--;
	bool no = true;
	int a=pow(10, A), b=pow(10, B), c1=pow(10, C), c2 = pow(10, C+1);
	for(int i=a; i<a*10; i++){
		int l = max(b, c1 - i);
		int r = min(b*10, c2 - i)-1;
		if(l > r)
			continue;
		int x = r-l+1;
		if(k<=x){
			cout << i << " + " << l+k-1 << " = " << i+l+k-1 << "\n";
			no = false;
			break;
		}
		k -= x;
	}
	if(no)
		cout << "-1\n";
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