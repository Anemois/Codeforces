//2024/1/22
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<int> ans;

void go(int n, int mn){
	
	if(n == 2){
		ans.push_back(mn);
		return;
	}
	else if(n<=1){
		return;
	}
	ans.push_back(mn);
	go(n/2, mn+1);

	if(n&1)
		ans.push_back(mn);
}

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
	ans.clear();
	int n;
	cin >> n;
	go(n, 0);
	cout << ans.size() << "\n";
	for(auto& i : ans)
		cout << i << " ";
	cout << "\n";
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