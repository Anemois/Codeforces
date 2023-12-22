//2023/12/21
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MAX = 2e5+10;

vector<int> sz(MAX);

int getsiz(vector<vector<int>>& graph, int p){
	int sum=1;
	for(auto i : graph[p])
		sum += getsiz(graph, i);
	
	return sz[p] = sum;
}

int go(vector<vector<int>>& graph, int p, int k){
	int tot= 0;
	//cout << k << " ";
	int mx = -1;
	for(auto i : graph[p]){
		tot += sz[i];
		if(mx == -1 || sz[i] > sz[mx])
			mx = i;
	}
	if(tot == 0)
		return 0;
	if(sz[mx]-k <= tot-sz[mx]){
		return (tot-k)/2;
	}
	int ad = tot - sz[mx];
	return ad + go(graph, mx, max(0LL, k + ad - 1));
}

int solve(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n+1);
	for(int i=2; i<=n; i++){
		int x;
		cin >> x;
		graph[x].push_back(i);
	}
	getsiz(graph, 1);
	//for(int i=1; i<=n; i++)
    	//cout << sz[i] << " ";
	return go(graph, 1, 0);
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}
