//2023/12/6 difficulty:1400
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;
int n;
vector<int> vect(200010);
vector<vector<int> > bit(200010, vector<int>(32, 0));	

bool check(int& l, int& r, int& k){
	int sum=0;
	for(int i=0; i<32; i++){
		if(bit[r][i] - bit[l-1][i] == r-l+1)
			sum += 1LL<<i;
	}
	//cout << r << " " << sum << " " << k << "\n";
	return sum>=k;
}

void solve(){
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> vect[i];
		for(int j=0; j<32; j++){
			if((vect[i] >> j) & 1)
				bit[i][j]=1;
			else
				bit[i][j]=0;
			bit[i][j] += bit[i-1][j];
			//cout << bit[i][j] << " ";
		}
		//cout << "\n";
	}
	
	int t;
	cin >> t;
	while(t--){
		int L, x;
		cin >> L >> x;
		if(vect[L] < x){
			cout << "-1 "; continue;
		}
		int l = L, r = n;
		while(l<r){
			int m = (l+r+1)/2;
			if(check(L, m, x))
				l = m;
			else
				r = m-1;
			
		}
		cout << l << " ";
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

