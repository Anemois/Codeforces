//12/12/2023 difficulty:1600
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n, m, d;
	cin >> n >> m >> d;
	int sum=0;
	int ans=0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		if(x <= 0) continue;
		sum += x;
		pq.push(x);
		if(pq.size() == m+1){
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, sum-i*d);
	}
	return ans;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
}