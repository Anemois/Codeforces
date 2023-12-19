//2023/12/19 difficulty:1800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;
 
int ans=0;
 
int go(int P, vector<vector<int>>& tree){
	set<int> st;
	st.insert(0);
	int x, sum=0;
	for(auto& i : tree[P]){
		x = go(i, tree);
		sum += x;
		for(auto j = st.rbegin(); j!=st.rend(); j++){
			st.insert(*j + x);
			//cout << i << " " << *j << "\n";
		}
	}
	
	x = sum/2;
	
	auto p = st.lower_bound(x+1);
	p--;
	int mx = (*p) * (sum-*p);
	if(p != st.begin()){
		p--;
		mx = max(mx, (*p) * (sum-*p));
	}
	ans += mx;
	return sum+1;
}
 
int solve(){
	int n;
	cin >> n;
	vector<vector<int>> tree(10000);
	for(int i=2; i<=n; i++){
		int x;
		cin >> x;
		tree[x].push_back(i);
	}
	go(1, tree);
	return ans;
}
 
signed main(){
	Anemoi
	int t=1;
//	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}