//11/9/2023 difficulty:1400
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int orig;
	cin >> orig;
	int x = orig;
	string str;
	vector<int> ans;
	while(x > 0){
		if(x&1)
			str+='1';
		else
			str+='0';
		x = x>>1;
	}
	reverse(str.begin(), str.end());
	int n = str.length();
	x = orig;
	int two = 1;
	ans.push_back(x);
	for(int i = n-1; i>=1; i--){
		if(str[i] == '1'){
			x -= two;
			ans.push_back(x);
		}
		two = two << 1;
	}
	two = two >> 1;
	for(int i=1; i<n; i++){
		x -= two;
		ans.push_back(x);
		two = two >> 1;
	}
	cout << ans.size() << "\n";
	for(auto& i : ans)
		cout << i << " ";
	cout << "\n";
}

signed main(){
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		solve();
	return 0;
}
