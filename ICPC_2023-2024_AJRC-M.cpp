//2023/12/8 difficulty:1700
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n;
	int sum=0;
	cin >> n;
	vector<int> vect(n*2);
	for(int i=0; i<n; i++){
		cin >> vect[i];
		sum += vect[i];
		vect[i+n] = vect[i];
	}
	for(int i=1; i<2*n; i++)
		vect[i] += vect[i-1];
	
	int tri = sum/3;
	int mx = 0;
	for(int i=0; i<n; i++){
		int p1 = distance(vect.begin(), lower_bound(vect.begin(), vect.end(), tri+vect[i]));
		int p2 = distance(vect.begin(), lower_bound(vect.begin(), vect.end(), tri*2+vect[i]));
		if(p1 != p2)
			return tri;
		else
			mx = max({mx, tri - (tri+vect[i] - vect[p1-1]), tri - (tri*2+vect[i] - vect[p2-1])});
	}
	return mx;
}

signed main(){
	int t=1;
	while(t--)
		cout << solve();
	return 0;
}

