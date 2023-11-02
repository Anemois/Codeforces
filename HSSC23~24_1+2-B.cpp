//11/2/2023 difficulty:1100;
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

string solve(){
	int n, k;
	string str;
	cin >> n >> k;
	cin >> str;
	string a, b, ans;
	if(k%2 == 1){
		for(int i=0; i<n; i++){
			if(i%2 == 0){
				a += str[i];
			}
			else{
				b += str[i];
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i=0; i<n; i++){
			if(i%2 == 0){
				ans += a[i/2];
			}
			else{
				ans += b[i/2];
			}
		}
	}
	else{
		ans = str;
		sort(ans.begin(), ans.end());
	}
	return ans;
}

signed main(){
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cout << solve() << "\n";
	return 0;
}
