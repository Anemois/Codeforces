//2023/12/20 difficulty:1500
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> vect(n+1), spec(n+1, 0);
	for(int i=1; i<=n; i++){
		cin >> vect[i];
		if(i >= 3 && vect[i-2] >= vect[i-1] && vect[i-1] >= vect[i]){
			spec[i]++;
		}
		spec[i] += spec[i-1];
	}
	int l, r;
	while(q--){
		cin >> l >> r;
		cout << r-l+1 - (r>l+1 ? spec[r] - spec[l+1] : 0) << "\n";
	}
}

signed main(){
	Anemoi
	int t=1;
	while(t--)
		solve();
}
