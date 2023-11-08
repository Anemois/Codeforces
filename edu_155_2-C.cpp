//2023/11/7 difficulty:1300
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;
const int MOD = 998244353;

int C(int x){
	int ret=1;
	for(int i=x; i>=2; i--){
		ret = (ret * i)%MOD;
	}
	return ret%MOD;
}

void solve(){
	int cnt=1;
	vector<int> vect;
	string str;
	cin >> str;
	int n = str.length();

	for(int i=1; i<n; i++){
		if(str[i] != str[i-1]){
			vect.push_back(cnt);
			cnt = 1;
		}
		else
			cnt++;
	}
	vect.push_back(cnt);
	int ans=1, anscnt=0;
	
	for(auto& i : vect){
		ans = (ans * (i))%MOD;
		anscnt += i-1; 
	}	
	cout << anscnt << " " << (ans*C(anscnt))%MOD << "\n";
}

signed main()
{
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		solve();
	return 0;
}