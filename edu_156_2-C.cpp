//11/15/2023 difficulty:1600
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int go(int&n, int x){
	int sum = 0;
	int i;
	for(i=n; i>=1; i--){
		//cout << sum << " " << i << "\n";
		sum += i;
		if(sum >= x)
			break;
	}
	return n-i+1;
}

char solve(){
	string str;
	cin >> str;
	int n = str.length(), x;
	cin >> x;
	vector<int> vect(n);
	vector<vector<int>> where(26);
	for(int i=0; i<n; i++){
		where[str[i]-'a'].push_back(i);
	}
	int yo = 1;
	for(int i=25; i>=0; i--){
		for(auto& j : where[i]){
			vect[j] = yo;
			yo++;
		}
	}
	int k = go(n, x);
	//cout << k << " ";
	x -= n*(n+1)/2 - (n-k+1)*(n-k+2)/2;
	//cout << x << "\n"; 
	int cnt = 0;
	int i;
	for(i=0; i<n; i++){
		//cout << vect[i] << " ";
		if(vect[i] >= k)
			cnt++;
		if(cnt == x)
			break;
	}
	//for(auto& i : vect)
	//	cout << i << " ";
	return str[i];
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
		cout << solve();

	return 0;
}
