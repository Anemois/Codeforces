//2023/12/28
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
	vector<int> even(n+1, 0), odd(n+1, 0);
	set<int> ev, od;
	ev.insert(0);
	od.insert(0);
	bool can = false;
	for(int i=1; i<=n; i++){
		if(i&1){
			cin >> odd[i];
		}
		else
			cin >> even[i];
		odd[i] += odd[i-1];
		even[i] += even[i-1];
		if(!can && (od.find(odd[i] - even[i]) != od.end() || ev.find(even[i] - odd[i]) != ev.end()))
			can = true;
		if(!can){
			if(odd[i] > even[i])
				od.insert(odd[i] - even[i]);
			if(odd[i] < even[i])
				ev.insert(even[i] - odd[i]);
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
