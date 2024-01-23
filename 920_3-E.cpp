//2024/1/23 difficulty:1600
#include <bits/stdc++.h>

#define HAS_T true
#define STRING

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
	int x1, y1, x2, y2;
	cin >> y1 >> x1 >> y2 >> x2;
	int dist=y2-y1;
	int white = (dist+1)/2, black = dist/2;
	if(dist <= 0)
		return "DRAW";
	else if(dist%2==0){
		if(x1==x2)
			return "BOB";
		else if(x1 < x2){
			if(black >= x2-1)
				return "BOB";
			else
				return "DRAW";
		}
		else{
			if(black >= m-x2)
				return "BOB";
			else
				return "DRAW";
		}
	}
	else{
		if(abs(x1-x2)<=1)
			return "Alice";
		else if(x2 < x1){
			if(white >= x1-1)
				return "Alice";
			else
				return "DRAW";
		}
		else{
			if(white >= m-x1)
				return "Alice";
			else
				return "DRAW";
		}
	}
	return "WHAT";
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