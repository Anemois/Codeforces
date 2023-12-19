//2023/12/17
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> vect(n);
	for(int i=0; i<n; i++){
		cin >> vect[i].first;
		vect[i].second = i;
	}
	sort(vect.begin(), vect.end());
	int sum=0;
	for(int i=0; i<n; i++){
		sum += vect[i].first - vect[0].first+1;
	}
	vector<int> ans(n);
	ans[vect[0].second] = sum;
	
	int cnt = 1;
	for(int i=1; i<n; i++){
		sum -= (vect[i].first-vect[i-1].first)*(n-2*cnt++);
		ans[vect[i].second] = sum;
	}
	for(auto& i : ans)
		cout << i << " ";
	cout << "\n";
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}