//2023/12/12 difficulty:1700
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
	int plus=0, minus=0;
};

int solve(){
	int n;
	cin >> n;
	int ans=0;
	vector<string> vect(n);
	vector<vector<P>> cnt(n+1, vector<P>(n+1));
	for(int i=0; i<n; i++){
		cin >> vect[i];
		for(int j=0; j<n; j++){
			cnt[i+1][max(0LL, j-1)].plus += cnt[i][j].plus;
			cnt[i+1][j+1].minus += cnt[i][j].minus;
			if(j != 0){
				cnt[i][j].plus += cnt[i][j-1].plus;
				cnt[i][j].minus += cnt[i][j-1].minus;	
			}
			if( ((vect[i][j]=='1') + cnt[i][j].plus - cnt[i][j].minus)%2 == 1){
				ans++;
				cnt[i+1][max(0LL, j-1)].plus++;
				cnt[i+1][min(n, j+2)].minus++;
			}
		}
	}
	return ans;
	
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--){
		cout << solve() << '\n';
	}
	return 0;
}
