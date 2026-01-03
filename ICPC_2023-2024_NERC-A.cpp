//2023/12/14 difficulty:1800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 998244353;

int solve(){
	int x, n;
	cin >> x >> n;
	//                min  val
	vector<deque<pair<int, int>>> vect(n);
	priority_queue<pair<int, int>> pq;
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		int mn=0;
		int val=0;
		int high=0;
		int y;
		for(int j=0; j<m; j++){
			cin >> y;
			val += y;
			mn = min(mn, val);
			if(val > high){
				while(!vect[i].empty() && vect[i].back().first == mn){
					high -= vect[i].back().second;
					vect[i].pop_back();
				}	
					
				vect[i].push_back(make_pair(mn, val-high));
				high = val;
			}
		}
		for(auto& j : vect[i])
			pq.push(j);
	}

	while(!pq.empty() && x >= -pq.top().first){
		//cout << pq.top().first << " " << pq.top().second << "\n";
		x += pq.top().second;
		pq.pop();
	}
	return x;
}

signed main(){
	Anemoi
	int t=1;
	while(t--)
		cout << solve();
	return 0;
}

