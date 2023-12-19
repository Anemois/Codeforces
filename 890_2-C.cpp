//2023/12/18 difficulty:1800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int n, k;
vector<int> vect(1001);

bool check(int x){
	for(int i=0; i<n; i++){
		int sum=0, now=x;
		for(int j=i; j<=n; j++){
			if(j == n)
				sum = 1000000000000000LL;
			else if(vect[j] >= now)
				break;
			else{
				sum += now-vect[j];
			}
			now--;
		}
		if(sum <= k)
			return true;
	}
	return false;
}

int solve(){
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> vect[i];
	int l = 0, r = 1000000000;
	while(l<r){
		int m = (l+r+1)/2;
		if(check(m))
			l = m;
		else
			r = m-1;
	}
	return l;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";	
	return 0;
}
