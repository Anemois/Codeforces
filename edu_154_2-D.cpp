//2023/12/16 difficulty:1800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

#define val first
#define ptr second

int solve(){
	int n;
	cin >> n;
	vector<int> vect(n);
	vector<int> dec(n), inc(n);
	dec[0] = 0;inc[n-1] = 0;
	cin >> vect[0];
	for(int i=1; i<n; i++){
		cin >> vect[i];
		dec[i] = dec[i-1];
		if(vect[i] >= vect[i-1])
			dec[i]++;
	}
	for(int i=n-2; i>=0; i--){
		inc[i] = inc[i+1];
		if(vect[i] >= vect[i+1])
			inc[i]++;
	}
	int mn = min(inc[0], dec[n-1]+1);
	for(int i=0; i<n-1; i++){
		mn = min(mn, dec[i] + inc[i+1] + 1);
	}
	return mn;
}

signed main()
{
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}
