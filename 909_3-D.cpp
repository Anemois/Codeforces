//2023/12/6 difficulty:1300
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n;
	cin >> n;
	int x;
	int cnt=0;
	map<int, int> mp;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x == 1 || x == 2){
			cnt += (mp.find(1)==mp.end() ? 0 : mp[1]) + (mp.find(2)==mp.end() ? 0 : mp[2]);
		}
		else{
			cnt += (mp.find(x)==mp.end() ? 0 : mp[x]);
		}
		mp[x]++;
	}
	return cnt;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}

