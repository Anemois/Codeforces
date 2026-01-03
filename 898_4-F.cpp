//11/8/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n, k;
	cin >> n >> k;
	int l=0, r=0;
	vector<int> cnt(n), height(n);
	for(int i=0; i<n; i++)
		cin >> cnt[i];
	for(int i=0; i<n; i++)
		cin >> height[i];
	int sum = 0;
	int mx = 0;
	while(r<n){
		if(sum == 0 || height[r-1]%height[r] == 0){
			sum += cnt[r];
			r++;
		}
		else{
			sum = 0;
			l = r;
		}
		while(sum > k){
			sum -= cnt[l];
			l++;
		}
		mx = max(mx, r-l);
	}
	return mx;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
		cout << solve() << "\n";
	return 0;
}
