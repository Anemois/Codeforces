//2023/12/6 difficulty:1300
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<int> vect(100010);
vector<vector<int> > bit(100010, vector<int>(32));
int n;

bool check(int& l, int& r, int& k){
	int sum=0;
	for(int i=0; i<32; i++){
		if(bit[r][i] - bit[l][i] == r-l)
			sum += 1LL<<i;
	}
	return sum>=k;
}

void solve(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> vect[i];
		for(int j=0; j<32; j++){
			if((vect[i] >> j) & 1)
				bit[i][j]=1;
			else
				bit[i][j]=0;
			if(i!=0)
				bit[i][j] += bit[i-1][j];
		}
	}
	
	int t;
	cin >> t;
	while(t--){
		int l, x;
		cin >> l >> x;
		int r = n;
		while(l<r){
			int m = (l+r)/2;
			if(check(l, m, x))
				r = m;
			else
				l = m+1;
		}
		if(l == n)
			cout << "-1 ";
		else
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

