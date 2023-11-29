#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, q;
	cin >> n >> q;
	
	for(int i=1; i<n; i++)
		cout << i << " " << i+1 << "\n";
	
	int last = -1;
	for(int i=0; i<q; i++){
		int x;
		cin >> x;
		if(last == -1){
			if(x == n-1){
				cout << "-1 -1 -1";
			}
			else{
				cout << n << " " << n-1 << " " << x;
				last = x;
			}
		}
		else{
			if(x == last){
				cout << "-1 -1 -1";
			}
			else{
				cout << n << " " << last << " " << x;
				last = x;
			}
		}
		cout << "\n";
	}
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}
