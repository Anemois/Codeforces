//2023/12/7
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	vector<int> l(k), r(k), cnt(n, 0);
	for(auto& i : l){
		cin >> i;
		i--;
	} 
	for(auto& i : r){
		cin >> i;
		i--;
	} 
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int x;
		cin >> x;
		int p = distance(l.begin(), (lower_bound(l.begin(), l.end(), x))) - 1;
		x--;
		cnt[min(x, r[p]+l[p]-x)]++;
	}
	for(int i=0; i<k; i++){
		int c = 0;
		for(int j=l[i]; j<=(r[i]+l[i])/2; j++){
			c+=cnt[j];
			if(c&1)
				swap(str[j], str[r[i]+l[i]-j]);
		}
	}
	cout << str << "\n";
}

signed main(){	
	Anemoi
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
