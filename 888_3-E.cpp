//2024/1/1 difficulty:1500 https://codeforces.com/problemset/problem/1851/E
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
	int n, k;
	cin >> n >> k;
	vector<int> ans(n);
	for(int i=0; i<n; i++)
		cin >> ans[i];
	for(int i=0; i<k; i++){
		int x;
		cin >> x;
		ans[--x] = 0;
	}
	vector<int> degree(n, 0);
	vector<vector<int>> graph(n);
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		degree[i] = m;
		for(int j=0; j<m; j++){
			int p;
			cin >> p;
			graph[--p].push_back(i);
		}
	}
	vector<int> other(n, 0);
	queue<int> pend;
	for(int i=0; i<n; i++){
		if(degree[i] == 0){
			pend.push(i);
			other[i] = INT64_MAX;
		}
	}
	while(!pend.empty()){
		int now = pend.front();pend.pop();
		ans[now] = min(ans[now], other[now]);
		for(auto& i : graph[now]){
			other[i] += ans[now];
			if(--degree[i] == 0)
				pend.push(i);
		}
	}
	for(int i=0; i<n; i++)
		cout << ans[i] << " ";
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
