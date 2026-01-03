//10/30/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int x, y, n;
	cin >> x >> y >> n;
	vector<int> vect(n);
	vect[n-1] = y;
	int t = 1;
	for(int i=n-2; i>=0; i--){
		vect[i] = vect[i+1] - t;
		t++;
	}
	if(vect[0] < x){
		cout << "-1\n";
		return;
	}
	
	vect[0] = x;
	for(auto& i : vect)
		cout << i << " ";
	cout << "\n";
}

signed main(){
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		solve();
	return 0;
}
