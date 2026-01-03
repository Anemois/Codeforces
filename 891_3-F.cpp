//2023/12/17
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MAX = 2e9;

void solve(){
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	int q;
	cin >> q;
	while(q--){
		int b, c;
		cin >> b >> c;
		double x1 = (b + sqrt(b*b - 4*c))/2, x2	= (b - sqrt(b*b - 4*c))/2;
		if(x1 != floor(x1) || x2 != floor(x2))
			cout << "0 ";
		else if(x1 == x2)
			cout << (mp.find(x1)==mp.end()?0:mp[x1]*(mp[x1]-1)/2)  << " ";
		else
			cout << (mp.find(x1)==mp.end()?0:mp[x1]) * (mp.find(x2)==mp.end()?0:mp[x2]) << " ";
	}
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
