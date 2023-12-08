//2023/12/8 difficulty:1700
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 998244353;

int solve(){
	int n;
	cin >> n;
	vector<int> vect(n+1);
	for(int i=1; i<=n; i++)
		cin >> vect[i];
	int ans=0;
	for(int i=0; i<32; i++){
		bool two = true;
		int sum = 0;
		int cnt[2][2] = {{0, 1}, {0, 0}};
		for(int j=1; j<=n; j++){
			if((vect[j]>>i)&1){
				two = !two;
			}
			if(two){
				sum = (sum + cnt[1][1]*j - cnt[1][0])%MOD;
				cnt[0][1]++;
				cnt[0][0]+=j;
			}
			else{
				sum = (sum + cnt[0][1]*j - cnt[0][0])%MOD;
				cnt[1][1]++;
				cnt[1][0]+=j;
			}
		}
		//cout << sum << "\n";
	  	ans = (ans + (sum%MOD)*(1LL<<i))%MOD;
	}	
	return ans;
}

signed main(){
	int t = 1;
	while(t--)
		cout << solve();
	return 0;
}

