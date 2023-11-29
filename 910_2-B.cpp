//2023/11/29 difficulty:1500
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n;
	cin >> n;
	vector<int> vect(n);
	for(auto& i : vect) cin >> i;
	
	int ans=0;
	int mn = vect[n-1];
	
	for(int i=n-2; i>=0; i--){
		if(vect[i] < mn){
			mn = vect[i];
		}
		else if(vect[i] % mn == 0){
			ans += vect[i] / mn - 1;
		}
		else{
			ans += vect[i] / mn;
			mn = vect[i] / (vect[i]/mn+1); 
		}
		//cout << mn << " ";
	}
	//cout << "\n";
	return ans;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		cout << solve() << "\n";
	}
	return 0;
}

