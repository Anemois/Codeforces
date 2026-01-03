//2023/12/28 difficulty:2100
#include <bits/stdc++.h>

#define HAS_T true
#define INT

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 998244353;

int mod(int x){
	return ((x%MOD)+MOD)%MOD;
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
	int n;
	cin >> n;
	vector<int> vect(n+1), last(n+1, 0), prefix(n+1, 0), chain(n+1, 0);
	stack<pair<int, int>> stk;
	stk.push(make_pair(INT_MIN, 0));
	for(int i=1; i<=n; i++){
		cin >> vect[i];
		while(!stk.empty() && stk.top().first >= vect[i])
			stk.pop();
		last[i] = stk.top().second;	
		chain[i] = mod(prefix[last[i]] - (last[i]==0?0:prefix[last[i]-1]) + chain[last[i]]);
		prefix[i] = mod(prefix[i-1] - (last[i]==0?0:prefix[last[i]-1]) + chain[last[i]] + prefix[i-1]);
		if(last[i]==0)
			prefix[i]++;
		stk.push(make_pair(vect[i], i));
	}
	int mn = vect[n];
	int ans=0;
	for(int i=n; i>=1; i--){
		mn = min(mn, vect[i]);
		if(vect[i] <= mn){
			ans = mod(ans + prefix[i] - prefix[i-1]);
		}
	}
	// for(auto& i : prefix)
	// 	cout << i << " ";
	// cout << "\n";
	return ans;
}

signed main(){
	Anemoi
	int t;
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
