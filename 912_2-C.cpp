//2023/12/6 difficulty:1400
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n;
	cin >> n;
	vector<int> vect(n);
	for(int i=0; i<n; i++) 
		cin >> vect[i];
		
	int sum=0, ans=0;
	for(int i=n-1; i>=0; i--){
		ans = ans - min(0LL, sum) + vect[i]*(i+1);
		sum += vect[i];
		//cout << ans << " ";
	}
	return ans;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}

